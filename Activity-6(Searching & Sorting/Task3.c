#include <stdio.h>
 
int *BubSort(int Ar[], int N)
{
    int i,j,k,temp;
    for(i=0;i<N;i++) 
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
    }
    return(Ar);
} 

int main()
{
    int A[100],n,i,k;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    BubSort(A, n);
    for(i=n-1;i>=n-k;i--)
    {
        if(i==n-k)
        printf("%d",A[i]); 
        else
        printf("%d ",A[i]); 

    }
    return 0;
}