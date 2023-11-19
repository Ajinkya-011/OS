#include <stdio.h>

int main()
{
	int r,p;
	printf("Enter no. of processes: ");
	scanf("%d", &p);
	printf("Enter no. of resources: ");
	scanf("%d", &r);
	
	int max[p][r];
	int alloc[p][r];
	int avail[r];
	int need[p][r];
	
	printf("Enter max. resources for each process: ");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			scanf("%d", &max[i][j]);
		}
	}
	
	printf("Enter alloc. resources for each process: ");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			scanf("%d", &alloc[i][j]);
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	printf("Enter avail. resources for each process: ");
	for(int i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}	
	
	int work[r];
	int finish[p];
	
	for(int i=0;i<r;i++)
	{
		work[i]=avail[i];
	}
	for(int i=0;i<p;i++)
	{
		finish[i]=0;
	}
	
	int ss[p];
	int count=0;
	
	while(count<p)
	{
		int round=0;
		for(int i=0;i<p;i++)
		{
			if(finish[i]==0)
			{
				int j;
				for( j=0;j<r;j++)
				{
					if(need[i][j]>work[j])
					break;
				}
				if(j==r)
				{
					for(int k=0;k<r;k++)
					{
						work[k]+=alloc[i][k];
						ss[count++]=i;
						finish[i]=1;
						round=1;
					}
				}
			}
		}
		if(round==0)
		{
			printf("System is in safe state.");
			return 0;
		}
	}
	printf("System is in safe state");
	printf("Safe State:");
	for(int i=0;i<p;i++)
	{
		printf("%d",ss[i]);
	}
	printf("\n");
	return 0;
} 
