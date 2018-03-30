#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void swap(int *x,int *y)
{
int temp;
temp = *x;
*x = *y;
*y = temp;

}

int median(int *A,int i,int j,int k)
{
if(A[i]>=A[j] && A[j]>=A[k])return j;
else if(A[i]>=A[k] && A[k]>=A[j])return k;
else if(A[j]>=A[i] && A[i]>=A[k])return i;
else if(A[j]>=A[k] && A[k]>=A[i])return k;
else if(A[k]>=A[i] && A[i]>=A[j])return i;
else if(A[k]>=A[j] && A[j]>=A[i])return j;
}

int partition(int* A,int p,int r);

void quicksort(int* A,int p,int r);



void almost_sorted(int *A,int n);
void  quicksort_0(int *A,int p, int r);
void  quicksort_1(int *A,int p, int r);
void quicksort_2(int *A,int p, int r);
void quicksort_3(int *A,int p, int r);


int main(void)
{
srand((unsigned int)time(NULL));
int i=4,n=1000,*A4,*A5,*A6,*A7,j;
/*int *A40,*A41,*A42,*A43;
int *A50,*A51,*A52,*A53;
int *A60,*A61,*A62,*A63;
int *A70,*A71,*A72,*A73;*/

double A4_runtime_0[3],A4_runtime_1[3],A4_runtime_2[3],A4_runtime_3[3];
double A5_runtime_0[3],A5_runtime_1[3],A5_runtime_2[3],A5_runtime_3[3];
double A6_runtime_0[3],A6_runtime_1[3],A6_runtime_2[3],A6_runtime_3[3];
double A7_runtime_0[3],A7_runtime_1[3],A7_runtime_2[3],A7_runtime_3[3];

for(i=4;i<=7;i++)
	{
	n = n*10;
	if(i==4) A4 = (int*)malloc(n*sizeof(int));
	else if(i==5) A5 = (int*)malloc(n*sizeof(int));
	else if(i==6) A6 = (int*)malloc(n*sizeof(int));
	else if(i==7) A7 = (int*)malloc(n*sizeof(int));
	}
for(i=0;i<10000000;i++)
	{
	if(i<10000) A4[i] = rand()%1000000000;
	if(i<100000) A5[i] = rand()%1000000000;
	if(i<1000000) A6[i] = rand()%1000000000;
	A7[i] = rand()%1000000000;
	
	}

		

clock_t c1, c2;



c1 = clock();
/*
quicksort_1(A41,0,10000-1);
c2 = clock();
printf("%lf",(double)(c2 -c1) / (double)CLOCKS_PER_SEC); */       



//three cases for quicksort_0 A40

//random case for A40
c1 = clock();

quicksort_0(A4,0,10000-1);
c2 = clock();
A4_runtime_0[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;


//sorted case for A40
c1 = clock();

quicksort_0(A4,0,10000-1);
c2 = clock();
A4_runtime_0[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//almost sorted case for A40
almost_sorted(A4,10000);

c1 = clock();

quicksort_0(A4,0,10000-1);
c2 = clock();
A4_runtime_0[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

for(i=0;i<10000;i++){
A4[i] = rand()%1000000000;
}
//three cases for quicksort_1 A41

//random case for A41
c1 = clock();

quicksort_1(A4,0,10000-1);
c2 = clock();
A4_runtime_1[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//sorted case for A41
c1 = clock();

quicksort_1(A4,0,10000-1);
c2 = clock();
A4_runtime_1[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

// almost sorted case for A41
almost_sorted(A4,10000);

c1 = clock();

quicksort_1(A4,0,10000-1);
c2 = clock();
A4_runtime_1[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

for(i=0;i<10000;i++){
A4[i] = rand()%1000000000;
}
//three cases for quicksort_2 A42

//random case for A42
c1 = clock();

quicksort_2(A4,0,10000-1);
c2 = clock();
A4_runtime_2[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//sorted case for A42
c1 = clock();

quicksort_2(A4,0,10000-1);
c2 = clock();
A4_runtime_2[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//almost sorted case for A42 
almost_sorted(A4,10000);

c1 = clock();

quicksort_2(A4,0,10000-1);
c2 = clock();
A4_runtime_2[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC; 

for(i=0;i<10000;i++){
A4[i] = rand()%1000000000;
}
//three cases for quicksort_3 A43

//random case for A43
c1 = clock();

quicksort_3(A4,0,10000-1);
c2 = clock();
A4_runtime_3[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        
       
//sorted case for A43
c1 = clock();

quicksort_3(A4,0,10000-1);
c2 = clock();
A4_runtime_3[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//almost sorted case for A43 
almost_sorted(A4,10000);

c1 = clock();

quicksort_3(A4,0,10000-1);
c2 = clock();
A4_runtime_3[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC; 

//quicksort_3(A50,0,100000-1);
//for(i=0;i<100000;i++) printf("%d<=",A50[i]);

printf("\nn\t\tPivot type\t\tRandom\t\t\tSorted\t\t\tAlmost Sorted\n\n\n");
for(i=0;i<4;i++)
	{
	if(i==0)
		{
		printf("10000\t\tFIRST\t\t\t");
		for(j=0;j<3;j++)
			{
			printf("%lf\t\t",A4_runtime_0[j]);
			}
		printf("\n");
		}
	else if(i==1)
		{
		printf("10000\t\tRANDOM\t\t\t");
		for(j=0;j<3;j++)
			{		
			printf("%lf\t\t",A4_runtime_1[j]);
			}
		printf("\n");
		}
	else if(i==2)
		{
		printf("10000\t\tMEDIAN OF THREE 1\t");
		for(j=0;j<3;j++)
			{		
			printf("%lf\t\t",A4_runtime_2[j]);
			}
		printf("\n");	
		}
	else
		{
		printf("10000\t\tMEDIAN OF THREE 2\t");
		for(j=0;j<3;j++)
			{		
			printf("%lf\t\t",A4_runtime_3[j]);
			}
		printf("\n");
		}
	
	}
	
	//three cases for quicksort_0 A50

//random case for A50
c1 = clock();

quicksort_0(A5,0,100000-1);
c2 = clock();
A5_runtime_0[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;


//sorted case for A50
c1 = clock();

quicksort_0(A5,0,100000-1);
c2 = clock();
A5_runtime_0[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//almost sorted case for A50
almost_sorted(A5,100000);

c1 = clock();

quicksort_0(A5,0,100000-1);
c2 = clock();
A5_runtime_0[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//three cases for quicksort_1 A51
for(i=0;i<100000;i++){
A5[i] = rand()%1000000000;
}
//random case for A51
c1 = clock();

quicksort_1(A5,0,100000-1);
c2 = clock();
A5_runtime_1[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//sorted case for A51
c1 = clock();

quicksort_1(A5,0,100000-1);
c2 = clock();
A5_runtime_1[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

// almost sorted case for A51
almost_sorted(A5,100000);

c1 = clock();

quicksort_1(A5,0,100000-1);
c2 = clock();
A5_runtime_1[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        


//three cases for quicksort_2 A52
for(i=0;i<100000;i++){
A5[i] = rand()%1000000000;
}
//random case for A52
c1 = clock();

quicksort_2(A5,0,100000-1);
c2 = clock();
A5_runtime_2[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//sorted case for A52
c1 = clock();

quicksort_2(A5,0,100000-1);
c2 = clock();
A5_runtime_2[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//almost sorted case for A52 
almost_sorted(A5,10000);

c1 = clock();

quicksort_2(A5,0,100000-1);
c2 = clock();
A5_runtime_2[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC; 

//three cases for quicksort_3 A53
for(i=0;i<100000;i++){
A5[i] = rand()%1000000000;
}
//random case for A53
c1 = clock();

quicksort_3(A5,0,100000-1);
c2 = clock();
A5_runtime_3[0] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        
       
//sorted case for A53
c1 = clock();

quicksort_3(A5,0,100000-1);
c2 = clock();
A5_runtime_3[1] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC;        

//almost sorted case for A53 
almost_sorted(A5,100000);

c1 = clock();

quicksort_3(A5,0,100000-1);
c2 = clock();
A5_runtime_3[2] = (double)(c2 -c1) / (double)CLOCKS_PER_SEC; 

printf("\n");

for(i=0;i<4;i++)
	{
	if(i==0)
		{
		printf("100000\t\tFIRST\t\t\t");
		for(j=0;j<3;j++)
			{
			printf("%lf\t\t",A5_runtime_0[j]);
			}
		printf("\n");
		}
	else if(i==1)
		{
		printf("100000\t\tRANDOM\t\t\t");
		for(j=0;j<3;j++)
			{		
			printf("%lf\t\t",A5_runtime_1[j]);
			}
		printf("\n");
		}
	else if(i==2)
		{
		printf("100000\t\tMEDIAN OF THREE 1\t");
		for(j=0;j<3;j++)
			{		
			printf("%lf\t\t",A5_runtime_2[j]);
			}
		printf("\n");	
		}
	else if(i==3)
		{
		printf("100000\t\tMEDIAN OF THREE 2\t");
		for(j=0;j<3;j++)
			{		
			printf("%lf\t\t",A5_runtime_3[j]);
			}
		printf("\n");
		}
	 
	}


}


int partition(int* A,int p,int r)
{
int x = A[r];
int i = p-1,j;
for(j=p;j<r;j++)
	{
	if(A[j]<=x)
		{
		i = i+1;
		swap(&A[i],&A[j]);
		}
	}
swap(&A[r],&A[i+1]);
return (i+1);


}

void quicksort(int* A,int p,int r)
{
int q;
if(p<r)
	{
 	q = partition(A,p,r);
	quicksort(A,p,q-1);
	quicksort(A,q+1,r);
	}
}

void  quicksort_0(int *A,int p, int r)
{

swap(&A[0],&A[r]);

quicksort(A,p,r);
}

void quicksort_1(int *A,int p,int r)
{
int z = rand()%(r+1);
swap(&A[z],&A[r]);
quicksort(A,p,r);
}

void quicksort_2(int *A,int p,int r)
{

int z = median(A,0,(r+1)/2,r);
swap(&A[z],&A[r]);
quicksort(A,p,r);


}

void quicksort_3(int *A,int p,int r)
{

int z = median(A,(r+1)/4,(r+1)/2,3*(r+1)/4);
swap(&A[z],&A[r]);
quicksort(A,p,r);


}

void almost_sorted(int *A,int n)
{
int k = n/100;
int r1,r2,i;

for(i=0;i<k;i++)
	{
	r1 = rand()%n;
	r2 = rand()%n;
	swap(&A[r1],&A[r2]);
	}


}
