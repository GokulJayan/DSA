#include <stdio.h>

void merge(int arr[], int L, int m, int R, int n)
{
    int i = L, j = m + 1, k = L;
    int temp[100];

    while (i <= m && j <= R)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else  
            temp[k++] = arr[j++];
    }

    while (i <= m)
    {
        temp[k++] = arr[i++];
    }

    while (j <= R)
    {
        temp[k++] = arr[j++];
    }

    for (k = L; k <= R; k++)
    arr[k] = temp[k];

    printf("\nArray: ");
    for (k=0; k < n; k++)
    printf("%d ", arr[k]);
    printf("\n\n");
}

void mergeSort(int arr[], int L, int R, int n)
{
    if (L < R)
    {
        int m = (L + R) / 2;

        mergeSort(arr, L, m, n);
        mergeSort(arr, m + 1, R, n);

        merge(arr, L, m, R, n);
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

    mergeSort(Ar, 0, n - 1, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    printf("%d ", Ar[i]);
    printf("\n\n");

    return 0;
}