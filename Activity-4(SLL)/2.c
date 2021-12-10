#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, vac[100], pep[100], i, flag=0;
    scanf("%d", &n);
    for (i = 0; i <n; i++)
        scanf("%d", &vac[i]);
    for (i = 0; i <n; i++)
        scanf("%d", &pep[i]);
    printf("Vaccine: ");
    for (i = 0; i <n; i++)
        printf("%d ", vac[i]);
    printf("\n");
    printf("People: ");
    for (i = 0; i < n; i++)
        printf("%d ", pep[i]);
    printf("\n");

    for(i=0;i<n;i++)
    {
        if(pep[i]>vac[i])
        flag=1;
    }
    if(flag==0)
    printf("Yes");
    else
    printf("No");
    return 0;
}