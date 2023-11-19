#include<stdio.h>
#include<stdlib.h>

void print(int frames[],int fs)
{
	for(int i=0;i<fs;i++)
	{
		if(frames[i]==-1)
		{
			printf("X");
		}
		else
		{
			printf("%d",frames[i]);
		}
	}
	printf("\n");
}

void fcfs(int pages[],int fs,int n)
{
	int frames[fs];
	int counter=0;
	int pf=0;
	for(int i=0;i<fs;i++)
	{
		frames[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		int pexist=0;
		for(int j=0;j<fs;j++)
		{
			if(frames[j]==pages[i])
			{
				pexist=1;
				break;
			}
		}
		if(pexist==0)
		{
			frames[counter]=pages[i];
			counter++;
			pf++;
			if(counter>=fs)
			{
				counter=0;
			}
		}
		printf("Frames");
		print(frames,fs);
	}
	printf("Page Faults=%d\n",pf);
}

void lru(int pages[],int fs,int n)
{
	int frames[fs];
	int counter=0;
	int pf=0;
	int recent[]={-1,-1,-1};
	for(int i=0;i<fs;i++)
	{
		frames[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		int pexist=0;
		for(int j=0;j<fs;j++)
		{
			if(frames[j]==pages[i])
			{
				pexist=1;
				recent[j]=i;
				break;
			}
		}
		if(pexist==0)
		{
			int lri=0;
			for(int j=1;j<fs;j++)
			{
				if(recent[j]==recent[lri])
				{
					lri=j;
				}
			}
			frames[lri]=pages[i];
			recent[lri]=i;
			pf++;
		}
		printf("Frames");
		print(frames,fs);
	}
	printf("Page Faults:%d\n",pf);
}
				
void optimal(int pages[],int fs,int n)
{
	int frames[fs];
	int pf=0;
	for(int i=0;i<fs;i++)
	{
		frames[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		int pexist=0;
		for(int j=0;j<fs;j++)
		{
			if(frames[j]==pages[i])
			{
				pexist=1;
				break;
			}
		}
		if(pexist==0)
		{
			int maxD=-1;
			int rIndex=-1;
			for(int j=0;j<fs;j++)
			{
				int fIndex=0;
				for(int k=i+1;k<20;k++)
				{
					if(frames[j]==pages[k])
					{
						fIndex=k;
						break;
					}
				}
				if(fIndex==0)
				{
					rIndex=j;
					break;
				}
				else
				{
					if(fIndex>maxD)
					{
						maxD=fIndex;
						rIndex=j;
					}
				}
			}
			frames[rIndex]=pages[i];
			pf++;
		}
		printf("Frames:\n");
		print(frames,fs);
	}
	printf("Page Faults:%d",pf);
}
		
int main()
{
	int pages[20];
	int n;
	printf("Enter Size of String:");
	scanf("%d",&n);
	printf("Enter Reference String:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pages[i]);
	}
	int fs=3;
	fcfs(pages,fs,n);
	lru(pages,fs,n);
	optimal(pages,fs,n);
	return 0;
}
	
