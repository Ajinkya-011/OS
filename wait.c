#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

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
void binarysearch(int a[],int n,int low,int high,int key)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==key)
		{
			printf("Element is found.!!\n");
		}
		else if(a[mid]<key)
		{
			binarysearch(a,n,mid+1,high,key);
		}
		else
		{
			binarysearch(a,n,low,mid-1,key);
		}
	}
	else
	{
		printf("Element is not found.!!\n");
	}
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
	int key;
	printf("Enter the element to search:");
	scanf("%d",&key);
	pid_t ID=fork();
	if(ID==0)
	{
		printf("Child process is created..!\n");
		printf("Child process id is:%d\n",getpid());
		printf("Child process sorting the numbers in ascending order.\n");
		ascending(a,n);
		printf("\n");
		
	}
	else
	{
		wait(NULL);
		printf("Parent process is created..!\n");
		printf("Parent process id is:%d\n",getpid());
		printf("Parent process search the number:\n");
		
		binarysearch(a,n,0,n-1,key);
		printf("\n");		
	}
}
