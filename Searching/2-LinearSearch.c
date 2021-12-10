#include <stdio.h>

int linSearch(int Ar[], int N, int element)
{
    int i,pos=0;
    for(i=0;i<N;i++)
    {
        if(element==Ar[i])
        {
            pos=i;
            break;
        }
        else
        pos=-1;
    }
    return pos;
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
    pos=linSearch(A,n,ele);
    if(pos==-1)
    printf("\nElement not found: %d\n",pos);
    else
    printf("\nIndex of the element: %d\nPosition of the element: %d\n\n",pos,pos+1);
    return 0;
}