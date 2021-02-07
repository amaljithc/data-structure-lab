#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	struct node*prev;
};
struct node*head=NULL;
struct node*last=NULL;
void ins_beg();
void ins_end();
void ins_pos();
void del_beg();
void del_end();
void del_pos();
void search();
void dis();
void dis_back();

void ins_beg()
{
	int val;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&val);
	newnode->data=val;
	newnode->prev=NULL;
	newnode->next=head;
	if(head==NULL)
	{
		head=newnode;
		last=newnode;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
	printf("\n node inserted");
}

void ins_end()
{
	
	int val;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&val);
	newnode->data=val;
	newnode->prev=last;
	newnode->next=NULL;
	if(last==NULL)
	{
		head=newnode;
		last=newnode;
	}
	else
	{
		last->next=newnode;
		last=newnode;
	}
	printf("\n node inserted");
}
void ins_pos()
{
	int i,val,pos;
	struct node*newnode,*temp;
	printf("\n enter the position:");
	scanf("%d",&pos);
	temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	for(i=1;i<pos-1;i++)
	{
		if(temp==NULL)
		{
			break;
		}
		temp=temp->next;
	}
	if(pos==1)
	{
		ins_beg();
		return;
	}
	else if(temp==last)
	{
		ins_end();
		return;
	}
	else if(temp!=NULL)
	{
		printf("\n enter the data:");
		scanf("%d",&val);
		newnode->data=val;
		newnode->next=temp->next;
		(temp->next)->prev=newnode;
		newnode->prev=temp;
		temp->next=newnode;
		printf("\n node inserted");
		return;
	}
}

void del_beg()
{
	struct node*temp=head;
	if(head==NULL)
	{
		printf("\nEmpty");
	}
	else
	{
		printf("\n %d  deleted",head->data,"\n");
		head=head->next;
		free(temp);
		if(head!=NULL)
		{
			head->prev=NULL;
		}
		else
		{
			printf("\n empty");
			last=NULL;
		}
	}
}

void del_end()
{
	struct node*temp=last;
	if(head==NULL)
	{
		printf("\nEmpty");
	}
	else
	{
		printf("\n %d  deleted",last->data,"\n");
		last=last->prev;
		if(last!=NULL)
		{
			last->next=NULL;
		}
		else
		{
			head=NULL;	
		}
		free(temp);
	}
}

void del_pos()
{
	int i,pos;
	struct node*temp=head;
	printf("\n Enter the position:");
	scanf("%d",&pos);
	for(i=1;i<pos&&temp!=NULL;i++)
	{
		temp=temp->next;
	}
	if(pos==1)
	{
		del_beg();
	}
	else if(temp==last)
	{
		del_end();
	}
	else if(temp!=NULL)
	{
		printf("\n %d deleted",temp->data);
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	else
	{
		printf("\n enter valid position");
	}
}
void search()
{
	struct node*temp=head;
	if(temp==NULL)
	{
		printf("\n Empty");
	
	}
	else
	{
		
		int ele,f,i=0;
		printf("\n enter the element to be searched:");
		scanf("%d",&ele);
		while(temp!=NULL)
		{
			if(temp->data==ele)
			{
				printf("\ndata found at the location  %d",i+1);
				f=0;
				break;
			}
			else
			{
				f=1;
			}
			i++;
			temp=temp->next;
		}
		if(f==1)
		{
			printf("\n data found");
		}
	}
}

void dis()
{
	if(head==NULL)
	{
		printf("\n Empty");
	}
	else
	{
		struct node*temp=head;
		while(temp->next!=NULL)
		{
			printf("%d<-->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
void dis_back()
{
	printf("\n backwars traversin....");
	if(last==NULL)
	printf("\n empty");
	else
	{
		struct node*temp=last;
		while(temp->prev!=NULL)
		{
			printf("%d<---->",temp->data);
			temp=temp->prev;
		}
		printf("%d",temp->data);
	}	
}
void main()
{
	int c;
	printf("\n enter the choice:");
	printf("\n");
	while(1)
	{
		printf("\n1.insertion at beginning\n2.insertion at end\n3.insertion at specified position\n4.deletion at beginning\n5.deletion at end\n6.deletion at specified position\n7.search\n8.display \n9.displaying backward\n10.Exit:\n");
		scanf("\n%d",&c);
		switch(c)
		{
			case 1:ins_beg();break;
			case 2:ins_end();break;
			case 3:ins_pos();break;
			case 4:del_beg();break;
			case 5:del_end();break;
			case 6:del_pos();break;
			case 7:search();break;
			case 8:dis();break;
			case 9:dis_back();break;
			case 10:exit(1);break;
			default:printf("\n invalid choice");
		}
	}
}