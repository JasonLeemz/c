//
// Created by 李明泽 on 2018/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;
#define PORT 8888

void process_conn_client(int s);

int main(int argc, char *argv[]) {
    int s;
    struct sockaddr_in server_addr;

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        cout << "socket error" << endl;
        return -1;
    }

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;//协议族
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//本地地址
    server_addr.sin_port = htons(PORT);//服务器端口

    //将用户输入的字符串ip地址转换为整型
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    connect(s, (struct sockaddr *) &server_addr, sizeof(struct sockaddr));
    process_conn_client(s);

    close(s);
    return 0;
}

void process_conn_client(int s) {
    ssize_t size = 0;
    char buffer[1024];

    while (1) {
        size = read(0, buffer, 1024);
        if (size > 0) {
            write(s, buffer, 1024);
            size = read(s, buffer, 1024);
            write(1, buffer, size);
        }
    }
}