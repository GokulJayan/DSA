#include<stdio.h>

int *insert(int A[], int n, int i)
{
    if(i<n)
    {
        printf("Enter %d element: ",i+1);
        scanf("%d",&A[i]);
        insert(A,n,++i);
    }    
    else
    return (A);
}

void main()
{
    int n,i=0,A[100];
    printf("Enter n: ");
    scanf("%d",&n);
    insert(A,n,i);
    for(i=0;i<n;i++)
    printf("%d ",A[i]);
}