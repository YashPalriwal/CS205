//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment9B.c

//NOTE - If there is no path from i to j dont enter i,j 0 as input
//Assuming graph with parallel edges wont be given as input
//assuming that the maximum number of vertices that are given as input is 100

#include<stdio.h>
#include<stdlib.h>
#define LOW -9999
#define HIGH 9999
#define delta 0.0000001

int maximum_val(float *a,int n,int *visited)//function to get the index of the highest valued element in the array
{
int i;
float max;//max value in the array explored till now
max = LOW;
int max_index = LOW;//index of the max value
for(i=0;i<n;i++)
	{
	if(a[i]>=max && visited[i]!=1){ max = a[i];max_index = i;}
	}
return max_index;	
}

float max(float x,float y)//function to find the maximum of two numbers
{
if(x>=y) return x;
else return y;
}

int main()
{
int v,e,count=0;
printf("Enter the number of vertices: ");
scanf("%d",&v);//Taking input of the number of vertices
printf("Enter the number of edges: ");
scanf("%d",&e);//Taking input of the number of vertices
int i,j,adj_mat[v][v],edge[e][2];
float r[e],val[v][v];
printf("Enter the pair of vertices between which a directed edge is present:\n(NOTE : index starts from 0 not 1)\nINPUT FORMAT - i,j r(if there is a path from i to j and r is the probabilility)\n");
for(i=0;i<v;i++)
	{
	for(j=0;j<v;j++)
		{
		adj_mat[i][j] = 0;//INitializing the adjacency matrix
		val[i][j] = 0;//initializing the probability array
		}
	}
for(i=0;i<e;i++)
	{
	scanf("%d,%d%f",&edge[i][0],&edge[i][1],&r[i]);
	adj_mat[edge[i][0]][edge[i][1]]++;//updating the adjacency matrix
	val[edge[i][0]][edge[i][1]] = r[i];//updating the probability matrix
	}

int start,end;	
printf("Enter the starting vertex: ");
scanf("%d",&start);
printf("Enter the destination vertex: ");
scanf("%d",&end);
int visited[v],index,selection_order[v],k=0;
float vertex_val[v];
for(i=0;i<v;i++)
	{
	vertex_val[i] = LOW;
	visited[i] = 0;
	}
//NOTE : 1 signifies that the vertex is already visited

while(visited[end]!=1)//Applying DIKSTRA'S Algorithm
	{
	if(visited[start]==0)//selecting the start index initially
		{
		visited[start] = 1;//As the start vertex is now visited
		index = start;
		}
	else
		{
		index = maximum_val(vertex_val,v,visited);//selecting the vertex with highest vertex value
		visited[index] = 1;
		
		}
	//printf("Selected Index: %d\n",index);	
	selection_order[k] = index;//Storing the order in which vertices are selected
	k++;	
	if(vertex_val[index]==LOW) vertex_val[index] = 1.0;	
	
	for(i=0;i<v;i++)
		{
		if(adj_mat[index][i]==1 && visited[i]==0)
			{ 
			vertex_val[i] = max(vertex_val[i],(vertex_val[index]*val[index][i]));
			if(i==end) count++;
			//printf("Updated Value of Vertex %d = %f\n",i,vertex_val[i]);
			}
		}	
	}
	 int path[k],c=1;
    	path[0] = end;
    	
    	 if(count==0||vertex_val[end]==0) printf("The destination vertex cannot be reached from the start vertex!\n"); 
	else{
	printf("Most efficient path has a probability of effective communication of %f\n",vertex_val[end]);
	printf("Path followed: ");
	
    i = end;//Tracing the path
    while(1)
    	{
    	if(i==start) break;//when the start vertex is reached break out of the loop
    	else
    		{
    		for(j=0;j<v;j++)//check the ith column of the adjacency matrix
    			{
    			if(adj_mat[j][i]==1 && vertex_val[i] - val[j][i]*vertex_val[j] <= delta && vertex_val[i] - val[j][i]*vertex_val[j]>= -1*delta)
    				{
    				//If the above condition satisfies , it means the index is present in the path
    				path[c] = j;
    				i = j;//update i to converge towards the start index
    				c++;//increase the counter
    				break;
    				}
    			}
    		}
    	
    	}
    
    for(i=c-1;i>=0;i--)//print the path matrix in reverse order to get the desired path
    	{
    	if(i==0) printf("%d\n",path[i]);
    	else printf("%d->",path[i]);
    	}
  }
return 0;
	
}
