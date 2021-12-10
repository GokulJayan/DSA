#include<stdio.h>
#include<conio.h>
#define inf 100000
#define max 10

void dijiks(int Adj[max][max], int n, int start)
{
	int visited[max], c, min, next, i,j, cost[max][max], dist[max], pred[max];
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(Adj[i][j]==0)
				cost[i][j]=inf;
			else
				cost[i][j]=Adj[i][j];
	
	for(i=0;i< n;i++)
	{
		dist[i]=cost[start][i];
		pred[i]=start;
		visited[i]=0;
	}
	dist[start]=0;
	visited[start]=1;
	c=1;
	
	while(c < n-1)
	{
		min=inf;
		for(i=0;i < n;i++)
			if(dist[i] < min && !visited[i])
			{
				min=dist[i];
				next=i;
			}
		visited[next]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(min+cost[next][i] < dist[i])
				{
					dist[i]=min+cost[next][i];
					pred[i]=next;
				}
			c++;
	}

	for(i=0;i < n;i++)
		if(i!=start)
		{
            printf("<%d,%d> : Path =%d", start, i, i);

			//printf("\nDistance of %d = %d", i, distance[i]);
			//printf(" Path = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d", j);
			}
			while(j!=start);
            printf(" : Distance =%d\n",dist[i]);
		}
}

void main()
{
	int Adj[max][max], i, j, n, s;
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		scanf("%d", &Adj[i][j]);
	}
	printf("\nEnter the starting node: ");
	scanf("%d", &s);
	dijiks(Adj,n,s);
}

 