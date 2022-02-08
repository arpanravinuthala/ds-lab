#include<stdio.h>
int s[100],c,n,top,i,x,y;
void push()
{
    if(top>=n-1)
    {
        printf("the stack is full\n");
    }
    else
    {
        printf("enter the value in stack\n");
        scanf("%d",&i);
        s[top]=i;
        top=top+1;
    }
}
void pop()
{
    if(top==0)
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("the element is popped\n");
        top=top-1;
    }
}
void display()
{
    if(top>0)
    {
        printf("the elements in the stack:\n");
        for(y=top-1;y>=0;y--)
        {
            printf("%d ",s[y]);
        }
    }
    else
    {
        printf("the stack is empty\n");
    }
}
int main()
{
    top=0;
    printf("enter the size of the stack\n");
    scanf("%d",&n);
    printf("select an operation to perform on the stack\n");
    do{
        printf("enter\n1=push\n2=pop\n3=display\n");
        scanf("%d",&c);
        switch(c)
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
        printf("enter\n1=continue\n0=stop\n");
        scanf("%d",&x);
    }while(x==1);
    return 0;
}
