#include <stdio.h>  

void HeapSort(int Ar[], int n)  
{  
    int i, temp;
    for (i = n/2 - 1; i >= 0; i--)  
    Heapify(Ar, n, i);  
    for (i = n - 1; i >= 0; i--) 
    {  
        temp = Ar[0];  
        Ar[0] = Ar[i];  
        Ar[i] = temp;  
          
        Heapify(Ar, i, 0);  
    }  
}  

void Heapify(int Ar[], int n, int i)  
{  
    int max, l, r;
    max = i;
    l = 2 * i + 1;  
    r = 2 * i + 2;

    if (Ar[l] > Ar[max] && l < n)  
    max = l;  

    if (Ar[r] > Ar[max] && r < n)  
    max = r;  

    if (max != i) 
    {  
        int temp = Ar[i];  
        Ar[i] = Ar[max];  
        Ar[max] = temp;  
          
        Heapify(Ar, n, max);  
    }  
}  

int main()  
{  
    int A[100],n,i;  
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    HeapSort(A, n);     
    for (int i = 0; i < n; i++)  
    printf("%d ", A[i]);  
    return 0;  
}  