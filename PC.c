#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int buff[5];
int in=0,out=0;
sem_t s,e,f;

void * producer(void* arg)
{
	int v;
	sem_wait(&e);
	sem_wait(&s);
	printf("\nEnter Value:");
	scanf("%d",&v);
	buff[in]=v;
	printf("Producer is Producing:%d",v);
	in=(in+1)%5;
	sem_post(&s);
	sem_post(&f);
}

void * consumer(void * arg)
{
	int cont;
	int v;
	do
	{
		sem_wait(&f);
		sem_wait(&s);
		v=buff[out];
		printf("\nConsumer is consuming:%d",v);
		out=(out+1)%5;
		sem_post(&s);
		sem_post(&e);
		sem_getvalue(&e,&cont);
	}while(cont!=5);
}

int main()
{
	pthread_t pid[5],cid;
	sem_init(&s,0,1);
	sem_init(&f,0,0);
	sem_init(&e,0,5);
	for(int i=0;i<5;i++)
	{
		pthread_create(&pid[i],NULL,producer,NULL);
	}
	pthread_create(&cid,NULL,consumer,NULL);
	for(int i=0;i<5;i++)
	{
		pthread_join(pid[i],NULL);
	}
	pthread_join(cid,NULL);
}
	
	
