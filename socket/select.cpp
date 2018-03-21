//
// Created by 李明泽 on 2018/3/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include <iostream>

using namespace std;
#define BUF_SIZE 30

int main() {

    int err,str_len;
    fd_set rd;
    struct timeval tv;


    tv.tv_sec = 5;
    tv.tv_usec = 0;

    FD_ZERO(&rd);
    FD_SET(0, &rd);

    char buf[BUF_SIZE];

    while (1) {
        err = select(1, &rd, NULL, NULL, NULL);

        if (err == 0) {
            perror("超时了");
        } else if (err) {
            if (FD_ISSET(0, &rd)) {
                str_len = read(0, buf, BUF_SIZE);
                buf[str_len] = 0;
                cout << buf << endl;
            }
        } else {
            cout << "发生了错误" << endl;
        }
    }

    return 0;
}