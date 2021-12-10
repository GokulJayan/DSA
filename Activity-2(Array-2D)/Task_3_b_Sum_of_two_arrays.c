#include<stdio.h>

int main()
{
  int r1,c1,r2,c2,i,j;
  int A[100][100],B[100][100];
 
  printf("Enter number of rows and columns matrix-1: ");
  scanf("%d%d", &r1, &c1);
  printf("Enter elements of matrix-1:\n");
  for (i=0;i<r1;i++)
  {
    for (j=0;j<c1;j++)
    scanf("%d",&A[i][j]);
  }

  printf("Enter number of rows and columns matrix-2: ");
  scanf("%d%d", &r2, &c2);
  printf("Enter elements of matrix-2:\n");
  for (i=0;i<r2;i++)
  {
    for (j=0;j<c2;j++)
    scanf("%d",&B[i][j]);
  }

  if(r1==r2 && c1==c2)
  {
      printf("\nSum of two arrays:\n");
      for(i=0;i<r1;i++)
      {
          for(j=0;j<c1;j++)
          printf("%d ",A[i][j]+B[i][j]);
          printf("\n");
      }
  }
  else
  printf("Arrays are of different sizes!!!");
  return 0;
}