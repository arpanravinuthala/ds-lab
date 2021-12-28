#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
}*newnode,*temp;
struct node*head=NULL;
struct node*tail=NULL;
void create()
{
    int value,m;
    do{
        printf("enter the value\n");
        scanf("%d",&value);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            tail->next=head;
            head->prev=tail;
        }
        else
        {
         tail->next=newnode;
         newnode->next=head;
         newnode->prev=tail;
         head->prev=newnode;
         tail=newnode;
        }
        printf("enter\n1=add another\n0=stop\n");
        scanf("%d",&m);
    }while(m==1);
}
void display()
{
    temp=head;
    printf("the elements in the circular linked list are :\n");
    while(temp->next!=head)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf(" %d\n",temp->data);
}
void ins_beg()
{
    int value;
    printf("enter the value to insert at the beginning\n");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    head->prev=newnode;
    tail->next=newnode;
    newnode->next=head;
    newnode->prev=tail;
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
    newnode->prev=tail;
    head->prev=newnode;
    newnode->next=head;
    tail=newnode;
}
void ins_pos()
{
    int value,pos,i;
    temp=head;
    printf("enter the value and position to insert respectively\n");
    scanf("%d%d",&value,&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
}
void del_beg()
{
    temp=head;
    tail->next=temp->next;
    temp->next->prev=tail;
    head=temp->next;
    temp->next=NULL;
    temp->prev=NULL;
}
void del_end()
{
    temp=tail;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    tail=temp->prev;
    temp->prev=NULL;
    temp->next=NULL;
}
void del_pos()
{
    int pos,i;
    temp=head;
    printf("enter the position to delete\n");
    scanf("%d",&pos);
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->prev=temp;
}
void main()
{
    int n,h;
    do{
    printf("enter the operation to perform\n1.create\n2.display\n3.insert at the beginning\n4.insert at the end\n5.insert at the position\n6.delete at the beginning\n7.delete at the end\n8.delete at the position\n");
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
        default:printf("enter the correct choice\n");
    }
    printf("enter\n1=continue\n0=exit\n");
    scanf("%d",&h);
}while(h==1);
}
