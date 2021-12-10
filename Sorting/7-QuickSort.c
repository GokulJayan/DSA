#include <stdio.h>

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int beg, int last, int n)
{
  int pivot,i,j,k;
  pivot=array[last]; 
  i = beg;
  
  for (j=beg;j<last;j++) 
  {
    if (array[j]<=pivot)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[last]); 

  printf("\nArray after partioning: ");
  for(k=0;k<n;k++)
  printf("%d ",array[k]);
  printf("\n");
  printf("\n");

  return (i); 
}


void quickSort(int A[], int beg, int last,int n) 
{
    int i;
  if (beg < last) 
  {
    int pi = partition(A, beg, last,n);
    quickSort(A, beg, pi - 1,n);
    quickSort(A, pi + 1, last,n);
  }
}


int main() 
{
  int Ar[100],i,n;
  printf("\nEnter size: ");
  scanf("%d",&n);
  printf("Enter elements: ");
  for(i=0;i<n;i++)
  scanf("%d",&Ar[i]);

  quickSort(Ar,0,n-1,n);

  printf("\nSorted array  : ");
  for(i=0;i<n;i++)
  printf("%d ",Ar[i]);
  printf("\n");
  printf("\n");
}
