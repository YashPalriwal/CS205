#include<stdio.h>
#include<stdlib.h>

int k=0;
int flag = 0;

int search_list(int *a,int index,int size,int no_to_be_searched)
{
int n,i;
n = no_to_be_searched;
if(size==1||size==2)
	{
	for(i=index;i<index+2;i++)
		{
		if(*(a+i)==n)
			{
			flag = 1;
			return i;
			break;
			}
		else k++;
		}
	}
else if(size>=3)
	{
	if(n < *(a + index + size/3))
	return search_list(a,index,size/3,n);
	else if(n>=*(a +index + size/3) && n<*(a + index + size/3 + size/3))
	return search_list(a,index + size/3,size/3,n);
	else if(n>=*(a+ index + size/3 + size/3))
	return search_list(a,index+size/3+size/3,size-size/3-size/3,n);
	}
	
if(k!=size){ return i;}
else 
	{
	k = size;
	return k;
	}


}

int main(void)
{

int n,i,m,k1;
printf("Enter the size of the list: ");
scanf("%d",&n);
int a[n];
if(n<=0)printf("Size of the list must be greater than 0");
else
	{
	printf("Enter the numbers in the list in a sorted order: ");
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
	printf("Enter the number to be searched: ");
	scanf("%d",&m);
	k1 = search_list(a,0,n,m); 
	if(flag==1)printf("NUmber is present in the list at index = %d\n",search_list(a,0,n,m));
	else printf("Number is not present in the list\n");
	}
}
