#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued %d into the queue.\n", data);
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d into the queue.\n", data);
}
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int dequeuedData = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Dequeued %d from the queue.\n", dequeuedData);
    return dequeuedData;
}
void displayQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    return 0;
}