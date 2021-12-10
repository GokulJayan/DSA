#include <stdio.h>  
  
int getMax(int a[], int n) 
{  
   int max = a[0];  
   for(int i = 1; i<n; i++) 
   {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countingSort(int a[], int n, int place) 
{  
  int output[n + 1];  
  int count[10] = {0};    
  
  // Calculate count of elements  
  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;  
      
  // Calculate cumulative frequency  
  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];  
  
  // Place the elements in sorted order  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  
  for (int i = 0; i < n; i++)  
    a[i] = output[i];  
}  
  

void radixsort(int a[], int n) 
{  
  int c=1,i;
  // get maximum element from array  
  int max = getMax(a, n);  
  
  // Apply counting sort to sort elements based on place value  
  for (int place = 1; max / place > 0; place *= 10)
  {
    countingSort(a, n, place);  
    printf("\n\nArray after pass %d: ",c++);
    for (i = 0; i < n; i++)
      printf("%d ", a[i]);
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
   radixsort(Ar, n);

   printf("\n\nSorted array: ");
   for (i = 0; i < n; i++)
      printf("%d ", Ar[i]);
   printf("\n\n");
   return 0;
}