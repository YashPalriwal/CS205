//NAME - YASH PALRIWAL
//ROLL NUMBER - 1601CS50
// Assign4B.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max_len(int len1,int len2)//function which returns the max value of length
{
if(len1>=len2)return len1;
else return len2;

}

int length(int n)// func to check the length of the binary equivalent of a decimal number
{
if(n==0)return 0;
else{
int temp,len1=0;

temp = n;
while(1)
	{
	
	temp = temp/2;
	len1++;
	if(temp<1)break;
	
	}
return len1;
	}
}


void int_to_binary(int n1,int *p1)//recurrsive func to convert integer to binary
{
int len1 = length(n1);	
if(len1>0)
	{
	p1[len1-1] = n1%2;
	n1 = n1/2;
	int_to_binary(n1,p1);
	}
}

int binary_to_int(int *p,int len)//func to convert binary to decimal 
{
int decimal=0,i=0,k=1;
for(i=0;i<len;i++)
	{
	decimal = decimal + p[len-i-1]*k;
	k = k*2;
	}

return decimal;
}



int* length_equalizer(int *p1,int *p2,int len1,int len2)/*func to make lengths of two binary numbers equal 
							by appending zeros to the starting of the binary number with less bits	*/
{
int *temp,i,len,*temp1;
if(len1>=len2)
	{
	temp = p2;
	temp1 = (int*)malloc(len1*sizeof(int));
	
	for(i=0;i<len1;i++)
		{
		temp1[i] = 0;
		}
	for(i=0;i<len2;i++)
		{
		temp1[i+len1-len2] = temp[i];
		}
	len = len1;
	p2 = temp1;
	return p2;
	}
else {
	temp = p1;
	temp1 = (int*)malloc(len2*sizeof(int));
	for(i=0;i<len2;i++)
		{
		temp1[i] = 0;
		}
	for(i=0;i<len1;i++)
		{
		temp1[i+len2-len1] = temp[i];
		}
	p1 = temp1;
	len = len2;
	return p1;
	}


}

int karatsuba_multiplication(int *p1,int *p2,int len);

int main(void)
{

int n1,n2,len1,len2,len,i;
int *p1,*p2;
printf("Enter the first number: ");
scanf("%d",&n1);
printf("Enter the second number: ");
scanf("%d",&n2);
len1	 = length(n1);
len2 = length(n2);

	p1 = (int*)malloc(len1*sizeof(int));
	p2 = (int*)malloc(len2*sizeof(int));

int_to_binary(n1,p1);
int_to_binary(n2,p2);

len = max_len(len1,len2);
if(len1>len2)p2 = length_equalizer(p1,p2,len1,len2);
else if(len2>len1)p1 = length_equalizer(p1,p2,len1,len2);

printf("Karatsuba Product: %d\n",karatsuba_multiplication(p1,p2,len));


}


int karatsuba_multiplication(int *p1,int *p2,int len)//func to recurrsively multiply two numbers with time complexity O(n^1.59)
{
int xl[len/2],xr[len-len/2],yl[len/2],yr[len-len/2];//xl and yl are left parts of the binary number
int xy,i,z1,z2,z3,x1,y1,x2,y2,*sum1,*sum2;//xr and yr are right parts of the binary number
if(len==0)return 0;
else if(len==1)return p1[0]*p2[0];//base condition
else
	{
	for(i=0;i<len;i++)
		{
		if(i<len/2)
			{
			xl[i] = p1[i];//Initializing the left parts
			yl[i] = p2[i];
			}
		else
			{
			xr[i-len/2] = p1[i];//Initializing the right parts
			yr[i-len/2] = p2[i];
			}
		}	

	z1 = karatsuba_multiplication(xl,yl,len/2);//recurrsive multiplication to get xl*yl
	z2 = karatsuba_multiplication(xr,yr,len-len/2);//recurrsive multiplication to get xr*yr
	x1 = binary_to_int(xl,len/2);	/*converting xl,yl,xr,yr to decimal ,taking their sum then again converting to binary */
	y1 = binary_to_int(yl,len/2);
	x2 = binary_to_int(xr,len-len/2);
	y2 = binary_to_int(yr,len-len/2);
	sum1 = (int*)malloc(length(x1+x2)*sizeof(int));
	sum2 = (int*)malloc(length(y1+y2)*sizeof(int));
	int_to_binary(x1+x2,sum1);
	int_to_binary(y1+y2,sum2);
	if(length(x1+x2)>length(y1+y2)) sum2 = length_equalizer(sum1,sum2,length(x1+x2),length(y1+y2));
	else if(length(x1+x2)<length(y1+y2)) sum1 = length_equalizer(sum1,sum2,length(x1+x2),length(y1+y2));
	z3 = karatsuba_multiplication(sum1,sum2,max_len(length(x1+x2),length(y1+y2)));//recurrsive multiplication to get xl*yr + xr*yl = (xl+xr)*(yl+yr) - xl*yl - xr*yr
	xy = z1*pow(2,2*ceil((float)len/2)) + z2 + (z3 - z1 - z2)*pow(2,ceil((float)len/2));//Applying karatsuba algorithm to get the overall product 
	}
return xy;
}
















