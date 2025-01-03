#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Insert the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list from head to tail
void displayForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the list from tail to head
void displayBackward(struct Node* head) {
    if (head == NULL) {
        return;
    }

    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Print the list in reverse order
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found!\n", value);
        return;
    }

    // If the node to delete is the head node
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        // Otherwise, adjust the pointers of previous and next nodes
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    // Free the memory of the deleted node
    free(temp);
}

// Main function to test the doubly linked list
int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Display the list from head to tail
    printf("Forward traversal (head to tail): ");
    displayForward(head);

    // Display the list from tail to head
    printf("Backward traversal (tail to head): ");
    displayBackward(head);

    // Delete a node
    printf("Deleting node with value 20...\n");
    deleteNode(&head, 20);

    // Display the list after deletion
    printf("Forward traversal (after deletion): ");
    displayForward(head);

    return 0;
}
