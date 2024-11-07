#include<stdio.h>
#include<stdlib.h>

#define SIZE 5  //size of the circular queue

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) 
{
    if ((rear + 1) % SIZE == front) 
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } 
    else 
    {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Enqueued %d\n", value);
}
int dequeue()
{
    if (front == -1) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("Dequeued %d\n", data);
    return data;
}
void display() 
{
    if (front == -1) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() 
{
    int ch,e;
    while(1)
    {
        printf("\n-------[CIRCULAR QUEUE]-------\n");
        printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n4 -> Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element to enqueue:\n"); scanf("%d",&e); enqueue(e); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0; break;
            default: printf("Enter a valid option!");
        }
        printf("\n");
    }
}
