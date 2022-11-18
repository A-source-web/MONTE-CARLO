
#include <stdio.h>
#include <string.h>
#include <pthread.h>//all the functions avilable for the threads
#include <math.h>
#include <stdlib.h>

int i= 0;//incrementing variable	
int n= 0;//the number of points to calculate the value of pi
int totalPts  = 0;//counts and stores the total number of points in the circle

void *count()
{ 
    /* initialize random numbers */
    printf("In count \nthread id = %lu\n", pthread_self());
    for (i=0; i < n; i++)
    {	
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (sqrt((X * X) + (Y * Y)) <= 1)
        {
            totalPts++;
        }
    }
    printf("\nIn count \nthread id = %lu\n", pthread_self());//returns the thrad identifier of the child thread.
    return NULL;
}

int main()
{
    srand(time(NULL));//srand creates a seed for a random number to be generated.
    pthread_t thread;//creates a variable that stores the value of thread identifier.

    do
	{
        printf("Enter the number of points you would like to generate: \n");
        scanf("%d", &n);  	
	}while (n <= 0);
  
    pthread_create(&thread, NULL,count, NULL);//creates a thread. The first parameter thread is passed so that the date of the thread can be stored in it. NULL in second attribute to set attributes of new thread created to default since no specifications are to be provided.Count() function indicates the starting point of the child thread.Fourth attribute null because no integer parameter was provided on the command line
    pthread_join(thread, NULL);//waits for the child thread to finish executing and update data.The parent thread waits. The second attribute is null to indicate that the parent thread doesnt expect any return value from the child thread.
    
    printf("\nIn main \nthread id = %lu\n", pthread_self());//returns the thread identifier of the parent thread.
    
    double points = 4.0 * totalPts;
    double pi = points / n;
    printf("\nThe approximate value of pi for the (%d) points is: %f \n", n, pi);  
    return 0;
}
