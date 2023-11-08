## Q2 - Write a C program for first _readers-writers_ problem using semaphores.

### C program - **readerWriter.c**

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

sem_t mutex, wrt;
int countReaders = 0;

void *reader(void *id) {
    int rID = *(int *)id;

    sem_wait(&mutex); 
    countReaders++; //access gained by reader
    if (countReaders == 1)
        sem_wait(&wrt); //first reader, blocking writer
        
    sem_post(&mutex);

    printf("Reader %d is reading.\n", rID);

    sem_wait(&mutex);
    countReaders--; //reading done
        
    if (countReaders == 0)
        sem_post(&wrt); //last reader, allowing writer
     
    sem_post(&mutex);

    pthread_exit(NULL);
}

void *writer(void *id) {
    int wID = *(int *)id;

    sem_wait(&wrt); //block for writer

    printf("Writer %d is writing.\n", wID);

    sem_post(&wrt); //unblock

    pthread_exit(NULL);
}

int main() {
    pthread_t readers[3], writers[2];
    //array of IDS
    int rIDs[3] = {49, 32, 19};
    int wIDs[2] = {172, 50};

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < 3; ++i)
        pthread_create(&readers[i], NULL, reader, &rIDs[i]);
    
    for (int i = 0; i < 2; ++i)
        pthread_create(&writers[i], NULL, writer, &wIDs[i]);

    for (int i = 0; i < 3; ++i)
        pthread_join(readers[i], NULL);
    
    for (int i = 0; i < 2; ++i)
        pthread_join(writers[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 49;
}
```

### Command to compile the C program
```shell
gcc -o readerWriter readerWriter.c -lpthread
```

### Command to run the program
```shell
./readerWriter
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/ad192c91-8bce-4eb2-b736-349a99bed576)
