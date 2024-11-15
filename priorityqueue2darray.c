#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Maximum number of elements 

int queue[SIZE][2];  // 2D array where first column stores value, second column priority
int rear = -1;
int isEmpty() {
    return (rear == -1);
}
int isFull() {
    return (rear == SIZE - 1);
}
void enqueue(int value, int priority) {
    if (isFull()) {
        printf("Priority Queue is full. Cannot enqueue %d\n", value);
        return;
    }

    rear++;
    queue[rear][0] = value;
    queue[rear][1] = priority;
    printf("Enqueued %d with priority %d\n", value, priority);
}
int dequeue() {
    if (isEmpty()) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int highestPriorityIndex = 0;
    for (int i = 1; i <= rear; i++) {
        if (queue[i][1] > queue[highestPriorityIndex][1]) {
            highestPriorityIndex = i;
        }
    }

    int dequeuedValue = queue[highestPriorityIndex][0];
    printf("Dequeued %d with priority %d\n", dequeuedValue, queue[highestPriorityIndex][1]);
    for (int i = highestPriorityIndex; i < rear; i++) {
        queue[i][0] = queue[i + 1][0];
        queue[i][1] = queue[i + 1][1];
    }
    rear--;

    return dequeuedValue;
}
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements (value, priority): ");
    for (int i = 0; i <= rear; i++) {
        printf("(%d, %d) ", queue[i][0], queue[i][1]);
    }
    printf("\n");
}
int main() {
    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 3);
    enqueue(40, 1);
    enqueue(50, 4);
    display();

    dequeue();
    display();

    enqueue(60, 6);
    display();

    return 0;
}