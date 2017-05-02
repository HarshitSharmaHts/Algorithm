/*
 * program to implement breadth-first-search traversal
 * Input  : -> Number of vertices
 	    -> Edge between src vertex to dest vertex
 * Output : -> BFS traversed path
 */

#include<stdio.h>
#include<malloc.h>

int front=-1,rear=-1;

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

void enQueue(int [],int ,int);
int deQueue(int [],int);
struct Node* createnode(int);
Graph* creategraph();
void Edge(Graph*, int ,int);
void getEdge(Graph*);
void BFS(Graph*);

// Driver function
int main()
{
	Graph* G=creategraph();
	getEdge(G);
	BFS(G);
	return 0;
}

// funtion to append element at tail
void enQueue(int cq[],int value,int SIZE)
{
   if((front == 0 && rear == SIZE - 1) || (front == rear+1))
      printf("\nOverflow!!!\n");
   else{
      if(rear == SIZE-1 && front != 0)
	 rear = -1;
      cq[++rear] = value;
      if(front == -1)
	 front = 0;
   }
}// End enQueue()

// function to remove element from front
int deQueue(int cq[],int SIZE)
{
	int temp;
   if(front == -1 && rear == -1)
      return -1;
   else{
      temp=cq[front++];
      if(front == SIZE)
	 front = 0;
      if(front-1 == rear)
	 front = rear = -1;
   }
   return temp;
}// End deQueue()

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

// function to print one possible BFS traversal
void BFS(Graph* G)
{
	int visited[G->size];
	int queue[G->size];
	int i,s;
	printf("Enter the starting vertex   :    ");
	scanf("%d",&s);
	for(i=0;i<G->size;i++)
		visited[i]=0;
	visited[s]=1;
	enQueue(queue,s,G->size);
	printf("\n***BFS traversal (Starting Vertex is %d)***\n",s);
	while(!(front == -1 && rear == -1))
	{
		int u=deQueue(queue,G->size);
		printf("%d  ",u);
		struct Node* ptr=G->list[u].head;
		while(ptr)
		{
			if(visited[ptr->dest]==0)
			{
				visited[ptr->dest]=1;
				enQueue(queue,ptr->dest,G->size);
			}
			ptr=ptr->next;
		}
		visited[u]=1;
	}
	printf("\n");
}// End BFS()
/*
 * Author : Harshit Sharma
 */
