// XOR LINKEDLIST - A memory efficient linkedList...

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *npx;	
};

struct node* XOR(struct node* prev, struct node* nxt)
{
	return (struct node*)((unsigned int)(prev) ^ (unsigned int)(nxt));
}

void insertfirst(struct node **head_ref, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	temp->npx = XOR(NULL, *head_ref);
	
	if(*head_ref != NULL)
	{
		struct node* next = XOR(NULL, (*head_ref)->npx);
		(*head_ref)->npx = XOR(temp, next);
	}
	
	*head_ref = temp;
}

void printlist(struct node *head)
{
	struct node *curr = head;
	struct node *prev = NULL;
	struct node *next = XOR(curr->npx, NULL);
	
	while(next!=NULL)
	{
		printf("%d ", curr->data);
		
		prev = curr;
		curr = next;
		next = XOR(curr->npx, prev);
		
	}
	
	printf("%d ", curr->data);
	
	
}

int main()
{
	struct node* head = NULL;
	
	insertfirst(&head, 10);
	insertfirst(&head, 20);
	insertfirst(&head, 30);
	insertfirst(&head, 40);
	insertfirst(&head, 50);
	
	printlist(head);
	
	return 0;
}
