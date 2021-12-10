
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &Ar[i]);

    mergeSort(Ar, 0, n - 1);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", Ar[i]);
    printf("\n\n");
    return 0;
}