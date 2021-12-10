
    int choice;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < n; i++)
        insert(A[i]);
    //checkEven();
    display();
    return 0;
}
