/*
 * implementation of Floyd's algorithm to find shortest path
 * Input  : -> Number of vertices
 	    	-> Weight beetween edges
 * Output : -> Distance beetween entered vertices
 			-> Path
 */

#include<stdio.h>

void path(int start , int end, int S[][100])
{
	int i=start-1,j=end-1;
	printf("%d ",start);
	int k=S[i][j];
	while(k!=end)
	{
		printf("--> %d",k);
		k=S[k-1][j];
	}
	printf(" --> %d",end);
}

void floyds(int D[][100], int S[][100], int v)
{
	for(int k=0;k<v;k++)
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				if(D[i][j] > D[i][k]+D[k][j])
				{
					D[i][j]=D[i][k]+D[k][j];
					S[i][j]=k+1;
				}
}

int main()
{
	int v;
	int D[100][100],S[100][100];
	printf("Enter the number of vertices : ");
	scanf("%d",&v);
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
		{
			if(i==j)
			{
				S[i][j]=0;
				D[i][j]=0;
			}
			else
			{
				printf("Edge %d , %d  :  ",i+1,j+1);
				scanf("%d",&D[i][j]);
				S[i][j]=j+1;
			}
		}
	floyds(D,S,v);
	int a,b;
	while(1)
	{
		printf("Enter two vertex (-1 for stop)    :   ");
		scanf("%d%d",&a,&b);
		if(a==-1 || b==-1)
			break;
		printf("\n+-----------------------------------------------+\n");
		printf("Shortest distance between %d and %d is   :   %d\nShortest path   :   ",a,b,D[a-1][b-1]);
		path(a,b,S);
		printf("\n+-----------------------------------------------+\n");
	}
	return 0;
}
/*
 * Author : Harshit Sharma
 * Date   : 11 Jun 2017
 */
