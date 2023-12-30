#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
/* Global variables */
int x = 0;
sem_t sync;
/* Thread function */
void *p1(void *arg)
{
    a();
    /* send signal to the created thread */
    ????;

}

void a(){
  sleep(10);
  printf("X = %d\n", x);
  x=55;
}
void *p2(void *arg)
{
    /* wait for signal from main thread */
    ?????;
    b();
}

void b(){
  printf("X = %d\n", x);
}

void main () {
    pthread_t thread1, thread2;
    /* semaphore sync should be initialized by 0 */
    if (sem_init(&sync, 0, 0) == -1) {
        perror("Could not initialize mylock semaphore");
        exit(2);
    }
    if (pthread_create(&thread1, NULL, a, NULL) < 0) {
        perror("Error: thread cannot be created");
        exit(1);
    }
    if (pthread_create(&thread1, NULL, b, NULL) < 0) {
        perror("Error: thread cannot be created");
        exit(1);
    }
    /* wait for created thread to terminate */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    /* destroy semaphore sync */
    sem_destroy(&sync);
    exit(0);
}
