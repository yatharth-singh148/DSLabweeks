#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int front=-1;
int rear=-1;
int queue[MAX];
void enqueue(int e, int lim)
{
    if(rear!=lim-1)
    {
    if(front == -1)
    {
        front=0;
    }
        ++rear;
        queue[rear]=e;
    }
    else
        printf("Queue Overflow!");
}
void dequeue()
{
    if(front!=-1 && front<=rear)
    {
        printf("%d has been moved out.",queue[front]);
        front++;
    }
    else
        printf("Queue Underflow!");
}
void display()
{
    if(rear!=-1 && front<=rear)
    {
    for(int j=front;j<=rear;j++)
        printf("%d\t",queue[j]);
    }
    else
        printf("Queue is empty.");
}
int main()
{
    printf("Enter number of elements for queue: ");
    int n;
    scanf("%d",&n);
    int ch,ele;
    while(1)
    {
        printf("\n---------QUEUE OPERATIONS--------\n");
        printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n4 -> Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter variable to enqueue: "); scanf("%d",&ele); enqueue(ele, n); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0; break;
            default: printf("\n Enter a valid option!\n");
        }

    }
}
