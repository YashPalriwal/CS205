//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//	Assignment7B.c

#include<stdio.h>
#include<stdlib.h>
#define HIGH 1000000

int diff(int x,int y)
{
if(x>=y) return x-y;
else return y-x;
}

void swap(int *x,int *y)//function to swap two integer values
{
int temp = *x;
*x = *y;
*y = temp;
}

int partition(int *a,int p,int r)//partition function for quicksort
{
int i=p-1,j;
for(j=p;j<r;j++)
	{
	if(a[j]<=a[r])
		{
		i++;
		swap(&a[i],&a[j]);		
		}
	}
swap(&a[r],&a[i+1]);
return i+1;

}

void quicksort(int *a,int p,int r)//function to sort the array 
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
int n,m,j,l=0,sum=0;
printf("Enter the number of elements: ");//taking input of number of elements from the user
scanf("%d",&n);
int a[n],i,arr[n];
printf("Enter the elements in the array: ");//taking input of elements in the array from the user
for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
quicksort(a,0,n-1);
printf("Enter the minimum difference: ");//taking input of the minimum difference between elements from the user
scanf("%d",&m);
for(i=n-1;i>0;i--)//Applying greedy approach to solve the question
	{
	for(j=i-1;j>=0;j--)//pairing the first element of the sorted array with the first element which satisfies a[j] - a[i]>=m
		{
		if(diff(a[j],a[i])<=m && a[i]!=HIGH && a[j]!=HIGH && i!=j) //storing these 2 values in the new arr array 
			{
			arr[l] = a[i];//since the expression a[j] - a[i+1]<=m is always false for j<k , so ignoring these cases
			l++;//l stores the present no. of stored elements in the arr array
			arr[l] = a[j];
			l++;
			sum = sum + a[j] + a[i];//sum stores the required output sum
			a[i] = HIGH;
			a[j] = HIGH;
			break;//breaking the loop whenever we find the first possible j for a particular i satisfying the constraint
			}
		}
	}
if(l!=0)printf("Max sum = %d\nElement Pairs:",sum);//printing the required sum
else printf("No two elements satisfy the constraint!!\n");
if(l!=0){
	for(i=l-1;i>=0;i--)
		{
		if(i==1) printf("(%d,%d)\n",arr[i],arr[i-1]);//printing the selected element pairs which give max sum
		else printf("(%d,%d),",arr[i],arr[i-1]);
		i--;
		}
	}			
return 0;	

}
