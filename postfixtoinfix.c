#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX]; 
int top = -1;

void push(char* str) {
    if (top == MAX - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    strcpy(stack[++top], str);
}

void pop(char* str) {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    strcpy(str, stack[top--]);
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postfixToInfix(char* postfix, char* infix) {
    char operand1[MAX], operand2[MAX], temp[MAX];
    int i = 0, j = 0;

    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            char str[2] = { postfix[i], '\0' }; 
            push(str);
        } else if (isOperator(postfix[i])) {
            pop(operand2); 
            pop(operand1); 
            sprintf(temp, "(%s %c %s)", operand1, postfix[i], operand2);
            push(temp); 
        }
        i++;
    }

    pop(infix);
}

int main() {
    char postfix[MAX], infix[MAX];
    printf("Enter a Postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);
    return 0;
}
