//NAME - YASH PALRIWAL
//ROLL NUmBER - 1601CS50
//	Assignment8C.c

//Assuming that the number of vertices donot exceed 100
//Also considering the case for self-loops and parallel edges
#include<stdio.h>
#include<stdlib.h>
int sum = 0;//global counter storing maximum number of edges found in any connected component so far
int count = 0;//global counter storing the count of number of edges in the connected component in which we are using DFS 
 
void DFS(int i,int **a,int *visited,int n);//Depth First Search

int main()
{
    int i,j,n,e;
    printf("Enter number of vertices:");
    scanf("%d",&n);//Taking input of the number of vertices
    int **adj_matrix,visited[n];//visited array stores value 1 for the vertex already visited else it stores 0
     
     adj_matrix = malloc(n*sizeof(int*));
     for(i=0;i<n;i++)
     	adj_matrix[i] = malloc(n*sizeof(int));
     
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            adj_matrix[i][j] = 0;//initializing the adjecency matrix
            
    printf("Enter the total number of edges: ");
    scanf("%d",&e); //Taking input of the number of edges
    int edge[e][2];
    printf("Enter the index pairs between which an edge is present:\n(NOTE: first element has 0 index not 1)\nINPUT FORMAT - i,j\n");
    for(i=0;i<e;i++)
    	{
    	scanf("%d,%d",&edge[i][0],&edge[i][1]); //Taking input of the vertex pairs which have a direct edge between them 
   	adj_matrix[edge[i][0]][edge[i][1]]++;//updating the adjacency matrix
   	adj_matrix[edge[i][1]][edge[i][0]]++;
    	}
 
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
        i=0;
while(1){
for(i=0;i<n;i++){
   if(visited[i]==0)
   	{DFS(i,adj_matrix,visited,n);
   	//printf("\n");
   	if(count/2>sum) sum = count/2;//UPdating sum whenever a connected component visited just now has more number of edges than any previously visited connected component
   	count = 0;//again initializing the global counter to 0 for next connected component
   	continue;
   	}
   }	
    printf("Maximum number of edges in any connected component = %d\n",sum);
    return 0; 
     
   }
  
}
 
void DFS(int i,int **a,int *visited,int n)
{
    int j;
    //printf("%d\n",i);
    visited[i]=1;
    for(j=0;j<n;j++)
    	count  = count + a[i][j];//taking the sum of degrees of all the vertices present in a connected component
    for(j=0;j<n;j++)
       if(!visited[j]&&a[i][j]>=1)//when vertex is not visited and their exists a direct edge to reach it 
            {DFS(j,a,visited,n);}//recurrsive call
}
