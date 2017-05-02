/*
 * program to implement Graph using adjacency list representation
 * Input  : -> Number of vertices
 *	    -> Edge between src vertex to dest vertex
 * Output : -> Adjacency list for each vertex
 */

#include<stdio.h>
#include<malloc.h>

// node contains destination vertex
struct Node
{
	int dest;		// destination vertex
	struct Node* next;	// pointer to next node of the adjacency list 
};// End struct Node

typedef struct
{
	struct Node* head;
}AdjList;

// Graph contains vertex and list of Adjacency vertex
typedef struct
{
	int size;
	AdjList *list;		// array of AdjList
}Graph;// End struct Graph

Graph* creategraph();
struct Node* createnode(int);
void Edge(Graph*, int,int);
void getEdge(Graph*);
void print(Graph*);

// Driver Function
int main()
{
	Graph* G=creategraph();
	getEdge(G);
	print(G);
	return 0;
}

// funtion createnode to make a node with destination vertex
struct Node* createnode(int val)
{
	struct Node* new=(struct Node*)malloc(sizeof(struct Node));
	new->dest=val;
	new->next=NULL;
	return new;
}// End createnode()

// function creategraph to make an graph with vertex initialized with NULL
Graph* creategraph()
{
	int V;
	printf("Enter number of vertices   :   ");
	scanf("%d",&V);
	Graph* G=(Graph*)malloc(sizeof(Graph));
	G->size=V;
	G->list=(AdjList*)malloc(V*sizeof(AdjList));
	int i;
	for(i=0;i<V;i++)
		G->list[i].head=NULL;
	return G;
}// End creategraph()

// function to add an Edge between src and dest
void Edge(Graph* G, int src,int dest)
{
	struct Node* new=createnode(dest);
	new->next = G->list[src].head;
	G->list[src].head=new;
}// End Edge()

// function to get Edge
void getEdge(Graph*G)
{
	while(1)
	{
		int src,dest;
		printf("Edge (Press -1 -1 to stop)   :   ");
		scanf("%d%d",&src,&dest);
		if(src==-1 && dest==-1)
			return;
		Edge(G,src,dest);
	}
}// End getEdge()

// funtion print to display graph
void print(Graph* G)
{
	int V;
	printf("\n***Adjacency List's for Each vertex***\n");
	for(V=0;V<G->size;V++)
	{
		printf("|%d|",V);
		struct Node* ptr= G->list[V].head;
		while(ptr)
		{
			printf("->%d",ptr->dest);
			ptr=ptr->next;
		}
		printf("\n");
	}
}// End print()
/*
 * Author : Harshit Sharma
 */
