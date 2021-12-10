#include <stdio.h>

int binsearch(int Ar[], int n, int ele) 
{
    int beg=0,end=n-1,mid;
    while (beg<=end)
    {
        mid=(beg+end)/2;
        if (Ar[mid]==ele)
        return 1;
        else if (Ar[mid] < ele)
        beg = mid + 1;
        else
        end=mid-1;
    }
    return 0;
}

int main()
{
    int A[100],n,i,diff,B[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    diff=A[1]-A[0];
    for(i=0;i<=n;i++)
    B[i]=A[0]+(i*diff);
    for(i=0;i<=n;i++)
    printf("%d ",B[i]);
    printf("\n");
    for(i=0;i<=n;i++)
    {
        if(binsearch(A,n,B[i])==0)
        printf("%d\n",B[i]);
    }
    return 0;
}