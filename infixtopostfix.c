#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}
char pop() 
{
    if (top == -1) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void infixToPostfix(char* infix, char* postfix) 
{
    int i = 0, j = 0;
    char c;
    while (infix[i] != '\0')
        {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }

        else if (isOperator(infix[i]))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
