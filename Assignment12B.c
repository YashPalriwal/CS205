//NAME - YASH PALRIWAL
//ROLL NUMBER- 1601CS50
//	Assignment12B.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HIGH 9999999

int min(int a,int b)//function to find the minimum  of two numbers
{
	if(a<=b) return a;
	else return b;
}

int compare(char *s1,char *s2)//function to compare two city names
	{
	int n1,n2,i,j,count=0;//to check if their is an edge between them or not
	n1 = strlen(s1);
	n2 = strlen(s2);
	char temp1[30],temp2[30];//creating temporary arrays
	strcpy(temp1,s1);
	strcpy(temp2,s2);
	for(i=0;i<n1;i++)
		{
		for(j=0;j<n2;j++)
			{
			if(temp1[i]==temp2[j])//required condition
				{
				count++;
				temp2[j] = '0';//so that same character is not counted twice
				break;
				}
			}
		}
	return 2*count;//returns the capacity of the edge between i and j
			//returns 0 if no edge is present or no characters are common
	
	}

int Queue(int start,int *parent,int **residue,int n)//Maintaining the required Queue
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
	
int Max_flow_algo(int** rgraph, int s, int t,int n)//Algorithm to find the max-flow
{
    int u, v;
    int parent[n];
 
    int max_flow = 0; 
    while (Queue(s,parent,rgraph,n))//while there are still elements present in the queue
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

int main()//main function
{
	char city[72][30]={   "goa",          //assigning the city names in the array
			"mumbai", "delhi","bangalore", "hyderabad", "ahmedabad", "chennai",
			"kolkata", "surat",
			"pune", "jaipur", "lucknow", "kanpur", "nagpur", "visakhapatnam",
			"indore", "thane", "bhopal", "patna",
			"vadodara", "ghaziabad", "ludhiana", "coimbatore", "agra", "madurai",
			"nashik", "faridabad", "meerut",
			"rajkot", "varanasi", "srinagar", "aurangabad", "dhanbad"," amritsar",
			"navimumbai", "allahabad",
			"ranchi", "howrah", "jabalpur", "gwalior", "vijayawada", "jodhpur",
			"raipur", "kota", "guwahati",
			"chandigarh", "solapur", "tiruchirappalli",
			"bareilly", "moradabad", "mysore",
			"tiruppur", "gurgaon", "aligarh", "jalandhar", "bhubaneswar", "salem",
			"warangal", "guntur", "bhiwandi",
			"saharanpur", "gorakhpur", "bikaner", "amravati", "noida", "jamshedpur",
			"bhilai", "cuttack", "firozabad",
			"kochi", "thiruvananthapuram"};
	int i,j,n=71;
	
	int **adj,**rgraph;//declaring the 2D arrays
	adj = (int**)calloc(n,sizeof(int*));//allocating memory to the arrays
	rgraph = (int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)//also initializing all the elements ass 0
		{
		adj[i] = calloc(n,sizeof(int));
		rgraph[i] = calloc(n,sizeof(int));
		}
	for(i=0;i<n;i++)//nested loop to compare all pair of city names
		{
		for(j=0;j<n;j++)
			{
			if((strlen(city[j]) - strlen(city[i]))==1)//if |Y|-|X|==1
				{
				rgraph[i][j] = compare(city[i],city[j]);//comparing the two strings and assigning the edge capacity
				if(rgraph[i][j]!=0) adj[i][j] = 1;//if edge capacity > 0
				}
			}
		}
	int count = 0;	//Taking care of the exceptional GOA case
	for(i=0;i<n;i++)//if a vertex is not reachable
		{count=0;
		for(j=0;j<n;j++)
			{
			if(adj[j][i]==0) count++;
			else break;
			}
		if(count==n && i!=j)
			{
			adj[0][i] = 1;//connecting it to city GOA
			rgraph[0][i] = 20;//with edge capacity 20
			}	
		}	
		
	for(i=0;i<n;i++)//Taking care of the exeptional THIRUVANANTHPURAM case
		{count=0;
		for(j=0;j<n;j++)//if a vertex cant lead to another vertex
			{
			if(adj[i][j]==0) count++;
			else break;
			}
		if(count==n && i!=j)
			{
			adj[i][n-1] = 1;//connecting it to THIRUVANANTHPURAM
			rgraph[i][n-1] = 20;//with edge capacity 20
			}	
		}
		
	int m = Max_flow_algo(rgraph,0,n-1,n);//storing the maximum flow
	printf("Maximum flow = %d\n",m);//printing the result;
	return 0;			
}





