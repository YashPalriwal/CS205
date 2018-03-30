//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment12A.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HIGH 999999

int compare(char *company_name,char *student)//function to compare if a student is ellgible for a company or not
{
int count = 0,i,j,n1,n2;
n1 = strlen(company_name);
n2 = strlen(student);
char temp1[n1],temp2[n2];
strcpy(temp1,company_name);
strcpy(temp2,student);
for(i=0;i<n1;i++)//loop to count the number of same characters
	{
	for(j=0;j<n2;j++)
		{
		if((temp1[i]==temp2[j] || temp1[i]+32==temp2[j] || temp1[i]-32==temp2[j])&&temp2[j]!='0')
			{
			count++;
			temp2[j] = '0';
			break;
			}
		}
	}
if(count>=2) return 1;//condition for the candidate to be eligible	
else return 0;	

}

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
int i,j;
char company[19][30]  = 	{"Microsoft","Google","Adobe","MentorGraphics","Synopsis","IBM","Wipro","TCS","CTS","Goldman","Infosys","Cadence","TexasInstrument","DRDO","HAL","ISRO","Capgemini","Ushacomm","Ericson"};	
	
int n;
printf("Enter the number of candidates applying for job: ");
scanf("%d",&n);//taking input of the number of candidates

int **adj;
adj = (int**)calloc((n+21),sizeof(int*));
for(i=0;i<(n+21);i++)
	adj[i] = (int*)calloc((n+21),sizeof(int));

int **rgraph;
rgraph = (int**)calloc((n+21),sizeof(int*));
for(i=0;i<(n+21);i++)
	rgraph[i] = (int*)calloc((n+21),sizeof(int));//taking input of the residue graph

char **names;
names = malloc(n*sizeof(char*));
for(i=0;i<n;i++)
	names[i] = malloc(40*sizeof(char));
printf("Enter the names of the candidates:\n");
for(i=0;i<n;i++)
	{
	scanf("%s",names[i]);	
	for(j=0;j<19;j++)
		{
		if(compare(company[j],names[i])==1) {adj[i+1][j+n+1] = 1;rgraph[i+1][j+n+1] = 1;}//updating the adj matrix and rgraph
		}
	}
for(i=0;i<n;i++)//connecting all the candidates to the source vertex
	{adj[0][i+1] = 1;	
	rgraph[0][i+1] = 1;
	}
for(i=n+1;i<(n+20);i++)//connecting all the companies to the sink vertex
	{adj[i][n+20] = 1;
	rgraph[i][n+20] = 1;
	}	

int m = fordFulkerson(rgraph,0,n+20,n+21);//using ford fulkerson algorithm to find the max flow
printf("\nMaximum number of placements = %d\n",m);	
if(m>0){printf("\nFollowing companies will take the indicated students:\n\n");

for(i=1;i<=n;i++)//finding the path between the company and students
	{
	for(j=n+1;j<n+20;j++)
		{
		if(adj[i][j] == 1 && rgraph[i][j]!=1)
			{
			printf("%s -> %s\n",company[j-n-1],names[i-1]);
			}
		}
	}
    }	
return 0;		
}
