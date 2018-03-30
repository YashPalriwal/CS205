#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag = 0;
int k=0;//global counter for the index of characters in string s
int k1=0;//global counter for the index of charcters in str

char* traversal(char *s,char *str,int n)//recurrsive function to traverse the loop
{
if(k==n)return str;//returning the string str after traversing it completely through its strlen
else {
	if(s[k]!=s[0])//if kth character of s is not same as its 1st character
		{
		str[k1] = s[k];//creating new string str with all the copies of 1st charcter in s removed
		k1++;//increasing the value of k1 whenever a value is assigned in str		
		}
	k++;//increasing the value of traversing counter for string s
	return traversal(s,str,n);//recurrsive step for looping
	}

}

int remove_char(char *s,int n)//recurrsive function to check whether a string is even or not
{

char *str;//creating str for storing the string after removing all the copies of 1st character of s
str = (char*)malloc(50*sizeof(char));
if(n%2!=0)return flag;//if strlen is odd , it is always an odd string
if(n==0){flag=1;return flag;}//if strlen is zero it is an even string
else
	{
	
	str = traversal(s,str,n);//nested recurrsion step
	k=0;//making the value of global variables 0 after every complete call of traversal function
	k1=0;
	s = str;//decompositon step of the recurrsive function remove_char
	n = strlen(s);//if all copies of 1st char are removed from an even string then also it is an even string
	return remove_char(s,n);//recurrsive step
	}
}

int main(void)
{

char *s;
int n,s1;
s = (char*)malloc(50*sizeof(char));

printf("Enter the string: ");
scanf(" %[^\n]", s);//Dont use inputs seperated by spaces as the strlen counts spaces also so it leads to errors
n = strlen(s);
if(n%2!=0)printf("ODD String\n");// if the strlen of the input step is odd it is always an odd string 
else{
	s1 = remove_char(s,n);
	if(flag==1)printf("It is an even string\n");//flag is 1 when an even string is found
	else printf("it is an odd string\n");
	}

}
