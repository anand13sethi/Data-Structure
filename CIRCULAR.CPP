//Circular Linked List
// 1. Insertion in the Begining
// 2. Insertion at the End
// 3. Insertion at any Arbitrary Position
// 4. Deletion in the Begining
// 5. Deletion at the End
// 6. Deletion from any Arbitrary Position

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
}*head=NULL,*temp,*ptr,*newNode;

void traversal()
{
	printf("\t\tPrinting Linked List\n\n");
	if(head==NULL)
	{
		printf("Linked List Is Empty");
	}
	else
	{
		temp=head;
		do
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
}

void insertInBegin()
{
	int info;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Information: ");
	scanf("%d",&info);
	newNode->data=info;
	newNode->next=NULL;
	if(head == NULL)
	{
		printf("\t\tInserting 1st Element in the List\n");
		head=newNode;
		newNode->next=head;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		newNode->next=head;
		temp->next=newNode;
		head=newNode;
	}
	traversal();
}

void insertAtEnd()
{
	int info;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Information: ");
	scanf("%d",&info);
	newNode->data=info;
	newNode->next=NULL;
	if(head == NULL)
	{
		printf("\t\tInserting 1st Element in the List\n");
		head=newNode;
		newNode->next=head;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=head;
	}
	traversal();
}

void insertRandom()
{
	int info,length=0,k=1,pos;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Information: ");
	scanf("%d",&info);
	newNode->data=info;
	newNode->next=NULL;
	if(head == NULL)
	{
		printf("\t\tInserting 1st Element in the List\n");
		head=newNode;
		newNode->next=head;
	}
	else
	{
		printf("Enter Position: ");
		scanf("%d",&pos);
		temp=head;
		do
		{
			temp=temp->next;
			length++;
		}while(temp!=head);
		if(pos > length+1 && pos < 1)
		{
			printf("Invalid Position!");
			getch();
		}
		else
		{
			if(pos==1)
			{
				temp=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				newNode->next=head;
				temp->next=newNode;
				head=newNode;
			}
			else if(pos==length+1)
			{
				temp=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				temp->next=newNode;
				newNode->next=head;
			}
			else
			{
				temp=head;
				while(k<pos-1)
				{
					temp=temp->next;
					k++;
				}
				newNode->next=temp->next;
				temp->next=newNode;
			}
		}
	}
	traversal();
}

void deleteInBegin()
{
	if(head==NULL)
	{
		printf("Underflow!");
		getch();
	}
	else
	{
		temp=head;
		if(temp->next==head)
		{
			free(temp);
			head=NULL;
		}
		else
		{
			ptr=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr->next;
			head=ptr->next;
			free(ptr);
		}
	}
	traversal();
}

void deleteAtEnd()
{
	if(head==NULL)
	{
		printf("Underflow!");
		getch();
	}
	else
	{
		temp=head;
		if(temp->next==head)
		{
			free(temp);
			head=NULL;
		}
		else
		{
			ptr=temp->next;
			while(ptr->next!=head)
			{
				temp=temp->next;
				ptr=ptr->next;
			}
			temp->next=head;
			free(ptr);
		}
	}
	traversal();
}

void deleteRandom()
{
	int length=0,k=1,pos;
	printf("Enter Position: ");
	scanf("%d",&pos);
	temp=head;
	do
	{
		temp=temp->next;
		length++;
	}while(temp!=head);
	if(pos>length && pos<1)
	{
		printf("Invalid Position!");
		getch();
	}
	else
	{
		if(pos==1)
		{
			temp=head;
			if(temp->next==head)
			{
				free(temp);
				head=NULL;
			}
			else
			{
				ptr=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				temp->next=ptr->next;
				head=ptr->next;
				free(ptr);
			}
		}
		else if(pos==length)
		{
			temp=head;
			if(temp->next==head)
			{
				free(temp);
				head=NULL;
			}
			else
			{
				ptr=temp->next;
				while(ptr->next!=head)
				{
					temp=temp->next;
					ptr=ptr->next;
				}
				temp->next=head;
				free(ptr);
			}
		}
		else
		{
			temp=head;
			ptr=temp->next;
			while(k<pos-1)
			{
				temp=temp->next;
				ptr=ptr->next;
				k++;
			}
			temp->next=ptr->next;
			free(ptr);
		}
	}
	traversal();
}

void main()
{
	clrscr();
	int choice;
	char ch;
	printf("\t\t\t****** Circular Linked List ******\n\n");
	do
	{
		printf("1. Insert Element In The Begining\n");
		printf("2. Insert Element At The End\n");
		printf("3. Insert Element In Arbitrary Position\n");
		printf("4. Delete Element From The Begining\n");
		printf("5. Delete Element From The End\n");
		printf("6. Delete Element From Any Arbitrary Position\n");
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertInBegin();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 2: insertAtEnd();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 3: insertRandom();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 4: deleteInBegin();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 5: deleteAtEnd();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 6: deleteRandom();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			default: printf("\nInvalid Choice!");
				break;
		}
	}while(ch=='Y' || ch=='y');
	getch();
}