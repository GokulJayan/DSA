#include <stdio.h>
 
void BubSort(int Ar[], int N)
{
    int i,j,k,temp;
    for(i=0;i<N-1;i++) 
    {
        for(j=0;j<N-1-i;j++)
        {
            if(Ar[j]>Ar[j+1])    
            {    
                temp=Ar[j];    
                Ar[j]=Ar[j+1];    
                Ar[j+1]=temp;     
            }   
        }
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
    BubSort(A, n); 
    return 0;
}