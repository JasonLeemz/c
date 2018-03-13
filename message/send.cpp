//
// Created by 李明泽 on 2018/3/13.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <iostream>
using namespace std;

struct msgmbuf {
    long mtype;
    char mtext[50];
};

int main() {
    int key, msg_id;
    static msgmbuf buf;

    key = ftok(".", 1);
//    cout << key;
    msg_id = msgget(key, IPC_CREAT | 0600);

    buf.mtype = 1;
    while (1) {
        fgets(buf.mtext, 50, stdin);

        msgsnd(msg_id, &buf, sizeof(buf), 0);

//        quit退出并删除队列
        if (!strncmp(buf.mtext, "quit", 4)) {
            msgctl(msg_id, IPC_RMID, 0);
            exit(0);
        }


    }
    return 0;
}
