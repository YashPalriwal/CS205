#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
	{
	char *a;
	char *n;
	int max_index;
	struct node *next;

	};

int min(int m,int n)
	{
   	 if(m<=n)return m;
   	 if(m>n)return n;
	}

int max(int m,int n)
	{
	    if(m<=n)return n;
	    if(m>n)return m;
	}

struct node* compress_string(struct node *head)
	{
	 struct node *p,*q;
	 int i,k=0,l=0;
	 p = head;
	 q = head;
	 while(p!=NULL)
	 {
	     q=head;
	     p->max_index = 0;


	     while(q!=NULL)
	     {
	            if(q==p) {q= q->next;}
	            if(q==NULL)break;
	            k=0;
	           for(i=0;i<min(strlen(p->n),strlen(q->n));i++)
	           {
	            if(*((p->n)+i)==*((q->n)+i))k++;
	            else break;
	           }
	           q = q->next;

	           p->max_index=max(p->max_index,k);

	     }
   
	     p->a = (char*)malloc(((p->max_index)+1)*sizeof(char));
	     for(i=0;i<=p->max_index;i++)
	           {
	            *((p->a)+i) = *((p->n)+i);
	           }
	     p = p->next;
	 }
	return head;
	}

int main(void)
{
    int n,i,j,k=0;
    struct node *p,*prev,*head = NULL;
    char *s,t[40],t1[40];
    printf("Enter the value of n: ");
    scanf("%d",&n);
    char a[n][20];
    for(i=0;i<n;i++)
    	{
        	p = (struct node*)malloc(sizeof(struct node));
        	p->n = (char*)malloc(20*sizeof(char));
   	     scanf("%s", p->n);
   	     p->next = NULL;
   	     if(head == NULL)head = p;
   	     else prev->next = p;
   	     prev = p;

   	 }
	compress_string(head);

	p = head;
	printf("Names in the list: ");
	while(p!=NULL)
		{
	    	printf("%s ",p->a);
	    	p = p->next;
		}



	while(1)
		{p = head;
	
		while(p->next != NULL)
			{
			k = 0;
			    if(strcmp(p->a,p->next->a) > 0) {
		
			        strcpy(t1, p->a);
	
			        strcpy(p->a,p->next->a);

			        strcpy(p->next->a, t1);
		
			  	k++;

			    }
			     else if(strcmp(p->a,p->next->a) <= 0)k = k+0;
				else if(k==0)break;
				
							

		   
			    p = p->next;

			}
		if(k==0)break;
	
		}
	p = head;
	printf("\nSorted names in list: ");
	while(p!=NULL)
		{
		if(p->next==NULL)printf("%s",p->a);
		 else printf("%s,",p->a);
		p = p->next;
		}


	while(1)
		{p = head;
		
		while(p->next != NULL)
			{
			k = 0;
			    if(strcmp(p->n,p->next->n) > 0) {
		
			        strcpy(t, p->n);

			        strcpy(p->n,p->next->n);

			        strcpy(p->next->n, t);
		
			  	k++;

			    }
			     else if(strcmp(p->n,p->next->n) <= 0)k = k+0;
				else if(k==0)break;
					
							

		   
			    p = p->next;

			}
		if(k==0)break;
	
		}
	p = head;
	printf("\nNames to be printed: ");
	while(p!=NULL)
		{if(p->next==NULL)printf("%s",p->n);
		 else printf("%s,",p->n);
		p = p->next;
		}
}
