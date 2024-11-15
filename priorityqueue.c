#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int heap[SIZE];
int heapSize = 0;
void enqueue(int value) {
    if (heapSize == SIZE) {
        printf("Priority Queue is full.\n");
        return;
    }
    int i = heapSize;
    heap[heapSize++] = value;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;
        i = (i - 1) / 2;
    }

    printf("Enqueued %d\n", value);
}
int dequeue() {
    if (heapSize <= 0) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    
    int max = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heapSize && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest == i) break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        
        i = largest;
    }

    printf("Dequeued %d\n", max);
    return max;
}
void display() {
    if (heapSize == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int main() {
    enqueue(20);
    enqueue(15);
    enqueue(30);
    enqueue(5);
    enqueue(10);
    display();

    dequeue();
    display();

    enqueue(25);
    display();

    return 0;
}