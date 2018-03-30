//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment9A.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HIGH 1111

float m(float a,float b)//function which gives the minimum of two float values
{
if(a<=b) return a;
else return b;
}

float minimum(float a,float b,float c,float d)//function to find the minimum of 4 float values
{
return m(m(a,b),m(c,d));

}
int diff(int x,int y)//returns the difference between two numbers
{
if(x>=y) return x-y;
else return y-x;
}

int min(int x,int y)//function to find the minimum of two int values
{
if(x<=y) return x;
else return y;
}

int is_neighbour(char *s1,char *s2)//functon which checks if two houses are in neighbourhood or not 
{
int n1,n2,i,j,count=0;
n1 = strlen(s1);//string length of s1
n2 = strlen(s2);
char *temp1,*temp2;
temp1 = malloc(100*sizeof(char));
temp2 = malloc(100*sizeof(char));
strcpy(temp1,s1);//copying elements to the temporary array
strcpy(temp2,s2);
if(diff(n1,n2)!=1) return 0;//if the difference between string lengths is not 1 , they are not neighbours
else
	{	
		for(i=0;i<n1;i++)
			{
			for(j=0;j<n2;j++)
				{
				if(temp1[i]==temp2[j]||temp1[i]-32==temp2[j]||temp1[i]==temp2[j]-32)
					{
					count++;//taking the count of the number of same characters
					break;
					} 
				}
			}
		if(count==min(n1,n2)) return 1;//if count equals the string length of smaller string , they are neighbours
		else return 0;	
	}
}

int pipeline_cost(char *a1,char *a2)//funnction to find out the cost of pipeline between two houses
{
int n1,n2,i,j,count=0;
n1 = strlen(a1);
n2 = strlen(a2);
if(n1>n2)
	{
	for(i=0;i<n1;i++)
		{
		count = 0;
		for(j=0;j<n2;j++)
			{
			if(a1[i]==a2[j] || a1[i]-32==a2[j] || a1[i]==a2[j]-32)
				{
				break;
				}
			else count++;	
			}	
		if(count==n2)return a1[i]; //if the number of same characters equals the string lenght of the shorter string
			
		}
	
	}
else
	{
	for(i=0;i<n2;i++)
		{count = 0;
		for(j=0;j<n1;j++)
			{
			if(a2[i]==a1[j] || a2[i]-32==a1[j] || a2[i]==a1[j]-32)
				{
				break;
				}
			else count++;	
			}	
		if(count==n1)
			{
			return a2[i];
			}	
			
		}
	
	}

}

int main()
{
int n;
printf("Enter the number of houses in the city: ");
scanf("%d",&n);//taking input of the number of houses
int i,j,l,sum=0;
char **a;
float boring[n];
int pipe[n][n];
a = (char**)malloc(n*sizeof(char*));
for(i=0;i<n;i++)
	a[i] = (char*)malloc(100*sizeof(char));
printf("Enter the names of the owner of the %d houses:\n",n);	
for(i=0;i<n;i++)
	{
	scanf("%s",a[i]);
	l = strlen(a[i]);
	for(j=0;j<l;j++)
		{
		sum = sum + a[i][j];
		}
	boring[i] = sum/l;//calculating the cost of boring
	sum = 0;
	}
int neighbour[n][n];

for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		neighbour[i][j] = 0;//Initializing the neighbour matrix
		pipe[i][j] = HIGH;//initializing the pipeline cost
		}
	}

for(i=0;i<n-1;i++)
	{
	for(j=i+1;j<n;j++)
		{
		if(is_neighbour(a[i],a[j])==1)//checking if two houses are neighbour or not
			{
			neighbour[i][j] = 1;
			neighbour[j][i] = 1;
			pipe[i][j] = pipeline_cost(a[i],a[j]);//updating the cost of making pipelines
			pipe[j][i] = pipeline_cost(a[i],a[j]);
			}
		}
	}
	
printf("Cost of boring the houses are : ");	
for(i=0;i<n;i++)
	printf("%0.2f  ",boring[i]);
printf("\n");

printf("Cost of laying pipeline:(-1 for HIGH) \n");	
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		if(pipe[i][j]==HIGH) printf("-1  ");
		else printf("%d  ",pipe[i][j]);
		}
	printf("\n");	
	}
	
	
	
	
float total_cost = 0;	
//To check which houses will have boring	
	
float vertex_val[n];
int index_bored[n];//storing the indexes which will have boring
int water[n];
int supply[n];//storing the indexes which are already supplied with water
for(i=0;i<n;i++)
	{
	vertex_val[i] = HIGH;//initializing the matrices
	index_bored[i] = 0;
	water[i] = 0;
	supply[i] = 0;
	}
 l=0;	
for(i=0;i<n;i++)
	{ l = 0;
	for(j=0;j<n;j++)
		{
		if(neighbour[i][j]==1)
			{
			vertex_val[i] = minimum(vertex_val[i],(boring[i]+pipe[i][j])/2,(boring[j]+pipe[i][j])/2,(boring[i]+boring[j])/2);//Required expression which tells the direction of water flow
			vertex_val[j] = minimum(vertex_val[j],(boring[j]+pipe[j][i])/2,(boring[i]+pipe[j][i])/2,(boring[i]+boring[j])/2);//for two houses
			l++;
			if(vertex_val[i]==(boring[i]+pipe[i][j])/2)
				{
				if(index_bored[i]==0 && water[i] == 0) 
					{
					index_bored[i] = 1;
					water[i] = 1;
					}
				}				
			else if(vertex_val[i]==(boring[j]+pipe[i][j])/2)
				{
				if(index_bored[i]==1) index_bored[i] = 0;
				water[i] = 1;
				}
			else if(vertex_val[i]==(boring[i]+boring[j])/2)	
				{
				if(index_bored[i]==0 && water[i]==0) index_bored[i] = 1;
				water[i] = 1;
				}
			if(vertex_val[j]==(boring[j]+pipe[j][i])/2)
				{
				if(index_bored[j]==0 && water[j]==0) index_bored[j] = 1;
				water[j] = 1;
				}
			else if(vertex_val[j]==(boring[i]+pipe[i][j])/2)
				{
				if(index_bored[j]==1) index_bored[j] = 0;
				water[j] = 1;
				}
			else if(vertex_val[j]==(boring[i]+boring[j])/2)	
				{
				if(index_bored[j]==0 && water[j]==0) index_bored[j] = 1;
				water[j] = 1;
				}	
			}
		
		}
	if(l==0) 
		{
		index_bored[i] = 1;//if a house has no neighbour
		}
	}	
	
for(i=0;i<n;i++)
	{
	supply[i] = index_bored[i];
	}	
l=0;
for(i=0;i<n;i++)
	{
	if(index_bored[i]==1) l++;
	}

		
printf("Index of the houses where boring is present are: ");
for(i=0;i<n;i++)
	if(index_bored[i]==1){ printf("%d ",i);total_cost = total_cost + boring[i];}
printf("\n");
if(l==n) printf("No pipelines are required\n");		
else{	
printf("Following indexed houses would be linked through a pipe:\nNOTE: If (i,j) is linked through pipe , water flows from i to j\n");
int min_cost_pipe,min_index;
int z;
while(1){
z = 0;
for(i=0;i<n;i++)
	{
	min_cost_pipe = HIGH;
	if(supply[i]!=1)
		{
		for(j=0;j<n;j++)
			{
			if(pipe[j][i]!=HIGH && pipe[j][i]<min_cost_pipe && supply[j] == 1) {min_cost_pipe = pipe[j][i];min_index = j;supply[i]=1;}			
			}
		printf("(%d,%d)\n",min_index,i);
		z++;
		total_cost = total_cost + pipe[min_index][i];
		}
	
	}
if(z==0) break;	
	}
}				
printf("Total Cost = %f\n",total_cost);	
		
return 0;
			
}
