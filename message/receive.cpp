//
// Created by 李明泽 on 2018/3/13.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct msgmbuf {
    long mtype;
    char mtext[50];
};

int main() {
    int key, msg_id;
    static msgmbuf buf;

    key = ftok(".", 1);
    msg_id = msgget(key, IPC_CREAT | 0600);

    buf.mtype = 1;

    while (1) {
        msgrcv(msg_id, &buf, sizeof(buf), buf.mtype, 0);

        cout << "recv:" << buf.mtext;
        if(!strncmp(buf.mtext, "quit", 4)){
            exit(0);
        }
    }

    return 0;
}
