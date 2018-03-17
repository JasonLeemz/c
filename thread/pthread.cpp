//
// Created by 李明泽 on 2018/3/14.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <sched.h>

using namespace std;

void *start_routine(void *arg) {

    int *running;
    running = static_cast  <int *>(arg);
    cout << "线程初始化完毕" << *running << endl;
    int i = 8;
    while (i--) {
        cout << "子线程正在运行" << endl;
        usleep(1);
    }

    cout << "子线程退出" << endl;

    int retvalue = 8;
    pthread_exit((void *) &retvalue);

}

static int run = 1;

int main() {
    pthread_t pt;
    int ret = -1;
    int times = 8;

    ret = pthread_create(&pt, NULL, &start_routine, &run);

    if (ret != 0) {
        cout << "创建线程失败" << endl;
        return 1;
    }

    for (int i = 0; i < times; i++) {
        cout << "主线程打印" << endl;
        usleep(1);
    }

//    void **retvalue = NULL;
//    pthread_join(pt, retvalue);//阻塞函数
//
//    int *a = static_cast<int *>(*retvalue);
//    cout << "线程返回值为："<< *a  << endl;
    pthread_join(pt, NULL);//阻塞函数
    cout << "线程结束" << endl;
    return 0;

}