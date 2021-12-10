#include <stdio.h>

int main()
{
    int A[100][100],B[100][100],r1,c1,r2,c2,i,j,count=0,sum[3][100];
    printf("\nEnter no:of rows and columns of Array_1: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter elements of Array_1:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        scanf("%d",&A[i][j]);
    }

    printf("\nEnter no:of rows and columns of Array_2 : ");
    scanf("%d %d",&r2,&c2);
    if(r1==r2 && c1==c2)
    {
        printf("Enter elements of Array_2:\n");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            scanf("%d",&B[i][j]);
        }
        
        int reduced_A[3][c1],k=0;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                if(A[i][j]!=0)
                {
                    reduced_A[0][k]=i;
                    reduced_A[1][k]=j;
                    reduced_A[2][k]=A[i][j];
                    k++;
                }
            } 
        }

        printf("\nArray after removing zeros in matrix A:\n");
        printf("Row Index: ");
        for(j=0;j<k;j++)
        printf("%d ",reduced_A[0][j]);
        printf("\n");
        printf("Col Index: ");
        for(j=0;j<k;j++)
        printf("%d ",reduced_A[1][j]);
        printf("\n");
        printf("Elements : ");
        for(j=0;j<k;j++)
        printf("%d ",reduced_A[2][j]);


        int reduced_B[3][c2];
        k=0;
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                if(B[i][j]!=0)
                {
                    reduced_B[0][k]=i;
                    reduced_B[1][k]=j;
                    reduced_B[2][k]=B[i][j];
                    k++;
                }
            } 
        }
        printf("\n\nArray after removing zeros in matrix B:\n");
        printf("Row Index: ");
        for(j=0;j<k;j++)
        printf("%d ",reduced_B[0][j]);
        printf("\n");
        printf("Col Index: ");
        for(j=0;j<k;j++)
        printf("%d ",reduced_B[1][j]);
        printf("\n");
        printf("Elements : ");
        for(j=0;j<k;j++)
        printf("%d ",reduced_B[2][j]);
        
        k=0;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                if(A[i][j]!=0 || B[i][j]!=0)
                {
                    sum[0][k]=i;
                    sum[1][k]=j;
                    sum[2][k]=A[i][j]+B[i][j];
                    k++;
                }
            }
        }
        printf("\n\nSum of two sparce Matrices: \n");
        printf("Row Index: ");
        for(j=0;j<k;j++)
        printf("%d ",sum[0][j]);
        printf("\n");
        printf("Col Index: ");
        for(j=0;j<k;j++)
        printf("%d ",sum[1][j]);
        printf("\n");
        printf("Elements : ");
        for(j=0;j<k;j++)
        printf("%d ",sum[2][j]);
        printf("\n\n");
    } 
    return 0;
}