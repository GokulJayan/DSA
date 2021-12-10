#include<stdio.h>

void reverse(int Ar[],int n)
{
    int i=0,j=n-1,temp;
    while(i<j)
    {
        temp=Ar[i];
        Ar[i]=Ar[j];
        Ar[j]=temp;
        i++;
        j--;
    }
}

void main()
{
    int A[100],n,i;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    reverse(A,n);
    printf("Reversed array:       ");
    for(i=0;i<n;i++)
    printf("%d ",A[i]);
}