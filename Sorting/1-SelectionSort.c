#include <stdio.h>

void SelSort(int Ar[], int N)
{
    int i,j,k,temp,min;
    for(i=0;i<N-1;i++) 
    {
        min=i;
        for(j=i+1;j<N;j++)
        {
            if(Ar[j]<Ar[min])    
            min=j;  
        }
        temp=Ar[min];    
        Ar[min]=Ar[i];    
        Ar[i]=temp;     
        printf("         Array after pass %d: ",i+1);
        for(k=0;k<N;k++)
        printf("%d ",Ar[k]);
        printf("\n");
    }
    printf("\n");
} 

int main()
{
    int A[100],n,i;
    printf("\nEnter size of the array: ");
    scanf("%d",&n);
    printf("Enter elements of the array: ");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    printf("\n");
    SelSort(A, n); 
    return 0;
}