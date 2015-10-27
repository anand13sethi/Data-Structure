// Implementing Stack using Linked List.
#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next;
}*head,*top=NULL,*newNode,*temp;

void traversal()
{
	printf("\t\tPrinting Elements in the Stack\n\n");
	if(top==NULL)
	{
		printf("Stack Is Empty\n");
	}
	else
	{
		temp=head;
		while(temp!=top)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}

void push()
{
	int info;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Information: ");
	scanf("%d",&info);
	newNode->data=info;
	newNode->next=NULL;
	if(top==NULL)
	{
		printf("\t\tInserting 1st Element In Stack\n\n");
		head=newNode;
		top=newNode;
	}
	else
	{
		top->next=newNode;
		top=newNode;
	}
	traversal();
}

void pop()
{
	if(top==NULL)
	{
		printf("Underflow!\n");
	}
	else if(head->next==NULL)
	{
		free(top);
		top=NULL;
		head=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=top)
		{
			temp=temp->next;
		}
		top=temp;
		temp=temp->next;
		free(temp);
	}
	traversal();
}

void main()
{
	clrscr();
	int choice;
	char ch;
	printf("\t\t****** Stacks Using Linked List ******\n\n");
	do
	{
		printf("1. Push Onto Stack\n");
		printf("2. Pop from Stack\n");
		printf("3. Traversal\n");
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
				printf("\nDo You Want to Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 2: pop();
				printf("\nDo You Want To  Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 3: traversal();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			default: printf("Invalid Choice!\n");
				break;
		}
	}while(ch=='Y' || ch=='y');
	getch();
}
