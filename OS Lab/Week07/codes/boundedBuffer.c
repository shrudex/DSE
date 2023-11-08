#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

sem_t mutex, empty, full; 
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int generateCount = 7;

void *producer(void *arg) {
    int item;

    for (int i = 0; i < generateCount; ++i) {
        item = rand(); 

        sem_wait(&empty); //waiting for an empty slot
        sem_wait(&mutex); //mutex for waiting to access the buffer

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex); //freeing the buffer
        sem_post(&full);  //notifying consumer
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;

    for (int i = 0; i < generateCount; i++) {
        sem_wait(&full);  //waiting for an item
        sem_wait(&mutex); //mutex for waiting to access the buffer

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex); //freeing the buffer
        sem_post(&empty); //notifying producer
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 49;
}
