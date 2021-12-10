#include<stdio.h>

int Sort(int Ar[], int n)
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

int parent[9];

int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

void main()
{
	int i, j, k=0, X, Y, P, Q, n, edges=1, min, mincost=0, Ar[100], cost[9][9];
	printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=10000;
		}
	}
	while(edges <= n-1)
	{
		min=cost[1][1];
		for(i=1;i<=n;i++)
		{
			for(j=2;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					X=P=i;
					Y=Q=j;
				}
			}
		}
		P=find(P);
		Q=find(Q);
		if(uni(P,Q))
		{
			Ar[k++]=min;
			edges++;
			mincost +=min;
		}
		cost[X][Y]=cost[Y][X]=10000;
	}
	Sort(Ar,k);
    for(i=0;i<k;i++)
        printf("%d\n",Ar[i]);
	int COst=1;
	printf("Minimum Spanning Tree Cost: %d",mincost*COst);
}