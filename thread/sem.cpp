//
// Created by 李明泽 on 2018/3/14.
//

#include <pthread.h>
#include <stdio.h>
#include <sched.h>
#include <semaphore.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void *consumer(void *arg);

void *producter(void *arg);

sem_t sem;

int main() {
    pthread_t producter_t;
    pthread_t consumer_t;

    sem_init(&sem, 0, 500);

    pthread_create(&producter_t, NULL, producter, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);


    pthread_join(producter_t, NULL);
    pthread_join(consumer_t, NULL);


    sem_destroy(&sem);
    return 0;
}

void *producter(void *arg) {
    int i = 50;
    int semvalue = 0;
    while (i--) {
        sem_post(&sem);
        sem_getvalue(&sem, &semvalue);
        cout << "producter:" << semvalue << endl;

        sleep(2);
    }
}

void *consumer(void *arg) {
    int i = 50;
    int semvalue = 0;

    pthread_t tid;

    tid = pthread_self();

    while (1) {
        cout << tid << endl;
        sem_wait(&sem);
        sem_getvalue(&sem, &semvalue);
        cout << "consumer:" << semvalue << endl;

//        sleep(1);
    }


}