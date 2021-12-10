#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Sort(int Ar[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Ar[i]>Ar[j])
            {
                temp=Ar[i];
                Ar[i]=Ar[j];
                Ar[j]=temp;
            }
        }
    }
}

void main()
{
    int first,Ar[100], i, j, k=0, X, Y, P, Q, n, edges = 1, mincost = 0, min;
    int cost[10][10];
    
    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter first node:");
    scanf("%d", &first);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            // if(i==n && j==n)
            // cost[i][j]==0;
            // else
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    int visited[10] = {0};
    visited[1] = 1;
    while (edges <= n-1)
    {
        min=cost[1][1];
        for (i = 1; i <= n; i++)
        {
            for (j = 2; j <= n; j++)
            {
                if (visited[i] != 0 && cost[i][j] < min)
                {
                    min = cost[i][j];
                    X = P = i;
                    Y = Q = j;
                }
            }
        }

        if (visited[P] == 0 || visited[Q] == 0)
        {
            Ar[k++]=min;
            edges++;
            mincost += min;
            visited[Y] = 1;
        }
        cost[X][Y] = cost[Y][X] = 10000;
    }
    
    Sort(Ar,k);
    for(i=0;i<k;i++)
        printf("%d\n",Ar[i]);
    int COst=1;
    printf("Minimum Spanning Tree Cost: %d", mincost*COst);
}