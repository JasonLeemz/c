//
// Created by 李明泽 on 2018/3/16.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

#define PORT 8888
#define BACKLOG 2

void process_conn_server(int s);

int main() {

    int ss, sc;

    //建立一个流式套接字
    ss = socket(AF_INET, SOCK_STREAM, 0);
    if (ss < 0) {
        cout << "socket create error" << endl;
        return -1;
    }

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    //设置服务器地址
    bzero(&server_addr, sizeof(server_addr));//清零
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;//协议族
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//本地地址
    server_addr.sin_port = htons(PORT);//服务器端口

    int err;

    //绑定地址到socket描述符
    err = bind(ss, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (err < 0) {
        cout << "bind error" << endl;
        return -1;
    }

    //设置侦听
    int *backlog;
    *backlog = 2;
    err = listen(ss, *backlog);
    if (err < 0) {
        cout << "listen error" << endl;
        return -1;
    }

    while (1) {
        socklen_t addrlen = sizeof(struct sockaddr);

        sc = accept(ss, (struct sockaddr *) &client_addr, &addrlen);

        pid_t pid;
        pid = fork();
        if (pid == 0) {
            close(ss);
            process_conn_server(sc);
        } else {
            close(sc);
        }


    }

}

void process_conn_server(int s) {
    ssize_t size = 0;
    char buffer[1024];

    while (1) {
        size = read(s, buffer, 1024);

        if (size == 0) {
            return;
        }

        sprintf(buffer, "%s %d 字节数据\n",buffer, size);
        write(s, buffer, strlen(buffer) + 1);

//        write(s, buffer, 1024);
//        size = read(s, buffer, 1024);
//        write(1, buffer, size);
    }
}