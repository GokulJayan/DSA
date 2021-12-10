#include<stdio.h>

int max (int A[],int N)
{
  int m = 0;
  for (int i = 0; i < N; i++)
  {
    if (A[i] > m)
	  m = A[i];
  }
  return m;
}

int min (int A[],int N)
{
  int m = A[0];
  for (int i = 1; i < N; i++)
  {
    if (A[i] < m)
	  m = A[i];
  }
  return m;
}

void main ()
{
  int n, a[100];
  printf("Enter array size: ");
  scanf ("%d", &n);
  printf("Enter array elements: ");
  for (int i = 0; i < n; i++)
  scanf ("%d", &a[i]);
  printf ("Smallest number: %d\n", min (a,n));
  printf ("Greater number: %d", max (a,n));
}