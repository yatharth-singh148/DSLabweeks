#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;
//INPUT RESTRICTED
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Function to check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert at rear in input-restricted deque
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Function to delete from front in input-restricted deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) {  // Only one element was present
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Function to delete from rear in input-restricted deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) {  // Only one element was present
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

// Function to display the elements in the deque
void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to test input-restricted deque
int main() {
    insertRear(10);
    insertRear(20);
    insertRear(30);
    displayDeque();

    deleteFront();
    displayDeque();

    deleteRear();
    displayDeque();

    return 0;
}

//OUTPUT RESTRICTED
// Function to insert at front in output-restricted deque
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

// Reusing deleteFront() and insertRear() from previous code

// Main function to test output-restricted deque
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    displayDeque();

    deleteFront();
    displayDeque();

    insertFront(15);
    displayDeque();

    return 0;
}