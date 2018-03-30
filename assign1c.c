//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
//DATE - 02/08/2017
//Program for a library

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book{
int s_no;
int issue_status;
char *t,*a;//To store strings with spaces allowed
}Book;

int main(void)
{
Book new[50];
int i=0,j=0,sno,k=0,n,m,z,x;
char c;
char *title , *author;
title = (char*)malloc(60*sizeof(char));//Allocating spaces to the pointers to store strings
author = (char*)malloc(60*sizeof(char));//These pointers are used in the 'View Details of a book' option to take input from the users 

while(1)
	{
	printf("\na.Make a new entry of book\nb.View Details of a book\nc.Show list of available books\nd.Issue a book\ne.Return a book\nf.Exit\n>>>>");
	scanf(" %c",&c);
	if(c=='f')break;//To exit the program
	if(c=='a')
		{
		new[i].t = (char*)malloc(60*sizeof(char));
		new[i].a = (char*)malloc(60*sizeof(char));
		printf("Enter the Serial Number of the new book: ");
		scanf("%d",&new[i].s_no);
		printf("Enter the title of the book: ");
		scanf(" %[^\n]",new[i].t);//%[^\n] is used to input strings with spaces allowed
		printf("Enter the author of the book: ");
		scanf(" %[^\n]",new[i].a);
		new[i].issue_status = 0;//issue_status=0 means the book is not issued yet
		printf("\nNew Entry Successful\n");
		i++;
		}
	k=0;
	if(c=='c')
		{
		for(j=0;j<i;j++)
			{
			if(new[j].issue_status==0)
				{
				printf("%d %s %s\n",new[j].s_no,new[j].t,new[j].a);
				}
			if(new[j].issue_status!=0)k++;
			if(k==i) printf("\nNo books are currently available\n");//k is equal to i when no books are available
			}
		}
	k=0;
	if(c=='d')
		{
		printf("Enter the serial number of the book to be issued: ");
		scanf("%d",&sno);
		for(j=0;j<i;j++)
			{
			if(new[j].s_no == sno)
				{
				if(new[j].issue_status == 0)
					{
					new[j].issue_status = 1;
					printf("\nBook Issue Successful\n");
					break;					
					}
				if(new[j].issue_status !=0)
					{
					printf("\nBook is already issued by someone else\n");
					break;						
					}				

				}
			if(new[j].s_no != sno)k++;			
			if(k == i)
				{
				printf("\nPlease enter a valid serial number.\n");	
				}			
			
			}
		}
	k=0;
	if(c=='e')
		{
		printf("Enter the serial number of the book to be returned: ");
		scanf("%d",&sno);
		for(j=0;j<i;j++)
			{
			if(new[j].s_no == sno)
				{
				if(new[j].issue_status != 1)printf("\nPlease enter a valid serial number. This serial number is not issued\n");
				if(new[j].issue_status == 1)
					{
					new[j].issue_status = 0;
					printf("\nBook Return Successful\n");
					}
				
				}
			if(new[j].s_no != sno)k++;
			if(k==i)printf("\nPlease enter a valid seial number\n");			
			}
		}
	k=0;
	if(c=='b')
		{
		printf("\n1.By serial No.\n2.By Title\n3.By Author\nEnter your choice>>>>");
		scanf("%d",&n);
		if(n==1)
			{
			printf("\nEnter the serial number of the book>>>>");
			scanf("%d",&m);
			for(j=0;j<i;j++)
				{
				if(new[j].s_no==m)printf("\n%d %s %s\n",new[j].s_no,new[j].t,new[j].a);
				else if(new[j].s_no!=m)k++;
				if(k==i)printf("\nNo Book of the entered serial number exist");

				}
			}
	k=0;
		if(n==2)
			{
			printf("\nEnter the title of the book>>>>");
			scanf(" %[^\n]",title);
			for(j=0;j<i;j++)
				{
				z = strcmp(title,new[j].t);//used to compare the input string to the stored string
				if(z==0)printf("\n%d %s %s\n",new[j].s_no,new[j].t,new[j].a);// if the return value of strcmp() is 0 means the strings are same
				else if(z!=0)k++;
				if(k==i)printf("\nNo book with entered title exist.\n");
				
				}
			}
	k=0;
		if(n==3)
			{
			printf("\nEnter the author of the book>>>>");
			scanf(" %[^\n]",author);
			for(j=0;j<i;j++)
				{
				x = strcmp(author,new[j].a);
				if(x==0)printf("\n%d %s %s\n",new[j].s_no,new[j].t,new[j].a);
				else if(x!=0)k++;
				if(k==i)printf("\nNo book with entered author exist.\n");
				
				}
			}
				
		}
		
	
	}
	




}
