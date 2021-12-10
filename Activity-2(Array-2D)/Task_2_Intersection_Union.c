#include <stdio.h>

void sort(int Ar[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Ar[i]>Ar[j])
            {
                temp=Ar[i];
                Ar[i]=Ar[j];
                Ar[j]=temp;
            }
        }
    }
}

void Union(int Ar1[], int n1, int Ar2[], int n2)
{
    int i=0,j=0;
    printf("\nUnion of two arrays: ");
    while (i<n1 && j<n2)
    {
        if (Ar1[i] < Ar2[j])
        printf("%d ", Ar1[i++]);
        else if (Ar2[j] < Ar1[i])
        printf("%d ", Ar2[j++]);
        else 
        {
            printf("%d ", Ar2[j++]);
            i++;
        }
    }
    while (i < n1)
        printf("%d ", Ar1[i++]);
    while (j < n2)
        printf("%d ", Ar2[j++]);
}

void Inter(int Ar1[], int n1, int Ar2[], int n2)
{
    int i,j;
    printf("\nIntersection of two arrays: ");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(Ar1[i]==Ar2[j])
            printf("%d ",Ar1[i]);
        }
    }
}

int main()
{
    int A[100],B[100],n1,n2,i;
    printf("\nEnter size of Array-1: ");
    scanf("%d",&n1);
    printf("Enter elements of Array-1: ");
    for(i=0;i<n1;i++)
    scanf("%d",&A[i]);
    
    printf("Enter size of Array-2: ");
    scanf("%d",&n2);
    printf("Enter elements of Array-2: ");
    for(i=0;i<n2;i++)
    scanf("%d",&B[i]);
    sort(A,n1);
    sort(B,n2);
    Union(A,n1,B,n2);
    Inter(A,n1,B,n2);
    return 0;
}