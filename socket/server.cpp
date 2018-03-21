//
// Created by 李明泽 on 2018/3/16.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

#define PORT 8888
#define BACKLOG 2
int SocketCount = 0;
const int SOCKET_MAX_COUNT = 50;
int Sockets[50];

void process_conn_server(int s);

void AddSocket(int s);


int main() {

    int ss, sc;

    //建立一个流式套接字
    ss = socket(AF_INET, SOCK_STREAM, 0);
    if (ss < 0) {
        cout << "socket create error" << endl;
        return -1;
    }
    AddSocket(ss);

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
    int bbb = 2;
    int *backlog = &bbb;
//    *backlog = 2;
    err = listen(ss, *backlog);
    if (err < 0) {
        cout << "listen error" << endl;
        return -1;
    }


    fd_set rd;
    struct timeval tv;

    tv.tv_sec = 5;
    tv.tv_usec = 0;


    while (1) {
        cout << "while" << endl;
        //读集 清零初始化
        FD_ZERO(&rd);
        FD_SET(0, &rd);

        //把socket放入读集合中，让内核检测这些socket是否读就绪
        for (int i = 0; i < SocketCount; i++) {
            FD_SET(Sockets[i], &rd);
        }

        //Select函数去检查读集中是否有socket读就绪
        int total = select(0, &rd, NULL, NULL, &tv);
//        for (int i = 0; i < SocketCount; i++) {
//            if (Sockets[i] == ss) {
//                socklen_t addrlen = sizeof(struct sockaddr);
//
//                sc = accept(ss, (struct sockaddr *) &client_addr, &addrlen);
//                cout << "accept" << endl;
//                pid_t pid;
//                pid = fork();
//                if (pid == 0) {
//                    close(ss);
//                    process_conn_server(sc);
//                } else {
//                    close(sc);
//                }
//            }
//        }


    }

    return 0;
}

void process_conn_server(int s) {
    ssize_t size = 0;
    char buffer[1024];

    while (1) {
        size = read(s, buffer, 1024);

        if (size == 0) {
            return;
        }

        sprintf(buffer, "%s %d 字节数据\n", buffer, size);
        write(s, buffer, strlen(buffer) + 1);

//        write(s, buffer, 1024);
//        size = read(s, buffer, 1024);
//        write(1, buffer, size);
    }
}

void AddSocket(int s) {
    if (SocketCount < 0 || SocketCount >= SOCKET_MAX_COUNT)
        return;
    Sockets[SocketCount++] = s;
}