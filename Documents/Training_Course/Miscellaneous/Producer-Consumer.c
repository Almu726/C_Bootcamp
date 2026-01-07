#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/semaphore.h>
 
const int MAX_BUFFER = 5;
sem_t mutex;
int buffer;
const int SEMAPHORE_MAX = 10;
 
void* producer(void *arg){
    sem_wait(&mutex);
    printf("producer");
    if (buffer < MAX_BUFFER){
        buffer++;
        sem_post(&mutex);
    }
    else {
        sem_post(&mutex);
    }
}
 
void* consumer(void *arg){
    sem_wait(&mutex);
    printf("consumer");
    if (buffer == 0){
        sem_post(&mutex);
    }
    else {
        buffer--;
        sem_post(&mutex);
    }
    sem_post(&mutex);
}
 
int main(void){
    sem_init(&buffer, 0, 1);
    pthread_t producer, consumer;
    for (int i = 0; i < SEMAPHORE_MAX; i++){
        pthread_create(&producer, NULL, producer, NULL);
        pthread_create(&consumer, NULL, consumer, NULL);
    }
}