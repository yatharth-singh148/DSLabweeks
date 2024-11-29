#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from the stack.\n", poppedData);
    return poppedData;
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}
int main() 
{
    struct Node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    displayStack(top);
    pop(&top);
    displayStack(top);

    return 0;
}