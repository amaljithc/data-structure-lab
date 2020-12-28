# include <stdio.h>
int q[100],i,rear,front,element,max,element2,opt,sflag=0;
void insert()
{
	if((rear+1)%max==front )
	{
		printf("Queue overflow\n");
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			rear=0;
		    front=0;
		}
		else if (rear==max-1 && front!=0)
			rear=0;
		else 
		{
		    rear=(rear+1)%max;
		}
		
		    printf("enter the element\n");
		    scanf("%d",&element);
		    q[rear]=element;
			if(front==-1)
				front=0;
			
		
	}
}
void deletion()
{
	if(front==-1  )
	{
		printf("queue underflow\n");
	}
	else
	{
		printf("deleted the element :%d\n",q[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(front==max-1)
				front=0;
			else
				front=front+1;
	
	

	}
}
void printfun()
{
	if(front==-1  )
	{
		printf("empty queue\n");
	}
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d \t",q[i]);
			
			}
			printf("\n");
		}
		else
		{
			for(i=front;i<max;i++)
			{
				printf("%d \t",q[i]);
				
			}
			for(i=0;i<=rear;i++)
			{
				printf("%d\t",q[i]);
			}
			
			
		}
	}
	
			
	
		
	
	
}
void search()
{
printf("Enter the item to be searched :");
scanf("%d",&element2);

if(front==-1  )
	{
		printf("empty queue\n");
	}
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				if(q[i]==element2)
				{
					sflag=1;
					printf("element found at the location :%d",i);
				}
			
			}
			if(sflag==0)
				printf("element not found\n");
		    
		}
		else
		{
			for(i=front;i<=max-1;i++)
			{
				if(q[i]==element2)
				{
					sflag=1;
					printf("element found at the location :%d",i);
				}
				
				
			}
			for(i=0;i<front;i++)
			{
				if(q[i]==element2)
				{
					sflag=1;
					printf("element found at the location :%d",i);
				}
			}
				if(sflag==0)
				printf("element not found\n");
		}
		
	}

}



void main()
{
	rear=-1;
	front=-1;
	printf("enter the size of queue");
	scanf("%d",&max);
	do
	{
		printf("enter your choice:\n 1.insertion\n 2.deletion \n 3.print queue\n 4.search \n5.exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case  1 :insert();break;
			case  2 :deletion();break;
			case  3 :printfun();break;
			case  4 :search();break;
            case  5 :printf("exited");break;
			default :printf("Incorrect choice\n");
		}

	}while(opt!=5);
	
}
