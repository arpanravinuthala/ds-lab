#include<stdio.h>
#include<stdlib.h>
void hash(int a[],int n)
{
        int h,i,j;
        for(i=0;i<n;i++)
        {
                a[i]=0;
        }
        for(i=0;i<n;i++)
        {
                printf("enter the element\n");
                scanf("%d",&h);
                if(a[h%n]==0)
                {
                        a[h%n]=h;
                }
                else
                {
                        j=h%n+1;
                        while(j!=h%n)
                        {
                                if(a[j]==0)
                                {
                                        a[j]=h;
                                        break;
                                }
                                else
                                {
                                        if(j<n)
                                        {
                                                j=j+1;
                                        }
                                        else if(j==n)
                                        {
                                                j=0;
                                        }
                                }
                        }
                }
        }
        printf("elements in the array\n");
        for(i=0;i<n;i++)
        {
                printf("%d\n",a[i]);
        }
}
void main()
{
        int n;
        printf("enter the size of the array\n");
        scanf("%d",&n);
        int a[n];
        hash(a,n);
}
