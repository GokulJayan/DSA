#include <stdio.h>

int binsearch(int Ar[], int N, int element)
{
    int beg=0,mid,end=N-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(element==Ar[mid])
        return mid;
        else if(element>mid)
        beg=mid+1;
        else if(element<mid)
        end=mid-1;
        else
        return -1;
    }
} 

int main()
{
    int A[100],n,i,ele,pos;
    printf("\nEnter size of the array: ");
    scanf("%d",&n);
    printf("Enter elements of sorted array: ");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    printf("Enter element to be searched: ");
    scanf("%d",&ele);
    pos=binsearch(A,n,ele);
    if(pos==-1)
    printf("\nElement not found: %d\n",pos);
    else
    printf("\nIndex of the element: %d\nPosition of the element: %d\n\n",pos,pos+1);
    return 0;
}