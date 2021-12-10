#include <stdio.h>  
/* function to heapify a subtree. Here 'i' is the   
index of root node in array a[], and 'n' is the size of heap. */   
void Heapify(int Ar[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && Ar[left] > Ar[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && Ar[right] > Ar[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = Ar[i];  
        Ar[i] = Ar[largest];  
        Ar[largest] = temp;  
          
        Heapify(Ar, n, largest);  
    }  
}  
/*Function to implement the heap sort*/  
void HeapSort(int Ar[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        Heapify(Ar, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap a[0] with a[i]  
        int temp = Ar[0];  
        Ar[0] = Ar[i];  
        Ar[i] = temp;  
          
        Heapify(Ar, i, 0);  
    }  
}  
/* function to print the array elements */  
void printArr(int Ar[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", Ar[i]);  
        printf(" ");  
    }  
          
}  
int main()  
{  
    int A[100],n,i;  
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    printf("Before sorting array elements are - \n");  
    printArr(A, n);  
    HeapSort(A, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(A, n);  
    return 0;  
}  