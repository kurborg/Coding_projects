#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

pthread_t tid[2];
int counter;

sem_t t[2];


void* doSomeThing(void *id)
{
	
long my_id = (long) id;
unsigned long i = 0;
counter += 1;


if (my_id == 0)
{

    for (int j = 0; j < 4; j++)
    {
        sem_wait(&t[0]);
            printf("\n Thread %d started\n", id);

            for(i=0; i<(0xFFFFFFF);i++);

            printf("\n Thread %d finished\n", id); 
        sem_post(&t[1]);
      }
      
   
    sleep(1);
}
else
{
    
    for (int j = 0; j < 4; j++)
    {
        sem_wait(&t[1]);
            printf("\n Thread %d started\n", id);

            for(i=0; i<(0xFFFFFFF);i++);

            printf("\n Thread %d finished\n", id);
        sem_post(&t[0]);
    }
    
    return NULL;

}

}

int main(void)
{
    int i = 0;
    int k;
    int err;

    sem_init(&t[0], 0 , 1);
    sem_init(&t[1], 0 , 0);

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, (void *)i);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    sleep(5);
    pthread_join(tid[1], NULL);

    for (k = 0; k <2; k++)
        sem_destroy(&t[k]);

    return 0;
}
