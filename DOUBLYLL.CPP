//Doubly Linked List
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
	struct node *prev;
	struct node *next;
}*head,*temp,*ptr,*newNode;

void traversal()
{
	printf("\t\tPrinting Linked List\n\n");
	if(head==NULL)
	{
		printf("Linked List Doesn't Exist\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
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
	newNode->prev=NULL;
	if(head==NULL)
	{
		printf("\t\tInserting 1st Element In Linked List\n\n");
		head=newNode;
	}
	else
	{
		newNode->next=head;
		head->prev=newNode;
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
	newNode->prev=NULL;
	if(head==NULL)
	{
		printf("\t\tInserting 1st Element In Linked List\n\n");
		head=newNode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
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
	newNode->prev=NULL;
	if(head==NULL)
	{
		printf("\t\tInserting 1st Element In Linked List\n\n");
		head=newNode;
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			temp=temp->next;
			length++;
		}
		printf("Enter Position: ");
		scanf("%d",&pos);
		if(pos>length+1 && pos<1)
		{
			printf("Invalid Position!\n");
		}
		else if(pos==1)
		{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
		else if(pos==length+1)
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->prev=temp;
		}
		else
		{
			temp=head;
			while(k<pos-1)
			{
				temp=temp->next;
			}
			ptr=temp->next;
			newNode->next=ptr;
			ptr->prev=newNode;
			temp->next=newNode;
			newNode->prev=temp;
		}
	}
	traversal();
}

void deleteInBegin()
{
	if(head==NULL)
	{
		printf("Underflow!\n");
	}
	else
	{
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
		}
		else
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
		}
	}
	traversal();
}

void deleteAtEnd()
{
	if(head==NULL)
	{
		printf("Underflow!\n");
	}
	else
	{
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
		}
		else
		{
			temp=head;
			ptr=temp->next;
			while(ptr->next!=NULL)
			{
				temp=temp->next;
				ptr=ptr->next;
			}
			ptr->prev=NULL;
			free(ptr);
			temp->next=NULL;
		}
	}
	traversal();
}

void deleteRandom()
{
	int length=0,k=1,pos;
	if(head==NULL)
	{
		printf("Underflow!\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			temp=temp->next;
			length++;
		}
		printf("Enter Position: ");
		scanf("%d",&pos);
		if(pos>length && pos<1)
		{
			printf("Invalid Position!\n");
		}
		else if(pos==1)
		{
			if(head->next==NULL)
			{
				free(head);
				head=NULL;
			}
			else
			{
				temp=head;
				head=head->next;
				head->prev=NULL;
			}
		}
		else if(pos==length)
		{
			if(head->next==NULL)
			{
				free(head);
				head=NULL;
			}
			else
			{
				temp=head;
				ptr=temp->next;
				while(ptr->next!=NULL)
				{
					temp=temp->next;
					ptr=ptr->next;
				}
				ptr->prev=NULL;
				free(ptr);
				temp->next=NULL;
			}
		}
		else
		{
			temp=head;
			while(k<pos-1)
			{
				temp=temp->next;
			}
			ptr=temp->next;
			temp->next=ptr->next;
			ptr->next->prev=temp;
			ptr->next=NULL;
			ptr->prev=NULL;
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
	printf("\t\t\t****** Doubly Linked List ******\n\n");
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
			default: printf("\nInvalid Choice!\n");
				break;
		}
	}while(ch=='Y' || ch=='y');
	getch();
}