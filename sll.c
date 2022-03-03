#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
}*temp,*new_node;
struct node* head=NULL;
struct node* tail=NULL;
void create()
{
int c=1,value;
while(c==1)
{
new_node = (struct node*)(malloc(sizeof(struct node)));
printf("Enter the value : ");
scanf("%d",&value);
new_node->data=value;
new_node->next=NULL;
if(head==NULL)
{
head=new_node;
tail=new_node;
}
else
{
tail->next=new_node;
tail=new_node;
}
printf("Enter (1) to continue (0) to exit.....\n");
scanf("%d",&c);
}
}
void display()
{
int count=1;
temp = head;
printf("The elements are : \n");
while(temp != NULL)
{
printf("%d) %d\n",count,temp->data);
count++;
temp=temp->next;
}
}
void insert()
{
int element,position,count=1;
printf("Enter element : ");
scanf("%d",&element);
printf("Enter position : ");
scanf("%d",&position);
new_node = (struct node*)(malloc(sizeof(struct node)));
new_node->data=element;
temp=head;
while(temp != NULL)
{
if (count == position)
{
new_node->next=temp->next;
temp->next=new_node;
}
temp=temp->next;
count++;
}

}
void insert_at_beginning()
{
int element;
printf("Enter element : ");
scanf("%d",&element);
new_node=(struct node*)(malloc(sizeof(struct node)));
new_node->data=element;
new_node->next=head;
head=new_node;
}
void insert_at_ending()
{
int element;
printf("Enter element : ");
scanf("%d",&element);
new_node=(struct node*)(malloc(sizeof(struct node)));
new_node->data = element;
tail->next = new_node;
new_node->next = NULL;
tail=new_node;
}
void delete_()
{
int element,flag=0;
printf("Enter element : ");
scanf("%d",&element);
temp=head;
while(temp->next!=NULL)
{
if(element==temp->next->data)
{
temp->next=temp->next->next;
flag+=1;
break;
}
temp=temp->next;
}
if(flag==0)
{
printf("Sorry the element is not present\n");
}
}
void delete_at_beginning()
{
temp=head->next;
head->next=NULL;
head=temp;
}
void delete_at_ending()
{
temp=head;
while(temp->next!=NULL)
{
new_node=temp;
temp=temp->next;
}
new_node->next=NULL;
tail=new_node;
}
void length()
{
int count=1;
temp=head;
while(temp->next!=NULL)
{
count+=1;
temp=temp->next;
}
printf("The length of the list : %d\n",count);
}
int main()
{
int choice,c=1;
  printf("---------------------------------------------------------\n");
printf("1.Create\n2.Display\n3.Insert\n4.Insert at beginning\n5.Insert at ending");
printf("\n6.Delete\n7.Delete at beginning\n8.Delete at ending\n9.Length\n10.Quit\n");
printf("**********************************************************\n");
while(c==1)
{
printf("Enter your choice : \n");
scanf("%d",&choice);
printf("---------------------------------------------------------\n");
switch(choice)
{
case 1: create();
break;
case 2:display();
break;
case 3:insert();
break;
case 4:insert_at_beginning();
break;
case 5:insert_at_ending();
break;
case 6:delete_();
break;
case 7:delete_at_beginning();
break;
case 8:delete_at_ending();
break;
case 9:length();
break;
case 10:c=0;
break;
default:printf("Enter valid number \n");
}
}

return 0;
}
