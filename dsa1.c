C Code for Calendar Activity
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the Day structure
struct Day {
 char *dayName;
 int date;
 char *activity;
};
// Function to create a new Day entry
void create(struct Day *day) {
 day->dayName = (char *)malloc(sizeof(char) * 10); // Allocate memory for dayName
 day->activity = (char *)malloc(sizeof(char) * 100); // Allocate memory for activity
 printf("Enter the day name: ");
 scanf("%s", day->dayName); // Take the day name as input
 printf("Enter the date: ");
 scanf("%d", &day->date); // Take the date as input
 printf("Enter the activity for the day: ");
 scanf(" %[^
]s", day->activity); // Take the activity input (including spaces)
}
// Function to read details for each day in the calendar
void read(struct Day *calendar, int size) {
 for (int i = 0; i < size; i++) {
 printf("Enter details for Day %d\n", i + 1);
 create(&calendar[i]); // Call create function for each day
 }
}
// Function to display the details of the calendar
void display(struct Day *calendar, int size) {
 printf("In Week's Activity Details: \n");
 for (int i = 0; i < size; i++) {
 printf("Day %d:\n", i + 1);
 printf("Day Name: %s\n", calendar[i].dayName);
 printf("Date: %d\n", calendar[i].date);
 printf("Activity: %s\n", calendar[i].activity);
 printf("\n");
 }
}
// Function to free allocated memory for each day's details
void freeMemory(struct Day *calendar, int size) {
 for (int i = 0; i < size; i++) {
 free(calendar[i].dayName); // Free the memory for dayName
 free(calendar[i].activity); // Free the memory for activity
 }
}
int main() {
 int size;
 // Ask the user for the number of days in the week
 printf("Enter the number of days in the week: ");
 scanf("%d", &size);
 // Dynamically allocate memory for the calendar
 struct Day *calendar = (struct Day *)malloc(size * sizeof(struct Day));
 // Check if memory allocation was successful
 if (calendar == NULL) {
 printf("Memory allocation failed. Exiting program.\n");
 return 1; // Exit if memory allocation fails
 }
 // Read and display the calendar details
 read(calendar, size);
 display(calendar, size);
 // Free the allocated memory
 freeMemory(calendar, size);
 // Finally, free the memory allocated for the calendar itself
 free(calendar);
 return 0;
}