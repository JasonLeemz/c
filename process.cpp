//
// Created by 李明泽 on 2018/3/12.
//

#include "process.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void process() {
    pid_t pid, ppid;

    pid = getpid();
    ppid = getppid();

    cout << "pid:" << pid << endl;
    cout << "ppid:" << ppid << endl;

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
    while(1){
        sleep(500);
    }

    //pstree -p 5278


    
}