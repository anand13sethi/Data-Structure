//Deleting Elements From Linked List
// 1. From the Begining
// 2. At the End
// 3. Arbitrary Position

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
	if(head==NULL)
	{
		printf("Linked List Is Empty\n");
	}
	else
	{
		printf("\t\t\nPrinting Linked List\n");
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

void deletionInBegin()
{
	if(head==NULL)
	{
		printf("Underflow!\n");
		getch();
	}
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
		printf("Element Deleted Succesfully\n");
		traversal();
	}
}

void deletionAtEnd()
{
	if(head==NULL)
	{
		printf("Underflow!\n");
		getch();
	}
	else
	{
		temp=head;
		ptr=temp->next;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			temp=temp->next;
		}
		temp->next=NULL;
		free(ptr);
		printf("Element Deleted Succesfully\n");
		traversal();
	}
}

void deletionRandom()
{
	int pos,length=0,k=1;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		length++;
	}
	printf("Enter Position: ");
	scanf("%d",&pos);
	if(pos > length || pos < 0)
	{
		printf("Invalid Position!");
		getch();
	}
	else
	{
		if(pos==1)
		{
			deletionInBegin();
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
			printf("Element Deleted Succesfully\n");
			traversal();
		}
	}
}

void main()
{
	clrscr();
	int info,choice;
	char ch,ch1;
	printf("\t\t\t****** Linked List Program No. 2 ******\n\n");
	point:
	do
	{
		printf("\t\t****** Creation Of Linked List ******\n");
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Enter Information: ");
		scanf("%d",&info);
		newNode->data=info;
		newNode->next=NULL;
		if(head==NULL)
		{
			printf("\t\tInserting 1st Element In The List\n");
			head=newNode;
			traversal();
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			traversal();
		}
		printf("\n\nAdd More Nodes To the LInked List?(Y/N): ");
		scanf("%s",&ch1);
	}while(ch1=='y' || ch1=='Y');
	do
	{
		printf("\n\n1. Deletion in the Begining\n");
		printf("2. Deletion at the End\n");
		printf("3. Deletion of Arbitrary Element\n");
		printf("4. Insert Elemts into Linked List\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: deletionInBegin();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 2: deletionAtEnd();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 3: deletionRandom();
				printf("\nDo You Want To Continue?(Y/N): ");
				scanf("%s",&ch);
				break;
			case 4: goto point;
			default: printf("\nInvalid Choice!");
				break;
		}
	}while(ch=='y' || ch=='Y');
	getch();
}