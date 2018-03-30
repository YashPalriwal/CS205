//NAME - YASH PALRIWAL
//ROLL NUMBE - 1601CS50
//	Assignment9C.c

//Assuming that the number of localities donot exceed 100
//Assuming the upper bound to deliver pizza is 30 minnutes
//Assuming that we have to cover all the localities such that delivery takes place within 30 minutes
//Applying GREEDY APPROACH to establish dominoes in different localities
//The locality with the highest number of neighbours will be selected first

#include<stdio.h>
#include<stdlib.h>
#define HIGH 9999

float min(float x,float y)//function which returns the minimum value of the two floating point numbers
{
if(x<=y) return x;
else return y;
}

int max_degree(int **a,int n)//function which returns the vertex with highest degree
{
int i,j,sum=0,max=0,index = -1;
for(i=0;i<n;i++)
	{
	sum = 0;
	for(j=0;j<n;j++)
		{
		if(a[i][j]!=-1)sum = sum + a[i][j];
		}
	if(sum>max){ max = sum;index = i;}	
	
	}
return index;//returns -1 when no more vertices are left	

}

void update_mat(int **a,int n,int index,float *time,float **distance,float **traffic,int *reachable)//to update a temporary adjacency matrix
{
int i,j;
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		
		if(j==index || i==index) 
			{
			if(distance[i][j]*traffic[i][j]<=30 && a[i][j]==1) //if an edge is present and the time is within bounds
				{
				if(i==index) {time[j] = min(time[j],distance[i][j]*traffic[i][j]);time[i] = 0;reachable[j] = 1;a[i][j] = -1;}//update all the matrices
				else if(j==index) {time[i] = min(time[i],distance[i][j]*traffic[i][j]);time[j] = 0;reachable[i] = 1;a[i][j] = -1;}
				}
			else 
				a[i][j] = -1;//deletes the vertex with highest degree	
			}
		}
	}

}

int main()
{
int n,i,j;
printf("Enter the number of localities(vertices): ");
scanf("%d",&n);
int e;
printf("Enter the number of roads(edges): ");
scanf("%d",&e);

float **distance,**traffic;//2D array for traffic and distance
int **adj,adj_mat[n][n];//adjacency matrices
adj = malloc(n*sizeof(int*));
for(i=0;i<n;i++)
	adj[i] = malloc(n*sizeof(int));

distance = malloc(n*sizeof(float*));
for(i=0;i<n;i++)
	distance[i] = malloc(n*sizeof(float));
traffic = malloc(n*sizeof(float*));
for(i=0;i<n;i++)
	traffic[i] = malloc(n*sizeof(float));
if(e>0){	
printf("Enter the index of the localities which have a path between them , traffic at that path , distance between the localities: \n");
printf("NOTE - Traffic varies from 0.5 to 2 and index starts from 0\n");
printf("Input format - i,j traffic[i][j] distance[i][j]\n");			
int edge[e][2];

for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		adj_mat[i][j] = 0;//Initializing the 2D arrays
		adj[i][j] = 0;
		traffic[i][j] = HIGH;
		distance[i][j] = HIGH;
		}
	}	
	
for(i=0;i<e;i++)
	{//taking input of the path with traffic and distance 
	scanf("%d,%d",&edge[i][0],&edge[i][1]);
	scanf("%f%f",&traffic[edge[i][0]][edge[i][1]],&distance[edge[i][0]][edge[i][1]]);
	traffic[edge[i][1]][edge[i][0]] = traffic[edge[i][0]][edge[i][1]];//updating the traffic matrix
	distance[edge[i][1]][edge[i][0]] = distance[edge[i][0]][edge[i][1]];//updating the distance matrix
	adj_mat[edge[i][1]][edge[i][0]] = 1;//updating the adjacency matrix
	adj_mat[edge[i][0]][edge[i][1]] = 1;
	adj[edge[i][1]][edge[i][0]] = 1;
	adj[edge[i][0]][edge[i][1]] = 1;
	}
      }
int visited[n];//matrix which stores the index where dominoes is established
int *reachable;//matrix which stores the indexes which are reachable from the dominoes within the limited time period
float *time;//stores the minimum time taken to reach a locality from any established dominoes

time = malloc(n*sizeof(float));
reachable = malloc(n*sizeof(int));
for(i=0;i<n;i++)
	{
	visited[i] = 0;//Initializing the matrices
	reachable[i] = 0;
	time[i] = HIGH;
	}
while(1)//GREEDY APPROACH
	{
	i = max_degree(adj,n);//finding the vertex with highest degree and establishing Dominoes there and then deleting the vertex
	if(i==-1) break;//break when all vertices are reachable
	else {visited[i] = 1;time[i] = 0;reachable[i] = 1;update_mat(adj,n,i,time,distance,traffic,reachable);}//Else update the matrices
	}
for(i=0;i<n;i++)
	{
	if(reachable[i]==0) {visited[i] = 1;reachable[i] = 1;}//if dominoes is present in a locality , it is obviously reachable
	}	
printf("Dominoes will be established in the following indexed localities such that the whole city is covered: ");	
for(i=0;i<n;i++)
	{
	if(visited[i]==1) {printf("%d ",i);time[i] = 0;}//Assuming time taken to deliver pizza to the same locality is 0
	}
printf("\n");
int destination;
printf("Enter the destination vertex: ");
scanf("%d",&destination);//Taking input of the destination vertex
printf("Time taken to deliver pizza = %0.2f\n",time[destination]);//minimum time taken to deliver the pizza
int path[n],k=0;
if(time[destination]==0) printf("(Time is 0 since dominoes is present in the same locality)\n");
else 
	{
	i = destination;//Backtrackking the path
	path[0] = destination;
	k++;
	while(1)
		{
		if(visited[i]==1) break;//if a dominoes is found
		else 
			{
			for(j=0;j<n;j++)
				{
				if(adj_mat[i][j]==1 && time[i] == time[j] + distance[i][j]*traffic[i][j]) 
					{
					path[k] = j;
					k++;
					i = j;
					break;
					}
				}
			}
		}
	path[k] = i;//Adding the dominoes location
	printf("Path followed : ");
	for(i=k-1;i>=0;i--)//printing the path matrix in reverse order to get the required path
		{
		if(i==0) printf("%d\n",path[i]);
		else printf("%d->",path[i]);
		}	
	}				
return 0;
}
