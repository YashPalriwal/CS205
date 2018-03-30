//NAME - YASH PALRIWAL
//ROLL NO. - 1601CS50
//DATE - 04/08/2017
//Program to find max 1D range sum with no adjacent elements allowed

#include<stdio.h>
#include<stdlib.h>

int max(int m,int n)
{

if(m>=n)return m; //max function
else return n;
}


int largest_digit(int n)
{
int x = n,j;
if(n%10==n)return n;//base condition i.e. if the number is single digit return the same number
else
	{
	j = x%10;//Decomposition step of recurrsion
	largest_digit(x/10);
	return max(j,largest_digit(x/10));//Condition to check the largest digit
	}

}


int main(void)
{
int n,i,incl,exc,exc_new;
//printf("Enter the number of boxes: ");
scanf("%d",&n);
if(n<=0)printf("Enter a number greater than 0\n");
else
	{
	int a[n];
	//printf("Enter the number of chocolates in each box: ");
	for(i=0;i<n;i++)
		{
		scanf("%d", &a[i]);
		}

	incl = a[0];//incl is the max sum including the previous element
	exc = 0;//exc is the max sum excluding the previous element
	for(i=1;i<n;i++)
		{
		exc_new = max(incl,exc);
		incl = exc + a[i];
		exc = exc_new;
		}
	printf("%d\n",max(incl,exc));
	printf("%d\n",largest_digit(max(incl,exc)));
	}
}
