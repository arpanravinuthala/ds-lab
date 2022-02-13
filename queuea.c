#include<stdio.h>
#define SIZE 10
int q[SIZE],front=-1,rear=-1;
void enqueue(int q[],int e)
{
    if(rear==SIZE-1)
    {
        printf("queue overflow\n");
        return;
    }
    else if(rear==-1)
    {
        front++;
        rear++;
        q[rear]=e;
    }
    else
    {
        rear++;
        q[rear]=e;
    }
}
void dequeue(int q[])
{
    int e;
    if(front==-1)
    {
        printf("queue underflow\n");
    }
    else if(front==rear)
    {
        e=q[front];
        front=rear=-1;
    }
    else
    {
        e=q[front];
        front++;
    }
}
void display(int q[])
{
    int i;
    if(rear==-1)
    {
        printf("the queue is empty\n");
        return;
    }
    printf("the elements in the queue are:\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
}
int main()
{
    int e,c,v;
    do
    {
        printf("enter the choice\n1:enqueue\n2:dequeue\n3:display\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("enter the element to insert into the queue\n");
            scanf("%d",&e);
            enqueue(q,e);
            break;
            case 2:dequeue(q);
            break;
            case 3:display(q);
            break;
            default:printf("enter the valid operation to perform\n");
            break;
        }
        printf("enter\n1=continue\n0=exit\n");
        scanf("%d",&v);
    }while(v==1);
    return 0;
}
