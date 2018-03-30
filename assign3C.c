#include<stdio.h>
#include<stdlib.h>
int k=0;//global counter for traversal through the array
int max_so_far=0;//absolute max value till the kth position 
int max_ending_here=0;//temporary positive value to check all cases

int max_subarray_sum(int a[],int n);

int main(void)
{
int n;//size of array
printf("Enter the size of  the array: ");
scanf("%d",&n);
if(n<0){printf("size must be greater than 0\n");return 0;}
int a[n],i;
for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}

printf("Max subarray sum = %d\n",max_subarray_sum(a,n));

}

int max_subarray_sum(int a[],int n)//recursive function to find maximum subarray sum
{


if(k==n)return max_so_far;//Base condition for breaking out of the recurrsive function 
else
	{
	if((max_ending_here+a[k])<0)max_ending_here = 0;//temp max value should never be negative
	else max_ending_here = max_ending_here + a[k];//if temp max value is +ve then checking all cases even if a[k]<0
	if(max_ending_here>max_so_far)max_so_far = max_ending_here;//max_so_far is updated whenever max_ending_here > max_so_far
	k++;
	return max_subarray_sum(a,n);//recurrsive step
	}


}
