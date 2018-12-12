/* Kurt Borgsmiller
   432 Lab5 pt b
   9/28/2018

   -Program would initially not run because math.h directory had to be included 
    for use of the sin and tan functions
   -Program also did not call pthread_exit in the busywork function or in the
    main 
   -After these were corrected, program worked as designed
*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS	4

void *BusyWork(void *t)
{
   long i, tid;
   double result=0.0;
   tid = (long)t;
   sleep(2);
   printf("Thread %ld starting...\n",tid);
   for (i=0; i<1000000; i++) {
     result = result + sin(i) * tan(i);
     }
   printf("Thread %ld done. Result = %e\n",tid, result);

pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
pthread_t thread[NUM_THREADS];
int rc; 
long t;

for(t=0;t<NUM_THREADS;t++) {
   printf("Main: creating thread %ld\n", t);
   rc = pthread_create(&thread[t], NULL, BusyWork, (void *)t); 
   if (rc) {
     printf("ERROR; return code from pthread_create() is %d\n", rc);
     exit(-1);
     }
  }

printf("Main: program completed. Exiting.\n");

pthread_exit(NULL);
}


