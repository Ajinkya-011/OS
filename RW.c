#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t r,w;
int rdcnt=0;

void * reader()
{
	sem_wait(&r);
	rdcnt++;
	if(rdcnt==1)
	{
		sem_wait(&w);
	}
	sem_post(&r);
	printf("\nReader is Reading");
	sem_wait(&r);
	rdcnt--;
	if(rdcnt==0)
	{
		sem_post(&w);
	}
	sem_post(&r);
}

void * writer()
{
	sem_wait(&w);
	printf("\nWriter is Writing");
	sem_post(&w);
}

int main()
{
pthread_t rid[3];
pthread_t wid[3];
sem_init(&r , 0 ,1);
sem_init(&w,0,1);

for(int i=0;i<3;i++)
{
	pthread_create(&rid[i],NULL,reader,NULL);
	pthread_create(&wid[i],NULL,writer,NULL);
}
for(int i=0;i<3;i++)
{
	pthread_join(rid[i],NULL);
	pthread_join(wid[i],NULL);
}
}
