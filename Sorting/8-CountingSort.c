#include <stdio.h>

int Max(int a[], int n)
{
   int max = a[0];
   for (int i = 1; i < n; i++)
   {
      if (a[i] > max)
         max = a[i];
   }
   return max;
}

void countSort(int Ar[], int n)
{
   int output[n + 1];
   int max = Max(Ar, n);
   int count[max + 1]; //create count array with size [max+1]
   int i;

   for (i = 0; i <= max; ++i)
      count[i] = 0; // Initialize count array with all zeros

   for (i = 0; i < n; i++) // Store the count of each element
      count[Ar[i]]++; 

   for (i = 1; i <= max; i++)
      count[i] += count[i - 1]; //find cumulative frequency

   /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/
   for (i = n - 1; i >= 0; i--)
   {
      output[count[Ar[i]] - 1] = Ar[i];
      count[Ar[i]]--; // decrease count for same numbers
   }

   for (i = 0; i < n; i++)
      Ar[i] = output[i]; //store the sorted elements into main array
}

int main()
{
   int n, Ar[100], i;
   printf("\nEnter array size: ");
   scanf("%d", &n);
   printf("Enter array elements: ");
   for (i = 0; i < n; i++)
      scanf("%d", &Ar[i]);
   countSort(Ar, n);

   printf("\n\nSorted array: ");
   for (i = 0; i < n; i++)
      printf("%d ", Ar[i]);
   printf("\n\n");
   return 0;
}