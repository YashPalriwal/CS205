#include<stdio.h>
#include<stdlib.h>

int i=0;

int max(int *a,int index,int n)
{
int j,temp_max = *(a+index);
for(j=index;j<n-index;j++)
	{
	if(*(a+j)>temp_max) temp_max = *(a+j);
	}
return temp_max;
}

int index_search(int *a,int index,int no,int n)
{
int j;
for(j=index;j<n;j++){if(a[j]==no)return j+index;}
}

int min(int *a,int index,int n)
{
int j,temp_min = *(a+index);
for(j=index;j<n-index;j++)
	{
	if(*(a+j)<temp_min) temp_min = *(a+j);
	}
return temp_min;
}


int* sorting(int *a,int index,int n)
{
int temp_max,temp_min,temp,j;

temp_max = max(a,index+i,n-i);
j = index_search(a,index,temp_max,n);

temp =  *(a+index+i);
 *(a+index+i) = *(a+j);
*(a+j) = temp;

temp_min = min(a,index+i,n-i);
j = index_search(a,index,temp_min,n);

temp = *(a+n-index -2*i);
 *(a+n-index-2*i) = *(a+index+j);
 *(a+index+j) = temp;

i++;
if(n - index -2*i<=1) return a;
else sorting(a,index+1,n-1);


}

int main(void)
{

int n,j;
printf("Enter the size of the list: ");
scanf("%d",&n);
int a[n];
if(n<=0)printf("Size of the list must be greater than 0");
else
	{
	printf("Enter the numbers in the list: ");
	for(j=0;j<n;j++)
		{
		scanf("%d",&a[i]);
		}
sorting(a,0,n);
printf("\nSorted list in descending order: ");
	for(j=0;j<n;j++)
		{
		printf("%d ",a[j]);
		}
	printf("\n");

	}



}
