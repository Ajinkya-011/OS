#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
	int fd1,fd2;
	char * fifo1="fifo1";
	char * fifo2="fifo2";
	mkfifo(fifo1,0666);
	mkfifo(fifo2,0666);
	while(1)
	{
		FILE * fp;
		fd1=open(fifo1,O_WRONLY);
		fp=fdopen(fd1,"w");
		char sent[100];
		printf("Enter Sentence:");
		fgets(sent,sizeof(sent),stdin);
		fprintf(fp,"%s",sent);
		fclose(fp);
		
		fd2=open(fifo2,O_RDONLY);
		fp=fdopen(fd2,"r");
		char cont[100];
		fgets(cont,sizeof(cont),fp);
		printf("%s",cont);
		fclose(fp);
		return 0;
	}
}
