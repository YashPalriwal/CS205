//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment11B.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HIGH 999999
#define LOW -99999
#define delta 0.0000001

//Assuming capital and small letters as different things
//Assuming if a character occurs in both the strings twice than it is counted twice in the compare string function
//Assuming if all the localities are not same

int min(int a,int b)
{
	if(a<=b) return a;
	else return b;

}

int maximum_val(int *a,int n,int *visited)//function to get the index of the highest valued element in the array
{
	int i;
	int min;//max value in the array explored till now
	min = HIGH;
	int min_index = LOW;//index of the max value
	for(i=0;i<n;i++)
		{
		if(a[i]<=min && visited[i]!=1){ min = a[i];min_index = i;}
		}
	return min_index;	
}

float max(float x,float y)//function to find the maximum of two numbers
{
if(x>=y) return x;
else return y;
}


int diff(char c1,char c2)//return |a-b|
{
	if(c2-c1>=0) return c2-c1;
	else return c1-c2;
}

int slope(char *s1,char *s2)//function to find the slope of the roads
{
	int n1,n2;
	n1 = strlen(s1);
	n2 = strlen(s2);
	return n2-n1;
}

int compare(char *s1,char *s2)//functon to compare the two strings and check if an edge is present or not
{
	int i,j,n1,n2,m,count=0;
	n1 = strlen(s1);
	n2 = strlen(s2);
	m = slope(s1,s2);
	if(m==1)//checking if the slope is 1 or not
		//ignoring the negative case as we can never use that
		{
		for(i=0;i<n1;i++)
			{
			for(j=0;j<n2;j++)
				{
				if(s1[i]==s2[j]) return 1;
				}
			}
		}
	else if(m==2)
		{
		for(i=0;i<n1;i++)
			{
			for(j=0;j<n2;j++)
				{
				if(s1[i]==s2[j]) {count++;break;}
				}
				if(count>=2) return 1;
			}
		}
	else return 0;		

}

int edge_distance(char *s1,char *s2)//calculating the distance between the localities
{
	int i,j,n1,n2,d=0;
	n1 = strlen(s1);
	n2 = strlen(s2);
	if(n1>=n2)
		{
		for(i=0;i<n1;i++)
			{
			if(i<n2)
				{
				d = d+diff(s1[i],s2[i]);
				}
			else if(i>=n2 && i<n1)
				{
				d = d+s1[i];
				}	
			
			}
		
		}
	else
		{
		for(i=0;i<n2;i++)
			{
			if(i<n1)
				{
				d = d+diff(s1[i],s2[i]);
				}
			else if(i>=n1 && i<n2)
				{
				d = d+s2[i];
				}	
			
			}
		
		}
	return d;	

}



int main()
{
	int i,j,k,n;
	printf("Enter the number of localities: ");
	scanf("%d",&n);//taking input of number of localities
	char **s;
	s = malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		s[i] = malloc(30*sizeof(char));
	printf("Enter the names of the localities:\n");//taking input of names of localities
	for(i=0;i<n;i++)
		scanf("%s",s[i]);
	int start,end;
	int **adj,**distance;//declaring 2D arrays
	adj = malloc(n*sizeof(int*));
	distance = malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		{
		adj[i] = malloc(n*sizeof(int));//allocating memories to the arrays
		distance[i] = malloc(n*sizeof(int));
		}
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			adj[i][j] = 0;//initializng the arrays
			distance[i][j] = HIGH;
			}
		}
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			if(compare(s[i],s[j])==1)//checking if edge is present or not in the DIRECTED GRAPH
				{
				distance[i][j] = edge_distance(s[i],s[j]);
				adj[i][j] = 1;
				}
			}
		}	
		
	int visited[n],index,selection_order[n],count=0;
	int vertex_val[n];
	k = 0;
	for(i=0;i<n;i++)
		{
		vertex_val[i] = HIGH;
		visited[i] = 0;
		}	
	//printf("Enter the start vertex and end vertex:");
	//scanf("%d%d",&start,&end);	
			
	while(1)
		{
		start = rand()%n;
		end = rand()%n;
		if(start!=end)
			{
			while(visited[end]!=1)//Applying DIKSTRA'S Algorithm
				{
				if(visited[start]==0)//selecting the start index initially
					{
					visited[start] = 1;//As the start vertex is now visited
					index = start;
					}
				else
				{
				index = maximum_val(vertex_val,n,visited);//selecting the vertex with highest vertex value
				visited[index] = 1;
		
				}
				//printf("Selected Index: %d\n",index);	
				selection_order[k] = index;//Storing the order in which vertices are selected
				k++;	
				if(vertex_val[index]==HIGH) vertex_val[index] = 0;	
	
				for(i=0;i<n;i++)
					{
					if(adj[index][i]==1 && visited[i]==0)
						{ 
						vertex_val[i] = min(vertex_val[i],(vertex_val[index]+distance[index][i]));
						//if(i==y) count++;
						//printf("Updated Value of Vertex %d = %f\n",i,vertex_val[i]);
						}
					}	
				}
			
			break;
			}
		}
		if(vertex_val[end]==HIGH) printf("It is not possible to reach %s from %s\n",s[end],s[start]);
		else printf("Shortest distance of %s from %s is %d\n",s[end],s[start],vertex_val[end]);
		
		
		int path[k],c=1;
    		path[0] = end;
		printf("Path followed: ");
	
    	i = end;//Tracing the path
    	while(1)
    		{
    		if(i==start) break;//when the start vertex is reached break out of the loop
    		else
    			{
    			for(j=0;j<n;j++)//check the ith column of the adjacency matrix
    				{
    				if(adj[j][i]==1 && vertex_val[i] == vertex_val[j] + distance[j][i])
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
		
	return 0;
}
