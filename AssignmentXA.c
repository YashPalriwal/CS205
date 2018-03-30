//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	AsignmentXA.c

//Assuming small letters and capital letters are different

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HIGH 99999

int diff(int a,int b)//returns |a-b|
	{
	if(a>=b) return a-b;
	else return b-a;
	}

int ascii_sum(char *s1)
	{
	int i,sum = 0;
	for(i=0;i<5;i++)
		sum = sum + s1[i];
	return sum;	
	}

int edge_weight(char *s1,char *s2)//calcutes the weight of edge 
	{
	int i,sum = 0;
	for(i=0;i<5;i++)
		{
		sum = sum + diff(s1[i],s2[i]);
		}
	return sum;	
	}

void compare(int **adj_mat,char *s1,char *s2,int i1,int i2,int **weight)
	{
	int i,j,count = 0;
	for(i=0;i<5;i++)
		{
		if(s1[i]==s2[i]) count++;
		}
	if(count==4) //if edge is present
		{
		adj_mat[i1][i2] = 1;//updating the adjacency matrix
		adj_mat[i2][i1] = 1;
		weight[i1][i2] = edge_weight(s1,s2);//calculating the weight of edge and then updating the weight matrix
		weight[i2][i1] = weight[i1][i2];
		}	
	}
	
void FloydWarshal(int **weight,int **shortest_path,int n)//Algo to find all pair shortest path in O(V^3) time
	{
	int i,j,k;
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			shortest_path[i][j] = weight[i][j];
			}
		}
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			for(k=0;k<n;k++)
				{
				if (shortest_path[i][k] + shortest_path[k][j] < shortest_path[i][j])
                    			{
                    			shortest_path[i][j] = shortest_path[i][k] + shortest_path[k][j];
                    			//shortest_path[j][i]  = shortest_path[i][j];
                    			}
				}
			}
		}
	
	}	

int main()
	{
	int i,j,n,d;
	printf("Enter the number of students in the institute: ");
	scanf("%d",&n);
	char **names;
	names = malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		names[i] = malloc(5*sizeof(char));
	printf("Enter the names of the students:\n");
	for(i=0;i<n;i++)
		scanf("%s",names[i]);//taking input of the names
	printf("Enter the threshold distance: ");
	scanf("%d",&d);	
		
	int **adj_mat,**weight,**shortest_path;
	adj_mat = malloc(n*sizeof(int*));//allocing memory to the double pointers
	weight = malloc(n*sizeof(int*));
	shortest_path = malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		{
		adj_mat[i] = malloc(n*sizeof(int));
		weight[i] = malloc(n*sizeof(int));
		shortest_path[i] = malloc(n*sizeof(int));
		} 
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			weight[i][j] = HIGH;//initializing the weight matrix
			}	
		}	
	for(i=0;i<n-1;i++)
		{
		for(j=i+1;j<n;j++)
			{
			compare(adj_mat,names[i],names[j],i,j,weight);//checking which vertices have edges between them
			}
		}
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			if(adj_mat[i][j]==1)
				{
				if(ascii_sum(names[i])>ascii_sum(names[j]))
					{
					adj_mat[j][i] = 0;
					weight[j][i] = HIGH;
					}
				else 
					{
					adj_mat[i][j] = 0;
					weight[i][j] = HIGH;
					}	
				}
			}
		}	
		
	FloydWarshal(weight,shortest_path,n);
	
	printf("\nWeight Matrix for the directed graph:\n\n");//printing the weight matrix
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			if(i==j) printf("0   ");
			if(weight[i][j]==HIGH) printf("-1   ");
			else printf("%d   ",weight[i][j]);
			}
		printf("\n");	
		}	
	
	printf("\nShortest Path matrix for the directed graph:\n\n");//printing the shortest path matrix
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			if(i==j) printf("0   ");
			else if(shortest_path[i][j]==HIGH) printf("-1   ");
			else printf("%d   ",shortest_path[i][j]);
			}
		printf("\n");	
		}
	
	int k=0;	
	printf("\nList of Users and the accounts which they can access:\n\n");
	for(i=0;i<n;i++)
		{k=0;
		for(j=0;j<n;j++)
			{
			if(i==j && k==0){printf("User '%s' can access the account of -> '%s'  ",names[i],names[j]);k++;}
			else if(i==j && k!=0)  {printf("'%s'  ",names[j]);k++;}
			if(shortest_path[i][j]<d) //Checking the necessary condition
				{
				if(k==0)printf("User '%s' can access the account of -> '%s'  ",names[i],names[j]);
				 else printf("'%s'  ",names[j]);
				 k++;
				}
				
			}
		printf("\n");	
		}						
	return 0;
	}	
