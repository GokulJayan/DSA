#include<stdio.h>

int main()
{
  int r,c,i,j;
  int A[100][100];
 
  printf("Enter number of rows and columns matrix: ");
  scanf("%d%d", &r, &c);
  printf("Enter elements of matrix:\n");
  for (i=0;i<r;i++)
  {
    for (j=0;j<c;j++)
    scanf("%d",&A[i][j]);
  }
  printf("\nTransposed Array:\n");
  for(i=0;i<c;i++)
  {
    for(j=0;j<r;j++)
    printf("%d ",A[j][i]);
    printf("\n");
  }
  return 0;
}