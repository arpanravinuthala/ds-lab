#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int expo;
    int coeff;
    struct poly* next;
}*temp,*newterm,*head1=NULL,*head2=NULL,*head3=NULL,*tail=NULL,*temp1,*temp2;
struct poly* create(struct poly *head)
{
    int a;
    printf("enter elements of the polynomial in descending order of exponents");
    do
    {
        newterm=(struct poly*)malloc(sizeof(struct poly));
        printf("enter exponent and coefficient in order:");
        scanf("%d%d",&newterm->expo,&newterm->coeff);
        newterm->next=NULL;
        if(head==NULL)
        {
            head=newterm;
            tail=newterm;
        }
        else
        {
            tail->next=newterm;
            tail=newterm;
        }
        printf("do you want to add terms(yes=1):");
        scanf("%d",&a);
    }while(a==1);
    return(head);
}
void display(struct poly* head)
{
    int c=0;
    temp=head;
    while(temp!=NULL)
    {
        printf("%dX^%d+",temp->coeff,temp->expo);
        temp=temp->next;
        c++;
    }
    printf("\n");
}
void add()
{
    temp1=head1;
    temp2=head2;
    while(temp1&&temp2)
    {
        if(temp1->expo==temp2->expo) {
            printf("%dX^%d+",temp1->coeff+temp2->coeff,temp1->expo);
            temp1=temp1->next;
            temp2=temp2->next;
        }else if(temp1->expo>temp2->expo) {
            printf("%dX^%d+",temp1->coeff,temp1->expo);
            temp1=temp1->next;
        }else {
            printf("%dX^%d+",temp2->coeff,temp2->expo);
            temp2=temp2->next;
        }
    }
    if(temp2==NULL)
    {
        while(temp1!=NULL) {
            printf("%dX^%d+",temp1->expo);
            temp1=temp->next;
        }
    }else
    {
        while(temp2!=NULL)
        {
            printf("%dX^%d+",temp2->coeff,temp2->expo);
            temp2=temp2->next;
        }
    }
    printf("\n");
}
void mul()
{
    temp1=head1;
    while(temp1!=NULL)
    {
        temp2=head2;
        while(temp2!=NULL)
        {
            newterm=(struct poly*)malloc(sizeof(struct poly));
            newterm->coeff=(temp1->coeff)*(temp2->coeff);
            newterm->expo=(temp1->expo)+(temp2->expo);
            newterm->next=NULL;
            if(head3==NULL)
            {
                head3=newterm;
                tail=newterm;
            }
            else
            {
                tail->next=newterm;
                tail=newterm;
            }
            printf("%d+^%d ",(temp1->coeff)*(temp2->coeff),(temp1->expo)+(temp2->expo));
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    temp=head3;
temp1 = head3->next;
while(temp1 != NULL)
{
if(temp->expo == temp1->expo)
{
   temp->coeff = temp->coeff + temp1->coeff;
        temp->next = temp1->next;
        temp = temp->next;
        temp1 = temp->next;
        }
        else
        {
        temp = temp1;
        temp1 = temp->next;
}
}
}


void main()
{
    int ch;
    do
    {
        printf("\n1.create 2 polynomials\n2.display 2 polynomials\n3.add\n4.multiply\n5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head1=create(head1);
                   head2=create(head2);
                   break;
            case 2:display(head1);
                   display(head2);
                   break;
            case 3: add();
                    break;
            case 4: mul();
                    display(head3);
                    break;
        }
    } while (ch<5);
}
