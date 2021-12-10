#include <stdio.h>
 
void insSort(int Ar[], int N)
{
    int i,j,k,key;
    for(i=1;i<N;i++) 
    {
        key=Ar[i];
        j=i-1;
        while(j>=0 && Ar[j]>key) 
        {
            Ar[j+1]=Ar[j];
            j--;
        }
        Ar[j+1]=key;
        printf("    Array after iteration %d: ",i);
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
    insSort(A, n); 
    return 0;
}