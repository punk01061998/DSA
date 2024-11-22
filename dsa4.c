Stack Operations Program in C
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int stack[MAX_SIZE], top = -1, flag = 1, item, temp, rev[MAX_SIZE];
void push();
void pop();
void display();
void pali();
int main()
{
 int choice;
 printf("\nSTACK OPERATIONS");
 printf("\n1. Push");
 printf("\n2. Pop");
 printf("\n3. Palindrome");
 printf("\n4. Display");
 printf("\n5. Exit\n");
 while (1)
 {
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 pali();
 break;
 case 4:
 display(); 
 break;
 case 5:
 exit(0);
 break;
 default:
 printf("Invalid choice\n");
 break;
 }
 }
 return 0;
}
void push()
{
 if (top == MAX_SIZE - 1)
 printf("Stack Overflow\n");
 else
 {
 printf("Enter the element to be inserted: ");
 scanf("%d", &item);
 top = top + 1;
 stack[top] = item;
 }
}
void pop()
{
 if (top == -1)
 {
 printf("Stack Underflow\n");
 flag = 0;
 }
 else
 {
 item = stack[top];
 top = top - 1;
 printf("The popped element: %d\n", item);
 }
}
void pali()
{
 int i = 0;
 if (top == -1)
 {
 printf("Push some elements into the stack first.\n");
 return;
 }
 temp = top;
 while (top != -1)
 {
 rev[i++] = stack[top];
 pop();
 }
 top = temp;
 for (i = 0; i <= temp; i++)
 {
 if (stack[top - i] != rev[i])
 {
 printf("Numbers in stack are NOT Palindrome\n");
 return;
 }
 }
 printf("Numbers in stack are Palindrome\n");
}
void display()
{
 int i;
 if (top == -1)
 printf("Stack is Empty\n");
 else
 {
 printf("The stack elements are: \n");
 for (i = top; i >= 0; i--)
 printf("%d\n", stack[i]);
 }
}