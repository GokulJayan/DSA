#include<stdio.h>

int main()
{
    int A[100][100],trans[100][100],n,i,j,temp;
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
        trans[i][j]=A[j][i];
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n/2;j++)
        {
            temp=trans[i][j];
            trans[i][j]=trans[i][n-1-j];
            trans[i][n-1-j]=temp;
        }
        
    }
    printf("Array after rotation:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",trans[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}