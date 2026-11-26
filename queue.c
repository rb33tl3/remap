
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int value)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }

        rear++;
        queue[rear]=value;

        printf("Element inserted successfully\n");
    }
}

void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n",queue[front]);
        front++;

        if(front>rear)
        {
            front=-1;
            rear=-1;
        }
    }
}

void peek()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n",queue[front]);
    }
}

void display()
{
    int i;

    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");

        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
