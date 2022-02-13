#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
char s[SIZE];
int top=-1;
void push(char item)
{
    if(top>=SIZE-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top=top+1;
        s[top]=item;
    }
}
char pop()
{
    char item;
    if(top<0)
    {
        printf("stack underflow\n");
        getchar();
        exit(1);
    }
    else
    {
        item=s[top];
        top=top-1;
        return(item);
    }
   
}
int is_operator(char symbol)
{
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char symbol)
{
    if(symbol=='^')
    {
        return 3;
    }
    else if(symbol=='*' || symbol=='/')
    {
        return 2;
    }
    else if(symbol=='+' || symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void InfixToPostfix(char infix_exp[],char postfix_exp[])
{
    int i,j;
    char item,x;
    push('(');
    strcat(infix_exp,")");
    i=0;
    j=0;
    item=infix_exp[i];
    while(item!='\0')
    {
        if(item=='(')
        {
            push(item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfix_exp[j]=item;
            j=j+1;
        }
        else if(is_operator(item)==1)
        {
            x=pop();
            if(is_operator(x)==1 && precedence(x)>=precedence(item))
            {
                postfix_exp[j]=x;
                j=j+1;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')')        
{
x = pop();                  
while(x != '(')                
{
postfix_exp[j] = x;
j++;
x = pop();
}
}
else
{
printf("\nInvalid infix Expression.\n");      
getchar();
exit(1);
}
i++;
item = infix_exp[i];
}
if(top>0)
{
printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
getchar();
exit(1);
}
postfix_exp[j] = '\0';
}
void main()
{
    char infix[SIZE],postfix[SIZE];
    printf("enter the infix expression\n");
    gets(infix);
    InfixToPostfix(infix,postfix);
    printf("Postfix expression\n");
    puts(postfix);
}
