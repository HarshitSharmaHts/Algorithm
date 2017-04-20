/*
 * Program to calculate average turnaround time and average waiting time 
 *of the processes using preemptive shortest remaining time first algorithm
 *Input  :  -> 1: Arival Time of Process
            -> 2: CPU Burst time
            
 *Output :  -> 1: Average turn around time
            -> 2: Average Waiting time
 */

#include<stdio.h>

// Structure for process details
typedef struct 
{
        int AT;         //Arival time
        int BT;         //Burst time
        int RT;		//Remaining time
        int CT;         //Complition time
        int temp;       //Holds BT
}PROCESS;

void fill_CT(PROCESS [], int);
void get_process(PROCESS [], int);
void print_process(PROCESS [], int);
void avg_TAT_WT(PROCESS [], int);

int main()
{
        PROCESS p[80];
        int num;
        printf("Enter the number of process   :   ");
        scanf("%d",&num);
        get_process(p,num);
        fill_CT(p,num);
        print_process(p,num);
        avg_TAT_WT(p,num);
        return 0;
}

// fill_CT function to calculate total complition time of process
void fill_CT(PROCESS p[], int number)
{
        p[number].RT=9999;
        int i,j,k,l,count=0;
        for(i=0;count!=number;i++)
        {
                k=number;
                for(j=0;j<number;j++)
                {
                	if(p[j].temp==0)
                	continue;
                	p[j].RT=p[j].temp-i;
                }
                for(j=0;j<number;j++)
                {
                        if(p[j].AT<=i && p[j].RT<p[k].RT && p[j].temp!=0)
                        k=j;
                }
                p[k].temp--;
                if(p[k].temp==0)
                {
                        count++;
                        p[k].CT=(i+1);
                }
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
}// avg_TAT_WT()
/*
 * Author :- Harshit Sharma
 * Date : 10/04/2017
 */
