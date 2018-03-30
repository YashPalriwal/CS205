//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment6C.c
#include<stdio.h>
#include<stdlib.h>
#define low  1000000 

void swap(int *x,int *y)//function to swap two numbers
{
int temp = *x;
*x = *y;
*y = temp;

}

int diff(int x,int y)//function which returns |x-y| i.e. their difference
{
int temp;
temp  = x-y;
if(temp>=0) return temp;
else return -1*temp;

}

int m(int x,int y)//function which returns the minimum of two numbers
{
if(x<=y) return x;
else return y;
}

int minimum(int x,int y,int z)//function which returns minimum of 3 numbers
{
return m(m(x,y),z);
}

int partition(int *a,int p,int r)//partition function to apply quicksort
{
int i = p-1,j;
for(j=p;j<r;j++)
	{
	if(a[j]<=a[r])
		{
		i = i+1;
		swap(&a[i],&a[j]);
		}
	
	}
swap(&a[i+1],&a[r]);
return i+1;
}

void quicksort(int *a,int p ,int r)//function to sort the array
{
int q;
if(p<r)
	{
	q = partition(a,p,r);
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);	
	}


}

int main(void)
{
int n,i,j;
printf("Enter the number of elements: ");
scanf("%d",&n);//number of elements taken input from user
int min[n+1],a[n],sum=0,count[n];//count[n] is the array which stores 0 or 1 for every element which indicates whether the element is selected or not
printf("Enter the elements(must be non-negative): ");
for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);//positive numbers taken input from the user
	min[i] = low;//initializing the dp array with high values 
	sum = sum + a[i];//sum is total sum of the array
	count[i] = 0;
	}
quicksort(a,0,n-1);//sorting the array	
min[n] = low;	
printf("\n");	
min[0] = m(low,sum);
min[1] = m(sum,sum-2*a[0]);	
for(i=1;i<=n;i++)//Applying BOTTOM UP Approach
	{
	for(j=1;j<i;j++)
		{
		min[i] = minimum(min[i],min[i-1],diff(min[j],2*a[i-1]));
		}
	}
int k = n;
for(i=n;i>=1;i--)
	{
	if(min[i-1]<=min[i]) k--;
	else break;
	}

for(j=1;j<k;j++)
	{
	if(min[j]>=2*a[k-1]) count[j-1] = 1;
	//else count[j-1] = 0;
	}
count[k-1] = 1;		

printf("Minimum difference of sum of subsets = %d\n",min[n]);

printf("Subset1 = {");
for(i=0;i<n;i++) 
	{
	if(count[i]==1) printf("%d,",a[i]);
	}
printf("\b}\n");	

printf("Subset2 = {");
for(i=0;i<n;i++) 
	{
	if(count[i]==0) printf("%d,",a[i]);
	}
printf("\b}\n");	

return 0;		
 }
 
 
 
 
 
