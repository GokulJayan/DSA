#include <stdio.h>
 
int main()
{
  int m1, n1, m2, n2, i, j, k, sum = 0;
  int A[100][100], B[100][100], mul[100][100];
 
  printf("\nEnter number of rows and columns of first matrix: ");
  scanf("%d%d", &m1, &n1);
  printf("Enter elements of first matrix:\n");
  for (i=0;i<m1;i++)
  {
    for (j=0;j<n1;j++)
    scanf("%d",&A[i][j]);
  }
  
  printf("Enter number of rows and columns of second matrix: ");
  scanf("%d%d",&m2,&n2);
 
  if (n1!=m2)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix:\n");
    for (i=0;i<m2;i++)
    {
      for (j=0;j<n2;j++)
      scanf("%d",&B[i][j]);
    }
 
    for (i=0;i<m1;i++) 
    {
      for (j=0;j<n2;j++) 
      {
        for (k=0;k<m2;k++)
        sum+=A[i][k]*B[k][j];
        
        mul[i][j]=sum;
        sum = 0;
      }
    }
 
    printf("Product of the matrices:\n");
 
    for (i=0;i<m1;i++) 
    {
      for (j=0;j<n2;j++)
      printf("%d\t",mul[i][j]);
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}