#include<stdio.h>
#include<stdlib.h>

int a[50];

int finding_median(int array[],int n,int m);

int main(void)
{
int n,m,median,i;
printf("Enter the size of the array: ");
scanf("%d",&n);
if(n<=0){printf("Size of the array must be greater than 0\n");return 0;}
int array[n];
for(i=0;i<n;i++)
	{
	scanf("%d",&array[i]);
	a[i] = array[i];
	}
if(n%2==0)m = n/2;
else m = (n+1)/2;
median = finding_median(array,n,m);
printf("Median = %d\n",median);
return 0;
}

int finding_median(int array[],int n,int m)
{
int r,i,j=0,k=0;
r = rand()%n;
printf("random no. = %d",r);
int left[n],right[n];



for(i=0;i<n;i++)
	{
	if(array[i]<array[r])
		{
		left[j] = array[i];
		j++;		
		}
	else if(array[i]>array[r])
		{
		right[k] = array[i];
		k++;
		}
	}
printf(" , j = %d , k = %d\n",j,k);
if(r==m && j>=m) return left[m-1];
else if(r==m && k>=m) return right[m-1];


if(j>=m) {n = j;return finding_median(left,n,m);}
else if(k>=m) 
	{
	n = k;
	if(m-j-1==0)return array[r];
	else{ m = m-j-1;
	
	return finding_median(right,n,m);}
	}
else if(j==k) return array[r];

if(r!=m && m>k && m>j){m = j;n = j;return finding_median(left,n,m);}



}
