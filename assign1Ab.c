#include<stdio.h>
#include<stdlib.h>

struct node{
char a[20];
char c;
struct node *next;
};

int vowel(char c)
{
int i;
if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')i=1;
else i=0;
return i;
}

int main(void)
{
int n,i,n1,n2,j,v1,v2;
char temp;
struct node *head1 = NULL,*p1,*prev1,*p2,*p,*prev2,*head2 = NULL;
printf("Enter the size of the list: ");
scanf("%d",&n);
n1 = n/2;
n2 = n - n/2;
char temp1[n1],temp2[n2];


for(i=0;i<n1;i++)
    {
        p1 = (struct node*)malloc(sizeof(struct node));
        scanf("%s", p1->a);
        p1->c = p1->a[0];
        p1->next = NULL;
        if(head1 == NULL)head1 = p1;
        else prev1->next = p1;
        prev1 = p1;
    }
for(j=0;j<n2;j++)
    {
        p2 = (struct node*)malloc(sizeof(struct node));
        scanf(" %s", p2->a);
        p2->c = p2->a[0];
        p2->next = NULL;
        if(head2 == NULL)head2 = p2;
        else prev2->next = p2;
        prev2= p2;
    }
    p1 = head1;
    printf("Linked List : ");
 while(p1!=NULL)
    {
        if(p1->next!=NULL)
        printf("%c->",p1->c);
        else printf("%c",p1->c);
        p1 = p1->next;

    }
    printf(" and ");
     p2 = head2;
 while(p2!=NULL)
    {
        if(p2->next!=NULL)
        printf(" %c->",p2->c);
        else printf("%c",p2->c);
        p2= p2->next;

    }
     p = head1;

if(p!=NULL)
{


    while(1)
    {
         j=0;
        for(p=head1;p->next!=NULL;p=p->next)
        {
        v1 = vowel(p->next->c);
        v2 = vowel(p->c);
         if(v1==1 && v2==0)
         {
            temp = p->next->c;
            p->next->c = p->c;
            p->c = temp;
            p = head1;
            j++;
            continue;
         }

        if(j==0 && p==NULL)break;
        }
         if(j==0)break;

    }
}
       p = head1;
    printf("\nArranged Linked List: ");
    i=0;
 while(p!=NULL)
    {
        if(p->next!=NULL)
        printf(" %c->",p->c);
        else printf("%c",p->c);
        temp1[i] = p->c;
        i++;
        p = p->next;

    }
    printf(" and ");
     p = head2;

     if(p!=NULL)
{



    while(1)
    {
         j=0;
        for(p=head2;p->next!=NULL;p=p->next)
        {
        v1 = vowel(p->next->c);
        v2 = vowel(p->c);
         if(v1==1 && v2==0)
         {
            temp = p->next->c;
            p->next->c = p->c;
            p->c = temp;
            p = head1;
            j++;
            continue;
         }

        if(j==0 && p==NULL)break;
        }
         if(j==0)break;

    }
}

       p = head2;
i = 0;
 while(p!=NULL)
    {
        if(p->next!=NULL)
        printf(" %c->",p->c);
        else printf("%c",p->c);
        temp2[i] = p->c;
        p = p->next;
        i++;
    }
printf("\n");
}




