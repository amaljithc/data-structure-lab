# include <stdio.h>
# include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
	void push(int n);
	void pop();
	void dis();
	struct node *newNode,*temp,*head;
void push(int n)
{
  	newNode = (struct node *)malloc(sizeof(struct node));
  	if(newNode == NULL)
  	{
    		printf("over flow");
		exit(0);
  	}
  	newNode->data=n;

  	if(head==NULL)
  	{
     		newNode->next=NULL;

  	}
 	else
 	{
   		newNode->next=head;

 	}
  	head=newNode;
}

void pop()
{
	if(head == NULL)
	{
		printf("stack is underflow");
		return;
	}
	else
	{
		printf("Element deleted is %d \n",head->data);
		head=head->next;
	}


}
void dis()
{
	if(head == NULL)
	{
		printf("Stack is empty.");
		return;
	}
	temp=head;
	while(temp!= NULL)
	{
		printf("Data = %d\n", temp->data); 
		temp = temp->next; 

	}

}
void main()
{
	int n,c;
	head=NULL;
	printf("\n Enter the choice:");
	while(1)
	{
		printf("\n Enter\t1.Push\t2.Pop\t3.Display\t 4.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case  1 :printf("Enter the element:");scanf("%d",&n);
                                 			push(n);break;
			case  2 :pop();break;
			case  3 :dis();break;
			case  4 :exit(1);break;
			default :printf("Incorrect choice\n");
		}

	}
}