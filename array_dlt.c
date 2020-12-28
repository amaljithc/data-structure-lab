#include<stdio.h>
void main()
{

	int a[100],i,n,pos;

	printf("Enter the size=");
	scanf("%d",&n);

	printf("Enetr elemts=");
	for(i=0;i<n;i++)
	scanf("%d/n",&a[i]);

	printf("Enetr pos=");
	scanf("%d",&pos);

	if(pos>=n)
	{
	printf("deltn not  possible");
	}
	else
	{
		
		for(i=pos-1;i<n;i++)
		a[i]=a[i+1];
	
	printf("After deleion\n");
	for(i=0;i<n-1;i++)
	printf("%d\n",a[i]);
	
	}

}