//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
// 	Assignment8B.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find_column(int **a,int n);//function which returns the index of column with all zeroes

int** remove_index(int **a,int n,int index);//reducing the 2D array by deleting ith row and column

int cycle_test(int **a,int n)//recurrsive function to check if a directed graph is cyclic or not
{			     //start by removing the vertex wgich can't be reached and also delete all the edges incident on it
int i,j,index,count=0;	     
if(n==0) {return 0;}         //if u r able to remove all the vertices , the graph is ACYCLIC
else
	{
	index = find_column(a,n);//finding the inddex with all zeroes
	if(index==-1) {return 1;}//GRAPH is CYCLIC if no index is fouond
	a = remove_index(a,n,index);//modifying 2D array a
	cycle_test(a,n-1);//recurrsive call
	}

}

int compare(char *s1,char *s2)//function to check if edge is present between two nodes or not
{
int i,j,sum=0,absent = 0;
char temp1[5],temp2[5];//temporary arrays
strcpy(temp1,s1);//copying elements in the temporary array 
strcpy(temp2,s2);
for(i=1;i<5;i++)//starting the loop from i = 1 as we have to remove the first character
		{
		sum = 0;
		for(j=0;j<5;j++)
		    {
		    if(temp1[i]==temp2[j]) 
		    	{
		    	sum++;
		    	if(sum==1)temp2[j] = '0';//for handling the case with multiple same characters
		    	
		    	}
		    }
		if(sum==0) {absent++;return 0;} //if even 1 character is extra in temp1 there is no edge between temp1 & temp2   
		}
	if(absent==0) return 1;	//If all the characters present in temp1 are also present in temp2 there will be an edge between temp1 & temp2
}

int main()
{
int n,i,j,res;
printf("Enter the number of words: ");
scanf("%d",&n);//Taking input of number of words from the user
int **adj_list;//Adjacency matrix
adj_list = malloc(n*sizeof(int*));
for(i=0;i<n;i++)
    adj_list[i] = malloc(n*sizeof(int));
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		adj_list[i][j] = 0;//Initializing the adjacency matrix
		}
	}
	
char **a;// 2D array storing the words
a = malloc(n*sizeof(char*));
for(i=0;i<n;i++)
    a[i] = malloc(5*sizeof(char));
printf("Enter the words: ");
for(i=0;i<n;i++)
	{
	scanf("%s",a[i]);//taking input of words from the user
	}
for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
		{
		if(compare(a[i],a[j])==1) adj_list[i][j] = 1;//checking if there is an edge between i & j
		if(compare(a[j],a[i])==1) adj_list[j][i] = 1;//Since the GRAPH is DIRECTED , considering swapped indexes also		
		}
	}	
printf("\nb.>> Matrix representing if there is an edge/path between pair (i,j): \n(NOTE: '0' means 'NO' and '1' means 'YES')\n");	
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		printf("%d ",adj_list[i][j]);
		}
	printf("\n");
    }
 res = cycle_test(adj_list,n); //Checking whether the graph is CYCLIC or not
 
 if(res==0) printf("\na.>> GRAPH IS ACYCLIC\n");
 else if(res==1) printf("\na.>> GRAPH IS CYCLIC\n");
   
    return 0;
}

int find_column(int **a,int n)
{
int i,j=0,index,count=0;
for(j=0;j<n;j++)
	{count=0;
	for(i=0;i<n;i++)
		{
		if(a[i][j]==0) count++;
		}
	if(count==n) return j;	
	}
return -1;//When no such column found	
}

int** remove_index(int **a,int n,int index)
{
int **temp,i,j;
temp = malloc((n-1)*sizeof(int*));
for(i=0;i<n-1;i++)
	temp[i] = malloc((n-1)*sizeof(int));
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		if(i!=index && j!=index)//not copying ith row and column
			{
			if(i<index && j<index) temp[i][j] = a[i][j];//Taking care of the indexes
			else if(i>index && j<index) temp[i-1][j] = a[i][j];
			else if(i<index && j>index) temp[i][j-1] = a[i][j];
			else if(i>index && j>index) temp[i-1][j-1] = a[i][j];
			}
		}
	}
return temp;//returning modified 2D array	
}


