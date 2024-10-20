#include<stdio.h>
void main()
{
int state[10];
int str[10], input[10];
char ch;
int x[20];
int s,n,k=0,j,a,i,l,t,q=0,fs,b,nxt,z;
printf("enter the no. states\n");
scanf("%d",&s);
printf("enter the no. of i/p s \n");
scanf("%d",&n);

for(i=0;i<s;i++)
{
	printf("enter the state\n");
	scanf("%d",&state[i]);
	
	printf("is it final state?... y... 1/n..0\n");
	scanf("%d",&a);
	
	if(a==1)
	{
		fs=state[i];
	}
}
	printf("enter the i/ps\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&input[i]);
	}
	printf("transition state\n");
	
	for(i=0;i<s;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("q%d,%d)=q",state[i],input[j]);
			scanf("%d",&b);
			x[k]=b;
			k++;
		}
	}
	
	do
	{
	printf("enter the length of string\n");
	scanf("%d",&l);
	
	printf("enter the i/p string/n");
	q=0;
	for(i=0;i<l;i++)
	
	scanf("%d",&str[i]);
	
	for(i=0;i<l;i++)
	{
		t=0;
		do
		{
			if(str[i]==input[t])
			{
				nxt=x[n*q+t];
				for(j=0;j<s;j++)
				{
				if(nxt==state[j])
				q=j;
			}
			t++;
			}
			else
			t++;
		}
		
		while(t!=n);
		}
		
		
		
		if(nxt==fs)
		printf("\n string is accepted\n");
		else
		printf("\n not accepted\n");
		
		printf("do you want to continue... if yes press 1 else 2");
		
		scanf("%d",&z);
		}
		while(z!=2);
		}
	
		
