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

void sjf(struct Process pro[],int n)
{
	int current=0;
	int completed=0;
	int shortest;
	while(completed<n)
	{
		shortest=-1;
		int minsert=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(pro[i].at<=current && pro[i].rt>0 && pro[i].st<minsert)
			{
				shortest=i;
				minsert=pro[i].st;
			}
		}
		if(shortest==-1)
		{
			current++;
		}
		else
		{
			pro[shortest].rt--;
			current++;
			if(pro[shortest].rt==0)
			{
				completed++;
				pro[shortest].tat=current-pro[shortest].at;
				pro[shortest].wt=pro[shortest].tat-pro[shortest].st;
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter Number of Process:");
	scanf("%d",&n);
	
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
	
	sjf(pro,n);
	printf("Process\tArrival TIme\tService Time\tWaiting Time\tTurn Around Time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",pro[i].id,pro[i].at,pro[i].st,pro[i].wt,pro[i].tat);
	}
}
