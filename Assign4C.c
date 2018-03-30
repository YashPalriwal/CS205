//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assign4C.c

#include<stdio.h>
#include<stdlib.h>



int main(void)
{
int n,i,j,k;
printf("Enter the size of square matrix(Format -> n = 2^k): ");
scanf("%d",&n);

int **a, **b, **c;

a = (int**)calloc(n,sizeof(int*));
b = (int**)calloc(n,sizeof(int*));
c = (int**)calloc(n,sizeof(int*));

for(i=0;i<n;i++)
	{
	*(a+i) = (int*)calloc(n,sizeof(int));
	*(b+i) = (int*)calloc(n,sizeof(int));
	*(c+i) = (int*)calloc(n,sizeof(int));
	}
printf("Enter the values in the matrices\n(Input format for n==2):\n");
printf("a b\nc d\n");
printf("\nMatrix 1: \n");
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
printf("\nMatrix 2: \n");
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		scanf("%d",&b[i][j]);
		}
	}

printf("\nMAtrix 1 * Matrix 2:\n");

for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		for(k=0;k<n;k++)
			{
			c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		printf("%d ",c[i][j]);
		}
		printf("\n");
	}	

}




