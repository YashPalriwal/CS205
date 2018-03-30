//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50	
//  	Assign6B.c
#include<stdio.h>
#include<stdlib.h>

int min(int x,int y)//function to get the minimum value of two numbers
{
if(x<=y) return x;
else return y;
}

int minimum(int x,int y,int z)//function to get the minimum value of 3 numbers
{
return min(min(x,y),z);
}

int main(void)
{
int row,col,i,j;
printf("Enter the size of the puzzle room(row  col): ");
scanf("%d%d",&row,&col);
int val[row][col];
printf("Enter the values in the matrix: \n");
for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
		{
		scanf("%d",&val[i][j]);
		}
	}

int min[row][col];//it is the 2D array which stores the minimum cost to reach (i,j)th element at its (i,j)th index 
min[0][0] = val[0][0];//minimum value to reach (0,0) is the value in val[0][0]
		      //since we can move only diagonally,horizontally or downward	
for(j=1;j<col;j++) min[0][j] = min[0][j-1] + val[0][j];//minimum value to reach (0,j)th index is the sum of all val[0][i] for all i<j
for(i=1;i<row;i++) min[i][0] = min[i-1][0] + val[i][0];//minimum value to reach (i,0)th index is the sum of all val[j][0] for all j<i
for(i=1;i<row;i++)
	{
	for(j=1;j<col;j++)//for all other elements the minimum value is the minimum of (diagonal,left,top) element + the value at val[i][j]
		{
		min[i][j] = val[i][j] + minimum(min[i-1][j],min[i][j-1],min[i-1][j-1]);
		}
	}

printf("\nTotal Cost = %d\n",min[row-1][col-1]);
int path[row*col];//temporary array of sufficient size
i = row-1;
j = col -1;
int k = 0;//counter to store the number of required moves
//0 for downward move
//1 for horizontal move
//2 for diagonal move

while(1)
{
if(i==0&&j==0) break;//to break the loop when we reach the start element
if(i!=0 && j!=0)
	{
	if(min[i-1][j-1] == minimum(min[i][j-1],min[i-1][j],min[i-1][j-1])){ path[k] = 2;i--;j--;k++;}//since we are traversing the loop backward we have to store the moves in a temporary array
	else if(min[i][j-1] == minimum(min[i][j-1],min[i-1][j],min[i-1][j-1])){ path[k] = 1;j--;k++;}
	else if(min[i-1][j] == minimum(min[i][j-1],min[i-1][j],min[i-1][j-1])){ path[k] = 0;i--;k++;}
	}
else if(i==0 && j!=0)//when i==0 , there is no top or diagonal element present
	{
	path[k] = 1;
	k++;
	j--;
	} 
	
else if(j==0 && i!=0)//when j==0 , there is no left or diagonal element present
	{
	path[k] = 0;
	k++;
	i--;
	} 	
}
printf("Number of moves req: %d\n",k);
printf("Required Moves : ");
for(i=k-1;i>=0;i--)//again traversing the temporary array backward to get the correct sequence of moves
{
if(path[i]==2) printf("diagonal  ");
else if(path[i]==1) printf("horizontal  ");
else if(path[i]==0) printf("downward  ");
}
printf("\n");				
return 0;
}
