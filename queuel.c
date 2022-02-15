#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*temp,*newnode;
struct node*front=NULL;
struct node*rear=NULL;
void enqueue()
{
    int v;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("overflow\n");
    }
    else{
    printf("enter the element\n");
    scanf("%d",&v);
    newnode->data=v;
    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
        front->next=NULL;
        rear->next=NULL;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=NULL;
    }
}
}
void dequeue()
{
    if(front==NULL)
    {
        printf("underflow\n");
    }
    else{
        temp=front;
        front=front->next;
        free(temp);
    }
}
void display()
{
    temp=front;
    if(front==NULL)
    {
        printf("underflow\n");
    }
    else{
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
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
            case 1:
            enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            default:printf("enter the valid operation to perform\n");
            break;
        }
        printf("enter\n1=continue\n0=exit\n");
        scanf("%d",&v);
    }while(v==1);
    return 0;
}
