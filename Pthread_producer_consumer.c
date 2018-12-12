#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define N 3
#define NEXT(x) ((x + 1) % N)

pthread_t tid[8];
int buffer[N], in=0, out=0, count=0;

sem_t mutex;
sem_t items;
sem_t space;



void* producer(void *ptr)
{
    sem_wait(&space);
    sem_wait(&mutex);
    
	srand(time(NULL));
	int item,i;
    
	item = rand()%50;
	printf("Insert: %d\n",item);
	buffer[in] = item;
	in = NEXT(in);
	count++;
    
    sem_post(&mutex);
    sem_post(&items);
    
    return NULL;

}

void* consumer(void *ptr)
{
    
    sem_wait(&items);
    sem_wait(&mutex);
    
	srand(time(NULL));
    
	int item,i;
    
	item = buffer[out];
	printf("Remove: %d\n",item);
	out = NEXT(out);
	count--;
    
    sem_post(&mutex);
    sem_post(&space);
    
    return NULL;
    
}


int main(void)
{
    long i = 0;
    int err;

    sem_init(&mutex, 0, 1);
    sem_init(&items, 0, 0);
    sem_init(&space, 0, N);


   pthread_create(&tid[0], NULL, consumer, NULL);
   pthread_create(&tid[1], NULL, producer, NULL);
   pthread_create(&tid[2], NULL, consumer, NULL);
   pthread_create(&tid[4], NULL, producer, NULL);
   pthread_create(&tid[5], NULL, consumer, NULL);
   pthread_create(&tid[6], NULL, producer, NULL);


    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    
    sem_destroy(&mutex);
    sem_destroy(&items);
    sem_destroy(&space);
    
    return 0;
}

