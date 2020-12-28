#include<stdio.h>
void main()
{
	int a[10],n,i,pos,val;
	printf("Enter the total number of elemnts=  ");
	scanf("%d",&n);

	printf("Enter the elemnts =  ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);

	printf("Enter the position=  ");
	scanf("%d",&pos);

	printf("Enter the value= ");
	scanf("%d",&val);

	for(i=n-1;i>=pos-1;i--)
	
	a[i+1]=a[i];
	a[pos-1]=val;
	
	printf("New array=  ");

	for(i=0;i<=n;i++)
	printf("\n %d",a[i]);
}