#include <stdio.h>  

int getMax(int a[], int n) // function to get maximum element from the given array  
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  

void bucket(int a[], int n) // function to implement bucket sort  
{  
  int max = getMax(a, n); //max is the maximum element of array  
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)   
    bucket[i] = 0;  
  for (int i = 0; i < n; i++)  
    bucket[a[i]]++;  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }
  }  
}  


int main()
{
   int n, Ar[100], i;
   printf("\nEnter array size: ");
   scanf("%d", &n);
   printf("Enter array elements: ");
   for (i = 0; i < n; i++)
      scanf("%d", &Ar[i]);
   bucket(Ar, n);

   printf("\n\nSorted array: ");
   for (i = 0; i < n; i++)
      printf("%d ", Ar[i]);
   printf("\n\n");
   return 0;
}
