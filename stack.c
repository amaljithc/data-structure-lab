#include<stdio.h>
#include<stdlib.h>
int top=-1,val,c,i,s[100],n;
void push();
void pop();
void dis();
void main()
{
	printf("\n enter the size:");
	scanf("\n%d",&n);
	
	printf("\n 1.insert 2.delete 3.display 4.exit:");
	
	do
	{
		printf("\n enter choice:");
		scanf("\n%d",&c);
		switch(c)
		{
			case 1:push();
			             break;
			case 2:pop();
			             break;
			case 3:dis();
			             break;
			case 4:exit(0);
			             break;
			default:printf("\n invalid choice");
		}
	}while(4!=0);
}
void push()
{
	if(top>=n-1)
	{
		printf("\n overflow");
	}
	else
	{
		printf("\n enter value:");
		scanf("\n%d",&val);
		top++;
		s[top]=val;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("\n underflow");
	}
	else
	{
		printf("%d deleted",s[top]);	
		top--;
	}
}
void dis()
{
	if(top<=-1)
	{
		printf("\n empty stack");
	}
	else
	{
		printf("\n elemts:");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",s[i]);
		}
	}
}
