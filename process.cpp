//
// Created by 李明泽 on 2018/3/12.
//

#include "process.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <string>

using namespace std;

void f();

void p();


void process() {
//    f();
    p();

}

void f() {
    pid_t pid, ppid;

    pid = getpid();
    ppid = getppid();

    cout << "pid:" << pid << endl;
    cout << "ppid:" << ppid << endl;
    cout << "----------------------------------------------" << endl;

    pid_t tpid;
    tpid = fork();

    if (tpid == -1) {
        cout << "tpid == -1" << endl;
        cout << "进程创建失败" << endl;
    } else if (tpid == 0) {

        cout << "tpid == 0" << endl;
        cout << "pid:" << pid << " ppid:" << ppid << " tpid:" << tpid << endl;
        cout << "getpid:" << getpid() << " getppid:" << getppid() << endl;
    } else {
        cout << "tpid >0" << endl;
        cout << "pid:" << pid << " ppid:" << ppid << " tpid:" << tpid << endl;
        cout << "getpid:" << getpid() << " getppid:" << getppid() << endl;
    }
//    while(1){
//        sleep(500);
//    }

    //pstree -p 5278

    cout << "----------------------------------------------" << endl;


}

void p() {
    int fd[2];
    int *write_fd = &fd[1];
    int *read_fd = &fd[0];

    int result = -1;
    result = pipe(fd);

    cout << result;

    pid_t npid;
    npid = fork();

    if (npid == 0) {
        //子进程
//        关闭读管道
        close(*read_fd);
        const char *str = "子进程发送消息：hello！";
//        char str[] = "子进程发送消息：hello！";

        write(*write_fd, str, strlen(str));
        cout << "这里是子进程，发送消息：" << endl;
    } else {
        //父进程
//        关闭写管道
        close(*write_fd);

        char readbuffer[50];
        read(*read_fd, readbuffer, sizeof(readbuffer));
        cout << "这里是父进程，接收消息为：" << readbuffer << endl;
    }

}