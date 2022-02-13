#include <stdio.h>
#include <ctype.h>
#define SIZE 100 
#define POSTSIZE 100
int s[SIZE];
int top = -1; 
void push(int h)
{
    if(top>=SIZE-1){
        printf("stack over flow\n");
        return;
    }
    else
    {
        top++;
        s[top]=h;
    }
}
int pop()
{
    int w;
    if(top<0){
        printf("stack under flow\n");
    }
    else 
    {
        w= s[top];
        top--;
        return w;
    }
}
void PostEval(char post[])
{
    int i,a,b,k;
    char c;
    for (i = 0;post[i]!=')'; i++)
    {
        c=post[i];
        if (isdigit(c))
        {
            push(c-'0');
        }
        else if (c=='*'||c=='/'||c=='+'||c=='-') 
        {
            a=pop();
            b=pop();
            switch (c) 
            {
            case '*':k=b*a;
            break;
            case '/':k=b/a;
            break;
            case '+':k=b+a;
            break;
            case '-':k=b/a;
            break;
            }
            push(k);
        }
    }
    printf("Result of the given postfix express is : %d\n",pop());
}
int main()
{
    int j;
    char post[POSTSIZE];
    printf("only the *,/,+,- operators are evaluated\n");
    printf("Enter the postfix expression and add ')'[right paranthesis at the end]\n");
    for(j=0;j<=POSTSIZE-1;j++) 
    {
        scanf("%c", &post[j]);
        if (post[j] == ')') 
        {
            break;
        }  
    }
    PostEval(post);
    return 0;
}
