//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//      Assignment8A.c

//Assuming the maximum number of players is 100
#include<stdio.h>
#include<stdlib.h>
#define RED -1//assigning values to colours 
#define BLUE 2

int main(void)
{
int n,r;
printf("Enter the total number of players: ");//total number of players
scanf("%d",&n);
printf("Enter the number of pair of players having rivalry: ");//pair of players having rivalry 
scanf("%d",&r);
int index[r][2],i,j,color[n];
printf("Enter the player numbers having rivalry: \nINPUT FORMAT : i,j\n");
for(i=0;i<r;i++)
    {
    scanf("%d,%d",&index[i][0],&index[i][1]);//storing the player numbers having rivalry in the index array
    index[i][0]--;
    index[i][1]--;// converting player numbers to player index by reducing 1 
    }
   int adj_list[n][n];//creating an adjacency list
    for(i=0;i<n;i++)
    {   color[i] = 0;//initializing the color array
      for(j=0;j<n;j++)
        {
        adj_list[i][j] = 0;//initialing the adjacency list
        }
    }
    for(i=0;i<r;i++)
    {
    adj_list[index[i][0]][index[i][1]] = 1;
    adj_list[index[i][1]][index[i][0]] = 1;//updating the adjacency list whenever an edge is found between two vertices
    }
     for(i=0;i<n;i++)//Checking if the graph is bipartite or not 
        {  if(color[i]==0) color[i] = RED;//Assigning color to a player if not assigned already
        for(j=0;j<n;j++)
            {
            if(adj_list[i][j]==1) 
                    {
                    if(color[i]==RED && color[j]!=RED) color[j] = BLUE;//updating the color array
                    else if(color[i]==RED && color[j]==RED){printf("NOT POSSIBLE!\n");return 0;}//whenever two adjacent vertices have the same color
                    if(color[i]==BLUE && color[j]!=BLUE) color[j] = RED;
                    else if(color[i]==BLUE && color[j]==BLUE){printf("NOT POSSIBLE!\n");return 0;}
                    
                    }
            }
    
        }
      printf("Members of team1 are : "); 
     for(i=0;i<n;i++)
        {
        if(color[i]==RED) printf("%d ",i+1);//All the players assigned RED belong to the same team
        }   
     printf("\nMembers of team2 are: ");
        for(i=0;i<n;i++)
        {
        if(color[i]!=RED) printf("%d ",i+1);//All the players assigned BLUE belong to one team
        }
        printf("\n");
   return 0; 
}
