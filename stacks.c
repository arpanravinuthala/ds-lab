#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*newnode,*temp;
struct node*head=NULL;
void push()
{
    int v;
    printf("enter the value to insert the value in stack\n");
    scanf("%d",&v);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=v;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode; 
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("the stack is empty\n");
    }
    else
    {
    temp=head->next;
    free(head);
    head=temp;
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main()
{
    int c,k;
    do
    {
        printf("enter\n1=push\n2=pop\n3=display\n");
        scanf("%d",&k);
        switch(k)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            default:printf("enter the correct choice\n");
            break;
        }
        printf("enter\n1=continue\n2=stop\n");
        scanf("%d",&c);
    }while(c==1);
}
