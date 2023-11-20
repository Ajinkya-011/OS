#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;sys/types.h&gt;
#include&lt;unistd.h&gt;
#include&lt;sys/wait.h&gt;
void arrayStore(char* c_arr[],int* i_arr, int n)
{
    for(int i=0;i&lt;n;i++)
    {
    i_arr[i] = atoi(c_arr[i+1]);
    }
}
void arraySort(int* arr, int n, int order)
{
    for(int i=0;i&lt;n-1;i++)
    {
        for(int j=0;j&lt;n-i-1;j++)
        {
            if(order == -1)
            {
                if(arr[j]&lt;arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            else if(order == 1)
            {
                if(arr[j]&gt;arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}
void arrayDisplay(int* arr, int n)
{
    printf(&quot;\nDisplaying Array.... \n&quot;);
    for(int i=0;i&lt;n;i++)
    {
        printf(&quot;%d\t&quot;,arr[i]);
    }

    printf(&quot;\n\n&quot;);
}
void main(int argc, char* argv[])
{
    int order;
    int arr[argc-1];
    int len = argc - 1;
    arrayStore(argv,arr,len);
    pid_t pid, tpid, status;
    pid = fork();
    if(pid == 0)
    {
        //sleep(5); //Orphan State
        printf(&quot;\nChild Process with ID %d\n&quot;,getpid());
        printf(&quot;Child&#39;s Parent ID %d\n&quot;,getppid());
        order = -1;
        arraySort(arr,len,order);
        arrayDisplay(arr,len);
    }
    else
    {
        //sleep(5); //Zombie State
        system(&quot;ps&quot;);
        tpid = wait(&amp;status);
        printf(&quot;\nParent Process with ID %d \n&quot;,getpid());
        order = 1;
        arraySort(arr,len,order);
        arrayDisplay(arr,len);
    }
}

Output :
┌──(pranav㉿Pranav)-[~]
└─$ cd OS
┌──(pranav㉿Pranav)-[~/OS]
└─$ gcc a3.c
┌──(pranav㉿Pranav)-[~/OS]
└─$ ./a.out 5 43 -34 0 -32 2
Child Process with ID 3423
Child&#39;s Parent ID 3422

Displaying Array....
43 5 2 0 -32 -34
PID TTY TIME CMD
3322 pts/0 00:00:00 zsh
3422 pts/0 00:00:00 a.out
3423 pts/0 00:00:00 a.out
3424 pts/0 00:00:00 sh
3425 pts/0 00:00:00 ps
Parent Process with ID 3422
Displaying Array....
-34 -32 0 2 5 43

Orphan State :

Code:
void main(int argc, char* argv[])
{
    int order;
    int arr[argc-1];
    int len = argc - 1;
    arrayStore(argv,arr,len);
    pid_t pid, tpid, status;
    pid = fork();
    if(pid == 0)
    {
        sleep(5); //Orphan State
        printf(&quot;\nChild Process with ID %d\n&quot;,getpid());
        printf(&quot;Child&#39;s Parent ID %d\n&quot;,getppid());
        order = -1;
        arraySort(arr,len,order);
        arrayDisplay(arr,len);
    }
    else
    {
        //sleep(5); //Zombie State
        system(&quot;ps&quot;);
        tpid = wait(&amp;status);

        printf(&quot;\nParent Process with ID %d \n&quot;,getpid());
        order = 1;
        arraySort(arr,len,order);
        arrayDisplay(arr,len);
    }
}
PID TTY TIME CMD
3894 pts/1 00:00:01 zsh
4391 pts/1 00:00:00 a.out
4352 pts/1 00:00:00 a.out
4353 pts/1 00:00:00 sh
4354 pts/1 00:00:00 ps

PID TTY TIME CMD
3894 pts/1 00:00:01 zsh
4351 pts/1 00:00:00 a.out
4352 pts/1 00:00:00 a.out
4355 pts/1 00:00:00 sh
4356 pts/1 00:00:00 ps

Child Process with ID 4352
Child&#39;s Parent ID 4391
Displaying Array....
53 34 5 0 -2 -54
Parent Process with ID 4351
Displaying Array....
-54 -2 0 5 34 53

Zombie State :

Output :
void main(int argc, char* argv[])
{
    int order;
    int arr[argc-1];
    int len = argc - 1;
    arrayStore(argv,arr,len);
    pid_t pid, tpid, status;
    pid = fork();
    if(pid == 0)
    {
        //sleep(5); //Orphan State
        printf(&quot;\nChild Process with ID %d\n&quot;,getpid());
        printf(&quot;Child&#39;s Parent ID %d\n&quot;,getppid());
        order = -1;
        arraySort(arr,len,order);
        arrayDisplay(arr,len);
    }
    else
    {
        sleep(5); //Zombie State
        system(&quot;ps&quot;);
        tpid = wait(&amp;status);
        printf(&quot;\nParent Process with ID %d \n&quot;,getpid());
        order = 1;
        arraySort(arr,len,order);
        arrayDisplay(arr,len);
    }
}
┌──(pranav㉿Pranav)-[~/OS]
└─$ ./a.out 5 53 -54 34 -2 0
PID TTY TIME CMD
3894 pts/1 00:00:01 zsh
4298 pts/1 00:00:00 a.out
4299 pts/1 00:00:00 a.out

4300 pts/1 00:00:00 sh
4301 pts/1 00:00:00 ps

Child Process with ID 4299
Child&#39;s Parent ID 4298
Displaying Array....
53 34 5 0 -2 -54
PID TTY TIME CMD
3894 pts/1 00:00:01 zsh
4298 pts/1 00:00:00 a.out
4299 pts/1 00:00:00 a.out &lt;defunct&gt;
4302 pts/1 00:00:00 sh
4303 pts/1 00:00:00 ps
Parent Process with ID 4298
Displaying Array....
-54 -2 0 5 34 53