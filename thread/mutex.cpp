//
// Created by 李明泽 on 2018/3/14.
//

#include <stdio.h>
#include <sched.h>
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void *producter(void *arg);

void *consumer(void *arg);

pthread_mutex_t mutex;

int main() {

    pthread_t producter_t;
    pthread_t consumer_t;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producter_t, NULL, producter, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);

    pthread_join(producter_t, NULL);
    pthread_join(consumer_t, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}

static int buffer_has_items = 0;

void *producter(void *arg) {
    int i = 50;
    while (i--) {
        pthread_mutex_lock(&mutex);
        buffer_has_items++;
        cout << "生产者，总数量：" << buffer_has_items << endl;
        pthread_mutex_unlock(&mutex);

        usleep(100);
    }
}

void *consumer(void *arg) {
    int i = 50;
    while (i--) {
        pthread_mutex_lock(&mutex);
        buffer_has_items--;
        cout << "消费者，总数量：" << buffer_has_items << endl;
        pthread_mutex_unlock(&mutex);

        usleep(100);

    }
}