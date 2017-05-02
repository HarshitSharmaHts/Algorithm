/*
 * Program to implement UNION-FIND disjoint datastructure
 */

#include<stdio.h>
#include<malloc.h>

// structure node
struct Node
{
	struct Node_header* rep;
	struct Node* next;
	int value;
};// End struct Node

// structure for header node
struct Node_header
{
	struct Node* head;
	struct Node* tail;
	int count;
};// End struct Node_header


struct Node* MAKE_SET(int);
struct Node_header* FIND_SET(struct Node*);
void UNION(struct Node*, struct Node*);
void print(struct Node*);

// Driver function main
int main()
{
	struct Node* a=MAKE_SET(1);
	struct Node* b=MAKE_SET(2);
	struct Node* c=MAKE_SET(3);
	struct Node* d=MAKE_SET(4);
	struct Node* e=MAKE_SET(5);
	UNION(a,b);
	UNION(b,c);
	UNION(d,e);
	UNION(c,d);
	print(a);
	return 0;
}

// function to create new node which represent it self
struct Node* MAKE_SET(int value)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node_header* new_header=(struct Node_header*)malloc(sizeof(struct Node_header));
	new_node->value=value;
	new_node->rep=new_header;
	new_node->next=NULL:
	new_header->count=1;
	new_header->head=new_node;
	new_header->tail=new_node;
	return new_node;
}// End MAKE_SET()

// function to find representative node of given node
struct Node_header* FIND_SET(struct Node* f)
{
	return f->rep;
}// End FIND_SET()

//function to put two node in same list
void UNION(struct Node* a, struct Node* b)
{
	struct Node_header* ptr1= FIND_SET(a);
	struct Node_header* ptr2= FIND_SET(b);
	if(ptr1->count>ptr2->count)
	{
		ptr1->count+=ptr2->count;
		ptr1->tail->next=ptr2->head;
		ptr1->tail=ptr2->tail;
		struct Node* temp = ptr2->head;
		while(temp)
		{
			temp->rep=ptr1;
			temp=temp->next;
		}
		free(ptr2);
	}
	else
	{
		ptr2->count+=ptr1->count;
		ptr2->tail->next=ptr1->head;
		ptr2->tail=ptr1->tail;
		struct Node* temp = ptr1->head;
		while(temp)
		{
			temp->rep=ptr2;
			temp=temp->next;
		}
		free(ptr1);
	}
}// End UNION()

// funtion print to display all element of Same Set
void print(struct Node* ptr)
{
	struct Node* temp = ptr->rep->head;
	while(temp)
	{
		printf("%d   ",temp->value);
		temp=temp->next;
	}
	printf("\n\n");
}// End print()
/*
 * Author : Harshit Sharma
 */
