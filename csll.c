#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void ins_beg();
void ins_end();
void ins_pos();
void del_beg();
void del_end();
void del_pos();
struct node
{
    int data;
    struct node*next;
}*newnode,*temp;
struct node*head=NULL;
struct node*tail=NULL;
void main()
{
    int n,j;
    do{
    printf("enter\n1.create\n2.display\n3.insert at beginning\n4.insert at end\n5.insert at position\n6.delete at beginning\n7.delete at end\n8.delete at a given position\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:create();
        break;
        case 2:display();
        break;
        case 3:ins_beg();
        break;
        case 4:ins_end();
        break;
        case 5:ins_pos();
        break;
        case 6:del_beg();
        break;
        case 7:del_end();
        break;
        case 8:del_pos();
        break;
        default:printf("choose from the given options\n");
    }printf("do you want to continue\n1=continue\n0=exit\n");
        scanf("%d",&j);
}while(j==1);
}
void create()
{
    int value,h;
    do{
        printf("enter the element\n");
        scanf("%d",&value);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            tail->next=head;
        }
        else
        {
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
        }
        printf("1=continue\n0=continue\n");
        scanf("%d",&h);
    }while(h==1);
}
void display()
{
    temp=head;
    while(temp->next!=head)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void ins_beg()
{
    int value;
    printf("enter the to value to insert at the beginning\n");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    tail->next=newnode;
    newnode->next=head;
    head=newnode;
}
void ins_end()
{
    int value;
    printf("enter the value to insert at the end\n");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    tail->next=newnode;
    newnode->next=head;
    tail=newnode;
}
void ins_pos()
{
    int value,pos,i;
    temp=head;
    printf("enter the value and position respectively\n");
    scanf("%d%d",&value,&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    for(i=0;i<(pos-1);i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void del_beg()
{
    temp=head;
    tail->next=temp->next;
    head=temp->next;
    temp->next=NULL;
}
void del_end()
{
    temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
       
    }
    temp->next=head;
    tail->next=NULL;
    tail=temp;
}
void del_pos()
{
    int pos,i;
    temp=head;
    printf("enter the position to delete\n");
    scanf("%d",&pos);
    for(i=0;i<(pos-1);i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
}
