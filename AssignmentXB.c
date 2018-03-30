//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	AssingmentXB.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define HIGH 99999

int min_index;
int visited[8] = {0};
/*
CHENNAI - 13.0827° N, 80.2707° E
KOLKATA - 22.5726° N, 88.3639° E
INDORE - 22.7196° N, 75.8577° E
BENGALURU - 12.9716° N, 77.5946° E
NAGPUR - 21.1458° N, 79.0882° E
RANCHI - 23.3441° N, 85.3096° E
GUWAHATI - 26.1445° N, 91.7362° E
HYDERABAD - 17.3850° N, 78.4867° E
*/

void distance_calculator(float **distance,float *north,float *east)//returns the areal distance between two cities through their coordinates
	{
	int i,j;
	for(i=0;i<8;i++)
		{
		for(j=i;j<8;j++)
			{
			distance[i][j] = 110.9*(pow((pow((north[i]-north[j]),2)+pow((east[i]-east[j]),2)),0.5));
			distance[j][i] = distance[i][j];
			}
		}

}	

void round_off(float **distance)//rounding off the vlues to the nearest 100
	{
	int i,j,n;
	for(i=0;i<8;i++)
		{
		for(j=0;j<8;j++)
			{
			n = distance[i][j]/100;
			if(distance[i][j]-100*n >= 50)
				distance[i][j] = 100*(n+1);
			else 
				distance[i][j] = n*100;	
			}
		distance[1][2] = 1300;//manually correcting some distances which have variation after rounding off
		distance[2][1] = 1300;
		distance[2][5] = 1000;
		distance[5][2] = 1000;
		distance[2][6] = 1600;
		distance[6][2] = 1600;
		distance[4][6] = 1400;
		distance[6][4] = 1400;
		distance[5][6] = 700;
		distance[6][5] = 700;
		distance[6][7] = 1700;
		distance[7][6] = 1700;	
		}

	}
	
int nearest_dis(float **distance,int index)//function which returns the distance of the place nearest to the place
	{
	int i,min = HIGH;
	for(i=0;i<8;i++)
		{
		if(distance[index][i]<min && visited[i]==0) min = distance[index][i];
		}
	return min;
	}
	
int nearest_index(float **distance,int index)//function which returns the index of the place nearest to it
	{
	int i,min = HIGH,temp;
	for(i=0;i<8;i++)
		{
		if(distance[index][i]<min && visited[i]==0) {min = distance[index][i];temp = i;}
		}
	return temp;
	}		
	
int shortest_path(float **distance,int index)//Using nearest neighbour to fing the shortest path
	{
	int i=0,j,k,min_dis=0,dis = HIGH,temp_index;
	
	j = index;
	visited[j] = 1;
	while(1)
		{
		if(i==7) break;
		else 
			{
			
			min_dis = min_dis + nearest_dis(distance,j);//updating the minimum distance
			i++;//increasing the counter
			j = nearest_index(distance,j);//updating the place by its nearest place
			visited[j] = 1;//updating the visited array
			}
		}
	return min_dis;			
	}	

int main()
	{
	char s[8][20] = {"Chennai","Kolkata","Indore","Bengaluru","Nagpur","Ranchi","Guwahati","Hyderabad"};//Cities in order
	int i,j;
	float **distance;
	distance = malloc(8*sizeof(float*));
	for(i=0;i<8;i++)
		distance[i] = malloc(8*sizeof(float));
	float north[8] = {13.0827,22.5726,22.7196,12.9716,21.1458,23.3441,26.1445,17.3850};
	float east[8] = {80.2707,88.3639,75.8577,77.5946,79.0882,85.3096,91.7362,78.4867};

	distance_calculator(distance,north,east);//filling the distance matrix
	round_off(distance);//rounding off each value in the distance matrix
	
	int min_dis = HIGH,temp;
	for(i=0;i<8;i++)
		{
		temp = shortest_path(distance,i);//calculating the shortest path distance from each vertex/place
		if(temp<min_dis) {min_dis  = temp;min_index = i;}//storing the current shortest path distance
		for(j=0;j<8;j++)
			visited[j] = 0;//again making all entries in the visited matrix as 0
		}
	printf("Shortest Path Distance = %d Km\n",min_dis);
	printf("Path : %s-> ",s[min_index]);
	
	i = 0;
	j = min_index;
	
	visited[j] = 1;
	while(1)//tracing the path by again applying the same process from the index which yields shortest path
		{
		if(i==7) break;
		else if(i==6)
			{
			i++;
			j = nearest_index(distance,j);
			printf("%s\n",s[j]);
			visited[j] = 1;
			}
		else 
			{
			i++;
			j = nearest_index(distance,j);
			printf("%s-> ",s[j]);
			visited[j] = 1;
			}
		}				
	return 0;
	}	
