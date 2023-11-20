#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


void display(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}	
}
void ascending(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Ascending order is:");
	display(a,n);
}
void descending(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("descending order is:");
	display(a,n);
}

int main()
{
	int n;
	printf("Enter the total numbers:");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the numbers:");
		scanf("%d",&a[i]);
	}
	printf("Printing Numbers:");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	pid_t ID=fork();
	if(ID==0)
	{
		sleep(10);
		printf("Child process is created..\n");
		printf("Child process id is:%d\n",getpid());
		printf("child sorting array in ascending order:\n");
		ascending(a,n);
		printf("\n");
		
	}
	else
	{
		printf("Parent process is created..\n");
		printf("Parent process id is:%d\n",getpid());
		printf("Parent sorting array in descending order:\n");
		descending(a,n);
		printf("\n");
	}
	
}
