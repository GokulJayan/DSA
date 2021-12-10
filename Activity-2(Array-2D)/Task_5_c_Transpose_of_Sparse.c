#include <stdio.h>

int main()
{
    int A[100][100], r, c, i, j, count = 0;
    printf("\nEnter no:of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of Array:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            scanf("%d", &A[i][j]);
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (A[i][j] != 0)
                count++;
        }
    }
    int reduced[3][count], k = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (A[i][j] != 0)
            {
                reduced[0][k] = i;
                reduced[1][k] = j;
                reduced[2][k] = A[i][j];
                k++;
            }
        }
    }

    printf("\nArray after removing zeros in matrix A:\n");
    printf("Row Index: ");
    for (j = 0; j < k; j++)
        printf("%d ", reduced[0][j]);
    printf("\n");
    printf("Col Index: ");
    for (j = 0; j < k; j++)
        printf("%d ", reduced[1][j]);
    printf("\n");
    printf("Elements : ");
    for (j = 0; j < k; j++)
        printf("%d ", reduced[2][j]);

    int tran[3][count];
    for (j = 0; j < k; j++)
        tran[0][j] = reduced[1][j];
    for (j = 0; j < k; j++)
        tran[1][j] = reduced[0][j];
    for (j = 0; j < k; j++)
        tran[2][j] = reduced[2][j];

    int temp, co = 0;
    for (i = 0; i < k - 1; i++)
    {
        for (j = i+1; j < k; j++)
        {

            if (tran[0][i] > tran[0][j])
            {
                temp = tran[0][i];
                tran[0][i] = tran[0][j];
                tran[0][j] = temp;

                temp = tran[1][i];
                tran[1][i] = tran[1][j];
                tran[1][j] = temp;

                temp = tran[2][i];
                tran[2][i] = tran[2][j];
                tran[2][j] = temp;
            }
        }
    }

    printf("\n\nTranspose matrix:\n");
    printf("Row Index: ");
    for (j = 0; j < k; j++)
        printf("%d ", tran[0][j]);
    printf("\n");
    printf("Col Index: ");
    for (j = 0; j < k; j++)
        printf("%d ", tran[1][j]);
    printf("\n");
    printf("Elements : ");
    for (j = 0; j < k; j++)
        printf("%d ", tran[2][j]);
    printf("\n");

    return 0;
}