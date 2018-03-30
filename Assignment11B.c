//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment11B.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HIGH 999999

//Assuming that source is the 1st vertex and then there are n vertices between source and sink and sink is the last vertex
//thus the total number of vertices are n+2

int min(int a,int b)//function to find the minimum of two values
{
	if(a<=b) return a;
	else return b;
}

int BFS(int start,int *parent,int **residue,int n)//Breadth first search
	{
	int queue[n],count = 0,number = 0,itr = 0,i,j;
	int visited[n];//visited array
	for(i=0;i<n;i++)
		visited[i] = 0;//initializing the array
	queue[0] = start;//enqueueing element in the queue
	count++;
	number++;
	for(i=0;i<n;i++)
		{
		//visited[i] = 0;
		parent[i] = -1;//initializing the parent matrix
		}
	visited[start] = 1;
	parent[start] = -1;
	while(count!=0)
		{
		for(i=0;i<n;i++)
			{
			if(residue[queue[itr]][i]>0 && visited[i]==0)//if still the full capacity of an edge is not completely exhausted
				{
				queue[number] = i;
				number++;
				visited[i] = 1;
				parent[i] = queue[itr];
				count++;
				}
			
			}
			count--;
			visited[queue[itr]] = 2;
			itr++;		
		}
	if(parent[n-1]==-1) return 0;//if sink is reachable from the source
	else return 1;	
	}
	
int fordFulkerson(int** rgraph, int s, int t,int n)//Algorithm to find the max-flow
{
    int u, v;
    int parent[n];
 
    int max_flow = 0; 
    while (BFS(s,parent,rgraph,n))//while sink is reachable from the source
    {
        int path_flow = HIGH;
        for (v=t; v!=s; v=parent[v])
        {
            
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
        
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}	

int main()
{
	int i,j,n;
	printf("Enter the number of vertices leaving source and sink vertex: ");
	scanf("%d",&n);
	int **adj,**weight,**residue;
	adj = malloc((n+2)*sizeof(int*));//creating the adjacency,weight,residue matrices
	weight = malloc((n+2)*sizeof(int*));
	residue = malloc((n+2)*sizeof(int*));
	n = n+2;
	for(i=0;i<n;i++){
		adj[i] = malloc((n)*sizeof(int));//allocating the arrays memory
		weight[i] = malloc((n)*sizeof(int));
		residue[i] = malloc((n)*sizeof(int));
		}
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			adj[i][j] = 0;//initializing the arrays
			weight[i][j] = 0;
			residue[i][j] = weight[i][j];
			}
		}
	for(i=0;i<n;i++)//applying the constraints for edge
		{
		for(j=0;j<n;j++)
			{
			if(i==0)
				{
				if(j>=1 && j<=(n-2)/4)
					{
					adj[i][j] = 1;
					weight[i][j] = j;
					residue[i][j] = weight[i][j];
					}
				}
			else if(j==n-1)
				{
				if(i>=3*(n-2)/4 && i<=n-2)
					{
					adj[i][j] = 1;
					weight[i][j] = i;
					residue[i][j] = weight[i][j];
					}
				}
			else
				{
				if(j-i>0 && j-i<=3)
					{
					adj[i][j] = 1;
					weight[i][j] = i+j;
					residue[i][j] = weight[i][j];
					}
				}	
			}
		}
		
	/*	
	printf("Adjacency Matrix:\n\n");
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			printf("%d ",adj[i][j]);
			}
		printf("\n");	
		}			
		
	printf("Weight Matrix:\n\n");
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			 printf("%d ",weight[i][j]);
			}
		printf("\n");	
		}
	printf("\n");*/
	int m = fordFulkerson(residue,0,n-1,n);
	if(m!=0)printf("Max flow = %d\n",m);
	else if(m==0) printf("Max flow = %d\nNo flow is possible from the source vertex to the sink vertex!\n",m);		
	return 0;
}
