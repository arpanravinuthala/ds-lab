#include<stdio.h>
#include<stdlib.h>
void hash(int a[],int n)
{
        int i,h;
        printf("size of the array is %d\n",n);
        for(i=0;i<n;i++)
        {
                printf("enter the element\n");
                scanf("%d",&h);
                a[h%n]=h;
        }
        printf("array elements are\n");
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
