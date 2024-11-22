#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfter(int data, int pos) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) 
    {
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int value) 
{
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == value) 
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found in the list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}
void deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    // If there is only one node
    if (head->next == NULL) 
    {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) 
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end.\n");
}

void displayList() 
{
    struct Node* temp = head;
    if (temp == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    int choice, data, pos;
    while (1)
    {
        printf("\n----------[~ LINKED LIST OPERATIONS ~]----------\n");
        printf("1 -> Insert at front\n");
        printf("2 -> Insert at end\n");
        printf("3 -> Insert after position\n");
        printf("4 -> Delete by value\n");
        printf("5 -> Display list\n");
        printf("6 -> Delete from beginning\n");
        printf("7 -> Delete from end\n");
        printf("8 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert after: ");
                scanf("%d", &pos);
                insertAfter(data, pos);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 5:
                displayList();
                break;
            case 6:
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
