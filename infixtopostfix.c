#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        // If the character is an operand, add it to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the character is '(', push it to the stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        // If the character is ')', pop and output until '(' is found
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop all the remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}





/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to get the precedence of operators
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        switch (infix[i]) {
            // If the character is an operand, add it to postfix
            case 'A' ... 'Z':
            case 'a' ... 'z':
            case '0' ... '9':
                postfix[j++] = infix[i];
                break;

            // If the character is '(', push it to the stack
            case '(':
                push(infix[i]);
                break;

            // If the character is ')', pop and output until '(' is found
            case ')':
                while (top != -1 && stack[top] != '(') {
                    postfix[j++] = pop();
                }
                pop(); // Pop the '(' from the stack
                break;

            // If the character is an operator
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                    postfix[j++] = pop();
                }
                push(infix[i]);
                break;

            default:
                printf("Invalid character in expression: %c\n", infix[i]);
                exit(1);
        }
        i++;
    }

    // Pop all the remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
*/