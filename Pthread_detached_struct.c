/* Kurt Borgsmiller
   432 Lab5 pt b
   9/28/2018

   -Program will create a struct thread_data containing the id and limit
   -Function busywork will take thread_data_array as an argument and use limit
    and thread id to compute result of function
   -Limit is unique for each thread
   -Program must spawn the threads with a detached attribute, I chose to
    make my attribute Joinable and joined them later in the main
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS	5

/*

Must create struct containing thread id and t then pass this struct to pthread_create.
Must calculate the limit for each thread in busy work

*/

void sleep();

struct thread_data{
	int id;
	double limit;

};

struct thread_data thread_data_array[NUM_THREADS];

void *BusyWork(void *threadarg)
{
   int i, tid;
   double result=0.0, tlimit;
   struct thread_data *my_data;

   sleep(2);

   my_data = (struct thread_data*) threadarg;

   tid = my_data -> id;
   tlimit = my_data -> limit;

   printf("Thread %d starting...\n",tid);
   for (i=0; i<tlimit; i++) {
     result = result + sin(i) * tan(i);
     }
   printf("Thread %d done. Result = %e\n",tid, result);

   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
pthread_t thread[NUM_THREADS];
pthread_attr_t attr;
int rc; 
int t;
void* status;

pthread_attr_init(&attr);
pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

for(t=0;t<NUM_THREADS;t++) {
	thread_data_array[t].id = t;
	thread_data_array[t].limit = (1000000 + t*100);

   printf("Main: creating thread %d\n", t);
   rc = pthread_create(&thread[t], &attr, BusyWork, (void *)&thread_data_array[t]); 
   if (rc) {
     printf("ERROR; return code from pthread_create() is %d\n", rc);
     exit(-1);
     }
  }

pthread_attr_destroy(&attr);


for(t=0;t<NUM_THREADS;t++) {
   rc = pthread_join(thread[t], &status); 
   if (rc) {
     printf("ERROR; return code from pthread_create() is %d\n", rc);
     exit(-1);
     }

   printf("Main: joined with thread %d with status %ld\n", t, (long)status);
  }


printf("Main: program completed. Exiting.\n");

pthread_exit(NULL);
}

