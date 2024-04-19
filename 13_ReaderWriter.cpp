// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>

// #define NUM_READERS 3
// #define NUM_WRITERS 2

// int shared_resource = 0; // The shared resource being read/written

// sem_t mutex; // Controls access to the shared resource
// sem_t rw_mutex; // Ensures exclusive access to writers

// int readers_count = 0; // Number of active readers

// void* reader(void* arg) {
//     while (1) {
//         // Entry section
//         sem_wait(&mutex);
//         readers_count++;
//         if (readers_count == 1) {
//             sem_wait(&rw_mutex); // Lock the resource if this is the first reader
//         }
//         sem_post(&mutex);

//         // Critical section
//         printf("Reader %d is reading shared resource: %d\n", *((int*)arg), shared_resource);

//         // Exit section
//         sem_wait(&mutex);
//         readers_count--;
//         if (readers_count == 0) {
//             sem_post(&rw_mutex); // Release the resource if this is the last reader
//         }
//         sem_post(&mutex);

//         // Remainder section
//         // Sleep to simulate some processing time
//         usleep(rand() % 1000000);
//     }
// }

// void* writer(void* arg) {
//     while (1) {
//         // Entry section
//         sem_wait(&rw_mutex); // Lock the resource for writing

//         // Critical section
//         shared_resource++;
//         printf("Writer %d is writing shared resource: %d\n", *((int*)arg), shared_resource);

//         // Exit section
//         sem_post(&rw_mutex); // Release the resource after writing

//         // Remainder section
//         // Sleep to simulate some processing time
//         usleep(rand() % 1000000);
//     }
// }

// int main() {
//     pthread_t readers[NUM_READERS];
//     pthread_t writers[NUM_WRITERS];

//     // Initialize semaphores
//     sem_init(&mutex, 0, 1);
//     sem_init(&rw_mutex, 0, 1);

//     // Create reader threads
//     int i, reader_ids[NUM_READERS];
//     for (i = 0; i < NUM_READERS; i++) {
//         reader_ids[i] = i + 1;
//         pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
//     }

//     // Create writer threads
//     int writer_ids[NUM_WRITERS];
//     for (i = 0; i < NUM_WRITERS; i++) {
//         writer_ids[i] = i + 1;
//         pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
//     }

//     // Join threads
//     for (i = 0; i < NUM_READERS; i++) {
//         pthread_join(readers[i], NULL);
//     }
//     for (i = 0; i < NUM_WRITERS; i++) {
//         pthread_join(writers[i], NULL);
//     }

//     // Destroy semaphores
//     sem_destroy(&mutex);
//     sem_destroy(&rw_mutex);

//     return 0;
// }
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t tid;
pthread_t writerthreads[100],readerthreads[100];
int readercount = 0;

void *reader(void* param)
{
    sem_wait(&x);
    readercount++;
    if(readercount==1)
        sem_wait(&y);
    sem_post(&x);
    printf("%d reader is inside\n",readercount);
    usleep(3);
    sem_wait(&x);
    readercount--;
    if(readercount==0)
    {
        sem_post(&y);
    }
    sem_post(&x);
    printf("%d Reader is leaving\n",readercount+1);
    return NULL;
}

void *writer(void* param)
{
    printf("Writer is trying to enter\n");
    sem_wait(&y);
    printf("Writer has entered\n");
    sem_post(&y);
    printf("Writer is leaving\n");
    return NULL;
}

int main()
{
    int n2,i;
    printf("Enter the number of readers:");
    scanf("%d",&n2);
    printf("\n");
    int n1[n2];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(i=0;i<n2;i++)
    {
        pthread_create(&writerthreads[i],NULL,reader,NULL);
        pthread_create(&readerthreads[i],NULL,writer,NULL);
    }
    for(i=0;i<n2;i++)
    {
        pthread_join(writerthreads[i],NULL);
        pthread_join(readerthreads[i],NULL);
    }

}