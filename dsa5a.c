#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
double compute(char symbol, double op1, double op2) {
switch(symbol) {
case '+': return op1 + op2;
case '-': return op1 - op2;
case '*': return op1 * op2;
case '/': return op1 / op2;
case '^': return pow(op1, op2);
case '%': return fmod(op1, op2);
default: return 0;
}
}
void main() {
double stack[120], res, op1, op2;
int top = -1;
char postfix[120], symbol;
printf("Enter the postfix expression: ");
scanf("%s", postfix);
for (int i = 0; i < strlen(postfix); i++) {
symbol = postfix[i];
if (isdigit(symbol)) {
stack[++top] = symbol - '0'; // Convert char to integer
} else {
op2 = stack[top--];
op1 = stack[top--];
res = compute(symbol, op1, op2);
stack[++top] = res;
}
}
res = stack[top--];
printf("The result is %f\n", res);
}