#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
int main(int argc , char *argv[])
{
    int i;
    int array[argc];
    //store the elements into the array (command line arguments)
    for(int i=1 ; i<argc ; i++)
    {
        array[i-1] = atoi(argv[i]);
    }
    printf("\nThe elements stored in array (after sorting ) are :\n");
    for(int i=1; i<argc ;i++)
    {
     printf("%d\n",array[i-1]);
    }
    int search;
    printf("Enter the target to search : ");
    scanf("%d",&search);
    int low = 0;
    int high = argc-1;
    int found=0;
    while ( low <= high)
    {
        //int mid =low + (high - low) / 2;
        int mid =(high + low) / 2;
        if (array[mid] == search)
        {
            printf("\nElement Found at index: %d \n", mid);
            printf("\nB process id : %d \n",getpid());
            printf("\nB Parent process id : %d \n",getppid());
            found=1;
            break;
        }
        else if (array[mid] < search)
        {
         low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if(found==0)
    {
        printf("\nThe element %d is not present in the given array !!!\n",search);
    }
    return 0;
}