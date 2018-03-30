//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment7C.c
#include<stdio.h>
#include<stdlib.h>
#define HIGH 999999

int min(int x,int y)//function to find the minimum value of two numbers
{
if(x<=y) return x;
else return y;
}

int main(void)
{
int n,i,j,k;
printf("Enter the number: ");
scanf("%d",&n);//taking input from the user
int dp[5][n+1],a[5];
a[0] = -1;
a[1] = 7;//Array storing the base case values
a[2] = 5;
a[3] = 3;
a[4] = 2;
for(i=0;i<5;i++) dp[i][1] = 0;//initializing the dp array
for(j=2;j<n+1;j++) dp[0][j] = j-1;

for(i=1;i<5;i++)//BOTTOM-UP APPROACH
	{
	for(j=2;j<n+1;j++)
		{
		if(j%a[i]!=0) dp[i][j] = min(dp[i-1][j],dp[i][j-1]+1);
		else if(j%a[i]==0) dp[i][j] = min(dp[i][j/a[i]] +1,min(dp[i-1][j],dp[i][j-1]+1));
		}
	}
int elements[dp[4][n]];//array storing the path

i = 4;
j = n;
k = 0;
while(1){//Tracing the path
if(j==1) break;
if(dp[i][j]==dp[i][j/a[i]]+1 && j%a[i]==0) {elements[k] = a[i];k++;j = j/a[i];}
else if(dp[i][j]==dp[i-1][j] && j%a[i]==0) {i--;}
else if(dp[i][j]==dp[i][j-1]+1 && j%a[i]==0) {j--;elements[k] = -1;k++;}
else if(dp[i][j]==dp[i-1][j] && j%a[i]!=0) {i--;}
else if(dp[i][j]==dp[i][j-1]+1 && j%a[i]!=0) {j--;elements[k] = -1;k++;}
}
//printf("Path: ");
for(i=1;i<k-1;i++)
{
//printf("%d ",elements[i]);
if(elements[i]==-1&&elements[i+1]==-1) {dp[4][n]--;i++;}
}
//printf("%d",elements[k-1]);
printf("Min Steps required to reach 1 is %d\n",dp[4][n]);
return 0;	
} 
