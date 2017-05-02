/*
 * Program to implement Kruskal's Algorithm
 *
 *Input : -> 1. Number of vertex in graph
 *	  -> 2. Number of edges in graph
 *	  -> 3. weight, source and destination vertex for each edge
 *
 *Output: -> 1. Edge's detail of Minimum-spanning-tree
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

// structure for Edge
struct Edge
{
	struct Node* src;
	struct Node* dest;
	int w,s,d,no;
};// End Edge

/*-----------Function's Prototype START--------------*/
struct Node* MAKE_SET(int);
struct Node_header* FIND_SET(struct Node*);
void UNION(struct Node*, struct Node*);
void sort(struct Edge [], int);
void getEdges(struct Edge [],struct Node* [],int);
void printEdge(struct Edge);
void kruskal(int , int);
/*-----------Function's Prototype END--------------*/


// Driver function main
int main()
{
	int V,E;
	printf("Enter the number of vertex in graph   :   ");
	scanf("%d",&V);
	printf("Enter the number of edges in graph    :   ");
	scanf("%d",&E);
	kruskal(V,E);
	return 0;
}// End main()

// function to create new node which represent it self
struct Node* MAKE_SET(int value)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node_header* new_header=(struct Node_header*)malloc(sizeof(struct Node_header));
	new_node->value=value;
	new_node->next=NULL;
	new_node->rep=new_header;
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

// bubble sorting funtion 
void sort(struct Edge arr[], int n)
{
	int i,j=1,flag;
	do
	{
		flag=0;
		for(i=0;i<n-j; i++)
			if(arr[i].w>arr[i+1].w)
			{
				flag=1;
				struct Edge temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
	j++;
	}while(flag);
}// End bubble()

// function to store Edges weight, src and dest in array
void getEdges(struct Edge e[],struct Node* v[],int ne)
{
	int i;
	for(i=0;i<ne;i++)
	{
		printf("Edge [%d]\n",i+1);
		printf("-----------------\n");
		printf("Source   :   ");
		scanf("%d",&e[i].s);
		printf("Destina  :   ");
		scanf("%d",&e[i].d);
		printf("Weight   :   ");
		scanf("%d",&e[i].w);
		printf("-----------------\n");
		e[i].no=i+1;
		e[i].src=v[e[i].s];			//putting source Node
		e[i].dest=v[e[i].d];			//putting destination Node
	}
}// End getEdges()

// function to display Edge's attribute
void printEdge(struct Edge E)
{
	printf("Edge [%d]\n",E.no);
	printf("-----------------\n");
	printf("Source   :   %d\n",E.s);
	printf("Destina  :   %d\n",E.d);
	printf("Weight   :   %d\n",E.w);
	printf("-----------------\n");
}// End printEdge()

// function of kruskal's algorithm
void kruskal(int nv, int ne)
{
	int i;
	struct Node* v[nv];
	struct Edge e[ne];
	for(i=0;i<nv;i++)
		v[i]=MAKE_SET(i);
	getEdges(e,v,ne);
	sort(e,ne);
	printf("\n\n***Edges of MST***\n");
	for(i=0;i<ne;i++)
	{
		if(FIND_SET(e[i].src) != FIND_SET(e[i].dest))
		{
			UNION(e[i].src,e[i].dest);
			printEdge(e[i]);
		}
	}
}// End kruskal()
/*
 * Author : Harshit Sharma
 */
