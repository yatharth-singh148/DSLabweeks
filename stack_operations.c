#include <stdio.h>
#include <stdlib.h>
int arr[100],size,top;
int push(int ele)
{
    if(top!=size-1)
    {
        arr[top+1]=ele;
        top++;
        printf("\nElement Pushed\n");
    }
    else if(top==size-1)
    {
        printf("\nStack is full.");
    }
}
int pop()
{
        if(top!=-1)
    {
        printf("\nPopped element `%d`",arr[top]);
        arr[top+1]=0;
        top--;
        printf("\nElement Popped\n");
    }
    else if(top==-1)
    {
        printf("\nStack is Empty.");
    }
}
int display()
{
    printf("\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
    size=0;
    printf("Enter size of stack: ");
    scanf("%d",&size);
    top=-1;
    int ch=1;
    int e;
    while(ch<4 && ch>0)
    {
        printf("\nPick option:\n1) Push\n2) Pop\n3) Display\n4) Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to push:\n"); scanf("%d",&e); push(e); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("\nClosing..."); break;
            default: printf("\nEnter valid option!");
        }
    }


}
