
// Double Linked List Insert, Delete , Forward Print, Reverse Print

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* prev;
	ListNode* next;
};

ListNode* head,*t;

ListNode* InsertNewNode(int x)
{
	ListNode* t=(ListNode*)malloc(sizeof(ListNode));
	t->val=x;
	t->prev=NULL;
	t->next=NULL;

	return t;
}

void InsertAtHead(int x)
{
	ListNode* NewNode= InsertNewNode(x);

	if(head==NULL)
	{
		head=NewNode;
		t=head;
		return;
	}


	head->prev=NewNode;
	NewNode->next=head;
	head=NewNode;
}

void InsertAtTail(int x)
{
	ListNode* NewNode=InsertNewNode(x);

	t->next=NewNode;
	NewNode->prev=t;
	t=NewNode;
}

void Delete(int x)
{
	ListNode* p=head;
	while(p!=NULL)
	{
		if(p->val==x)
		{
			if(p==head)// delete head node
			{
				head=p->next;
				return;
			}
			if(p==t) //delete last node
			{
				p->prev->next=NULL;
				return;
			}
			p->prev->next=p->next;
			p->next->prev=p->prev;
			return;
		}
		p=p->next;
	}
}

//Forward Print
void Print()
{
	ListNode* t=head;
	while(t!=NULL)
	{
		printf("%d ",t->val);
		t=t->next;
	}
	printf("\n");
}

//Reverse Print
void Reverse_Print()
{
	ListNode* t=head;
	while(t->next!=NULL)
	{
		//printf("%d",t->val);
		t=t->next;
	}

	while(t!=NULL)
	{
		printf("%d ",t->val);
		t=t->prev;
	}
	printf("\n");
}


int main()
{
	head=NULL;
	InsertAtHead(2);
	InsertAtHead(5);

	InsertAtTail(12);

	InsertAtHead(7);

	InsertAtTail(13);
	InsertAtTail(14);
	InsertAtTail(15);
	InsertAtTail(16);
	InsertAtTail(17);

	Print();
	Delete(13);

	Print();
	Delete(2);

	Print();
	Delete(17);

	Print();

	Reverse_Print();


	return 0;
	
}