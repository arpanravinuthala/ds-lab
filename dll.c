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
    int value,n;
    do{
    printf("enter the value\n");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=NULL;
        tail=newnode;
    }
    printf("1=add another\n0=stop\n");
    scanf("%d",&n);
    }while(n==1);
}
void display()
{
    temp=head;
    while(temp->next!=NULL)
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
    newnode->next=head;
    newnode->prev=NULL;
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
    tail=newnode;
}
void ins_pos()
{
    int i,value,pos;
    temp=head;
    printf("enter the value and position to insert\n");
    scanf("%d%d",&value,&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
}
void del_beg()
{
    temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
}
void del_end()
{
    temp=tail;
    temp->prev->next=NULL;
    tail=temp->prev;
    temp->prev=NULL;
}
void del_pos()
{
    int pos,i;
    printf("enter the position to delete the element\n");
    scanf("%d",&pos);
    temp=head;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->prev=temp;
}
void search()
{
    int a,c=0;
    printf("enter the element to search\n");
    scanf("%d",&a);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==a)
        {
            c=1;
            printf("element is present in the linked list\n");
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    if(c==0)
    {
        printf("element is not present\n");
    }
}
void main()
{
    int h,m;
    do{
        printf("enter\n1.create\n2.display\n3.insert at beginning\n4.insert at the end\n5.insert at the position\n6.delete at beginning\n7.delete at end\n8.delete at specified position\n9.search\n");
        scanf("%d",&h);
        switch(h)
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
            case 9:search();
            break;
            default:printf("enter the correct choice\n");
        }
        printf("1=continue\n0=exit\n");
        scanf("%d",&m);
    }while(m==1);
}
