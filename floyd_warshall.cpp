#include<stdio.h>
#include<stdlib.h>
#define V 4
#define INF 99999

void printsolution(int dist[][V])
{
	int i,j;
printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }

}

void printpath(int parent[][V],int u,int v)
{
if(parent[u][v]==u)
{
	printf("%d",u);
	return;
}
if(parent[u][v]!=INF)
{
printf("%d<-",parent[u][v]);
printpath(parent,u,parent[u][v]);
}
}

void floydwarshall(int graph[][V])
{
	int dist[V][V],i,j,k;
	int parent[V][V];

	for(i=0;i<V;i++)
	for(j=0;j<V;j++)
	{
	dist[i][j]=graph[i][j];

	if(i==j)
	parent[i][j]=INF;
if(graph[i][j]!=INF)
parent[i][j]=i;
else
parent[i][j]=INF;
}

	for(k=0;k<V;k++)
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
				dist[i][j]=dist[i][k]+dist[k][j];
				parent[i][j]=parent[k][j];
			}
			}
		}
	}
	printsolution(dist);
	printf("\n\n");
	for(i=0;i<V;i++)
	for(j=0;j<V;j++)
	{
printf("Path between %d and %d passes through = \n",i,j);
if(parent[i][j]!=INF)
{
printf("%d<-",j);
	printpath(parent,i,j);
	printf("\n");
}
else
printf("No path\n");
}
}

int main()
{
	/* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */

    int graph[V][V]={{0,5,INF,10},
					 {INF,0,3,INF},
					 {INF,INF,0,1},
					 {INF,INF,INF,0}
					 };

floydwarshall(graph);
return 0;
}
