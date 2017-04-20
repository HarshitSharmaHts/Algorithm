/*
 * Program to calculate average turnaround time and average waiting time 
 *of the processes using Shortest job first (SJF) algorithm
 *Input  :  -> 1: Arival Time of Process
            -> 2: CPU Burst time
            
 *Output :  -> 1: Average turn around time
            -> 2: Average Waiting time
 */
 
#include<stdio.h>

typedef struct 
{
        int AT;         //Arival time
        int BT;         //Burst time
        int CT;         //Complition Time
        int flag;
}PROCESS;

void fill_CT(PROCESS [], int);
void get_process(PROCESS [], int);
void print_process(PROCESS [], int);
void avg_TAT_WT(PROCESS [], int);

int main()
{
        int num;
        printf("Enter the number of process   :   ");
        scanf("%d",&num);
                PROCESS p[num];
        get_process(p,num);
        fill_CT(p,num);
        print_process(p,num);
        avg_TAT_WT(p,num);
        return 0;
}

// fill_CT function to calculate total complition time of process
void fill_CT(PROCESS p[], int number)
{
        p[number].BT=9999;
        int j,k,l,count=0,time=0;
        while(count!=number)
        {
                k=number;
                for(j=0;j<number;j++)
                {
                        if(p[j].AT<=time && p[j].BT<p[k].BT && p[j].flag!=1)
                        k=j;
                }
                if(p[k].flag!=1)
                {
                	p[k].flag=1;
                	time=time+p[k].BT;
                	p[k].CT=time;
                	count++;
                }
                else time++;
        }
        return;
}// End fill_CT()

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
                p[i].flag=0;
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
}// avg_TAT_WT()

/*
 * Author :- Harshit Sharma
 * Date : 18/04/2017
 */
