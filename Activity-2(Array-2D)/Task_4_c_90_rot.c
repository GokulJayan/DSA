#include <stdio.h>

int main()
{
    int A[100][100],rot[100][100],n,i,j;
    printf("\nEnter size of Array: ");
    scanf("%d",&n);
    printf("Enter elements of Array:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&A[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        rot[i][j]=A[j][n-1-i];
    }
    printf("Array after rotation:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",rot[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}