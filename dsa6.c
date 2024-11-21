#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int CQ[SIZE];
int front = -1;
int rear = -1;
// Function Prototypes
int IsCQ_Full();
int IsCQ_Empty();
void CQ_Insert(int);
void CQ_Delete();
void CQ_Display();
void main() {
int ch, ele;
while (1) {
printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
if (IsCQ_Full()) {
printf("\nCircular Queue Overflow\n");
} else {
printf("\nEnter the element to be inserted: ");
scanf("%d", &ele);
CQ_Insert(ele);
}
break;
case 2:
if (IsCQ_Empty()) {
printf("\nCircular Queue Underflow\n");
} else {
CQ_Delete();
}
break;
case 3:
if (IsCQ_Empty()) {
printf("\nCircular Queue is empty\n");
} else {
CQ_Display();
}
break;
case 4:
exit(0);
default:
printf("\nInvalid choice, please try again\n");
}
}
}
// Check if Circular Queue is Full
int IsCQ_Full() {
return ((rear + 1) % SIZE == front);
}
// Check if Circular Queue is Empty
int IsCQ_Empty() {
return (front == -1);
}
// Insert element into Circular Queue
void CQ_Insert(int item) {
if (front == -1) {
front = 0; // Set front to 0 for the first element
}
rear = (rear + 1) % SIZE;
CQ[rear] = item;
printf("\nInserted %d into the queue\n", item);
}
// Delete element from Circular Queue
void CQ_Delete() {
int item = CQ[front];
printf("\nDeleted element is: %d\n", item);
if (front == rear) {
// Queue becomes empty after deletion
front = -1;
rear = -1;
} else {
front = (front + 1) % SIZE;
}
}
// Display elements in the Circular Queue
void CQ_Display() {
int i = front;
printf("\nElements of the Circular Queue are: ");
if (front <= rear) {
while (i <= rear) {
printf("%d ", CQ[i]);
i++;
}
} else {
while (i < SIZE) {
printf("%d ", CQ[i]);
i++;
}
i = 0;
while (i <= rear) {
printf("%d ", CQ[i]);
i++;
}
}
printf("\n");
}