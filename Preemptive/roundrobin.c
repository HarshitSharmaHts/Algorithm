/*
 * Program to calculate average turnaround time and average waiting time 
 *of the processes using round robin algorithm
 *Input  :  -> 1: Arival Time of Process
            -> 2: CPU Burst time
            -> 3: Time Quantum
            
 *Output :  -> 1: Average turn around time
            -> 2: Average Waiting time
 */
#include<stdio.h>

typedef struct
{
	int AT;		//Arival Time
	int BT;		//Burst Time
	int CT;		//Complition TIme
	int temp;	//holds BT
}PROCESS;

int front=-1,rear=-1;	//Circular Queue's front and rear

void enQueue(int [],int ,int);
int deQueue(int [],int);
void fill_CT(PROCESS [], int, int);
void get_process(PROCESS [], int);
void print_process(PROCESS [], int);
void avg_TAT_WT(PROCESS [], int);

int main()
{
        int num,q;
        printf("Enter the number of process   :   ");
        scanf("%d",&num);
        PROCESS p[num];
        get_process(p,num);
        printf("Enter the time Quantum        :   ");
        scanf("%d",&q);
        fill_CT(p,num,q);
        print_process(p,num);
        avg_TAT_WT(p,num);
        return 0;
}

//enQueue to put Process number in Ready Queue
void enQueue(int cq[],int value,int SIZE)
{
   if((front == 0 && rear == SIZE - 1) || (front == rear+1))
      printf("\nProcess Limit Exceed!!!\n");
   else{
      if(rear == SIZE-1 && front != 0)
	 rear = -1;
      cq[++rear] = value;
      if(front == -1)
	 front = 0;
   }
}//End enQueue()

//deQueue to get process which comes first in ready Queue
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
}//End deQueue()

// get_process function to scan required information of process 
void get_process(PROCESS p[], int n_of_p)
{
        int i;
        for(i=0;i<n_of_p;i++)
        {
                printf("----------------------------------------------------\n");
                printf("Enter details of Process P[%d]\n",i+1);
                printf("----------------------------------------------------\n");
                printf("Arival Time   :   ");
                scanf("%d",&p[i].AT);
                printf("Burst Time    :   ");
                scanf("%d",&p[i].BT);
                p[i].temp=p[i].BT;
        }
        printf("----------------------------------------------------\n");
        return;
}// End get_process()

// print_process funtion to print details of process
void print_process(PROCESS p[], int n_of_p)
{
        int i;
        printf("----------------------------------------------------\n");
        printf("Process     | Arival Time | Burst Time  \n");
        for(i=0;i<n_of_p;i++)
        {
                printf("P[%d]",i+1);
                printf("%13d",p[i].AT);
                printf("%13d\n",p[i].BT);
        }
        printf("----------------------------------------------------\n");
        return;
}// End print_process()

// avg_TAT_WT funtion to calculate average Turn Around Time and Waiting Time
void avg_TAT_WT(PROCESS p[], int n_of_p)
{
        int i;
        float TAT=0.00,WT=0.00;
        for(i=0;i<n_of_p;i++)
        {
                TAT=TAT+p[i].CT - p[i].AT;
                WT =WT +p[i].CT - p[i].AT-p[i].BT;
        }
        printf("----------------------------------------------------\n");
        printf("Average Turn Around Time   :   %7.3f\n",TAT/n_of_p);
        printf("Average Waiting Time       :   %7.3f\n",WT/n_of_p);
        printf("----------------------------------------------------\n");
}//End avg_TAT_WT()

// fill_CT function to calculate total complition time of process
void fill_CT(PROCESS p[],int nu_of_p,int TQ)
{
	int ready_Q[nu_of_p];
	int i=0,j,r,time=0;
	while(1)
	{
		for(j=0;j<nu_of_p;j++)
		{
			if(p[j].AT==time && p[j].temp!=0)
			enQueue(ready_Q,j,nu_of_p);
		}
		if(time==0)
		r=deQueue(ready_Q,nu_of_p);
		if(p[r].temp==0)
		{
			i=TQ;
			p[r].CT=time;
		}
		if(i==TQ)
		{
			i=0;
			if(p[r].temp!=0)
				enQueue(ready_Q,r,nu_of_p);
			r=deQueue(ready_Q,nu_of_p);
			if(r==-1)
			break;
		}
		p[r].temp--;
		i++;
		time++;
	}
}//End fill_CT()
/*
 * Author : Harshit Sharma
 *Written Date : 12/04/2017
 *Upload Date  : 18/04/2017
 */
