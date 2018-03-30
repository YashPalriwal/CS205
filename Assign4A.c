//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//Assign4A.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int start = 800;
int q=0;
 
int max(int a,int b)
{
if(a>=b)return a;
else return b;
}
 
void swap(int *x,int *y)
{
int temp;
temp = *x;
*x = *y;
*y = temp;

}

void sorted_order(int* time,int n,int* priority_order,int* sorted_index);//function to give the array of index of strings in the order of them being examined
 
void priority(char **names,char *doc_name,int n,int *stringlen,int *priority_order)//function to give the array of the number of char common in doctors and patients name
{
 
int i,j,k,l=0,sum,w,z;
z = strlen(doc_name);
 
 
int a[26];
for(i=0;i<26;i++){a[i]=0;}//array taking count of the no. of same charcters with all initial values=0
for(k=0;k<n;k++)//loop to traverse through the array of strings of patients name
    {sum = 0;
    for(i=0;i<z;i++)//loop to traverse char in doctors name
        {
        for(j=0;j<stringlen[k];j++)//loop to traverse char in kth patients name
            {
            if(doc_name[i] == names[k][j])
                {
                if(doc_name[i]>=65 && doc_name[i]<=90 && a[doc_name[i]-65]==0) a[doc_name[i]-65] = 1;//The cond.a[doc_name[i]-65]==0 is used to prevent counting of same char more than 1 time
                else if(doc_name[i]>=97 && doc_name[i]<=122 && a[doc_name[i]-97]==0) a[doc_name[i]-97]=1;
                }
            }
           
        }
    for(w=0;w<26;w++)
            {
            sum = sum+a[w];//The value of sum is the total number of same char in doctor's and patient's name
            a[w] = 0;//again initializing every element as 0 for next iteration
            }
    priority_order[l] = sum;//Array storing the no. of same char 
    if(k<n-1)l++;
       
    }
 
}
 
int main(void)
{
int n,i,j;
printf("Enter the number of patients: ");
scanf("%d%*c",&n);//stringlen is the array storing the string lengths of every string in names
int time[n],stringlen[n],sorted_index[n],time_check[n];//sorted_index is the array storing the value of index of a corresponding string
int priority_order[n];//time_check[n] is the array to prevent the patient atteneded once to be considered again 
char **names,doc_name[20];
names=(char**)calloc(n,sizeof(char*));//calloc is used to get a contiguous memory space
for(i=0;i<n;i++)
{
    names[i]=(char*)calloc(20,sizeof(char));
    sorted_index[i] = i;//corresponds to index of every string in names
    time_check[i] = 0;//initially every element 
}

printf("Enter the name of the patients: \n");
for(i=0;i<n;i++)
    { for(j=0;j<20;j++)
        {
        names[i][j] = 0;//Initializing every element NULL initially
        }
    }
for(i=0;i<n;i++)
    {
    scanf("%s%*c",names[i]);
    stringlen[i] = strlen(names[i]);
    }
printf("Enter the time of arrival of patients respectively in a sorted order: ");
printf("\n24 hour time input format(hhmm)[example 08:00am = 0800 ; 03:31pm = 1531]: \n");
for(i=0;i<n;i++)
    {
    scanf("%d%*c",&time[i]);
    }
printf("Enter the name of the doctor: ");
scanf("%s%*c",doc_name);

priority(names,doc_name,n,stringlen,priority_order); 
sorted_order(time,n,priority_order,sorted_index);

printf("Order in which patients are attended: \n");
while(1)
	{
	for(i=0;i<n;i++)
		{
		if(start - time[i] >=0 && time_check[i]==0)
			{
			printf("%s\n",names[sorted_index[i]]);
			time_check[i] = 1;
			q++;//Global counter to store the number of patients examined
			break;
			}
		
		}
	start = start + 10;//time taken to examine each patient is 10 min
	if(q==n)break;//when q==n all the patients are attended
	}

return 0;
}
 
void sorted_order(int *time,int n,int *priority_order,int *sorted_index)
{
int i,j;
while(j!=0)
	{
		j=0;//when j==0 the priority_order array is completely stable sorted
		for(i=0;i<n-1;i++)
		{
			if(priority_order[i]<priority_order[i+1])
				{
				swap(&priority_order[i],&priority_order[i+1]);
				swap(&time[i],&time[i+1]);//swapping corresponding elements with priority_order
				swap(&sorted_index[i],&sorted_index[i+1]);
				j++;
				}
		}
	}
 

}

