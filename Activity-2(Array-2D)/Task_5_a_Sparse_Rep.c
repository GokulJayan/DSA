#include <stdio.h>

int main()
{
    int A[100][100],r,c,i,j,count=0;
    printf("\nEnter no:of rows and columns of Array: ");
    scanf("%d %d",&r,&c);
    printf("Enter elements of Array:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        scanf("%d",&A[i][j]);
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]!=0)
            count++;
        }
    }

    int reduced[3][count],k=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]!=0)
            {
                reduced[0][k]=i;
                reduced[1][k]=j;
                reduced[2][k]=A[i][j];
                k++;
            }
        }
    }

    printf("Array after removing zeros:\n");
    printf("Row Index: ");
    for(j=0;j<k;j++)
    printf("%d ",reduced[0][j]);
    printf("\n");
    printf("Col Index: ");
    for(j=0;j<k;j++)
    printf("%d ",reduced[1][j]);
    printf("\n");
    printf("Elements : ");
    for(j=0;j<k;j++)
    printf("%d ",reduced[2][j]);
    printf("\n\n");
    return 0;
}