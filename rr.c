#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Process
{
	int id;
	int at;
	int st;
	int wt;
	int tat;
	int rt;
};

void rr(struct Process pro[],int n,int quantum)
{
	int current=0;
	int completed=0;
	while(completed<n)
	{
		for(int i=0;i<n;i++)
		{
			if(pro[i].at<=current && pro[i].rt>0)
			{
				if(pro[i].rt<=quantum)
				{
					current+=pro[i].rt;
					pro[i].rt=0;
					completed++;
				}
				else
				{
					current+=quantum;
					pro[i].rt-=quantum;
				}
				pro[i].tat=current-pro[i].at;
				pro[i].wt=pro[i].tat-pro[i].st;
				if (pro[i].wt < 0) 
				{
                    			pro[i].wt = 0;
				}
			}
		}
	}
}

int main()
{
	int n,quantum;
	printf("Enter Number of Process:");
	scanf("%d",&n);
	printf("Enter the time quantum: ");
    	scanf("%d", &quantum);
	
	struct Process pro[n];
	for(int i=0;i<n;i++)
	{
		pro[i].id=i+1;
		printf("Enter Arrival Time for%d",i+1);
		scanf("%d",&pro[i].at);
		printf("Enter Service Time for%d",i+1);
		scanf("%d",&pro[i].st);
		pro[i].rt=pro[i].st;
	}
	
	rr(pro,n,quantum);
	printf("Process\tArrival TIme\tService Time\tWaiting Time\tTurn Around Time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",pro[i].id,pro[i].at,pro[i].st,pro[i].wt,pro[i].tat);
	}
}
