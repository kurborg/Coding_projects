#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
int counter;

pthread_mutex_t lock;


void* doSomeThing(void *id)
{
	
int my_id = (int) id;

    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    counter += 1;
    printf("\n Thread %d started\n", id);

    for(i=0; i<(0xFFFFFFF);i++);

    printf("\n Thread %d finished\n", id);

     pthread_mutex_unlock(&lock);

}

int main(void)
{
    int i = 0;
    int err;
    
    pthread_mutex_init(&lock,NULL);

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

    
    pthread_mutex_destroy(&lock);

    return 0;
}
