#include <stdio.h>

void insSort(int Ar[], int N)
{
    int i,j,key;
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
    }
    for(i=0;i<N;i++)
    {
        if(i==N-1)
        printf("%d",Ar[i]);
        else
        printf("%d ",Ar[i]);
    }
    
} 

int main()
{
    int A[100],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    insSort(A, n); 
    return 0;
}