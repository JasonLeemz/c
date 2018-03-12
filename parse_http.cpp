#include "parse_http.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char reqHeadersSource[] = "GET /question/576635507.html HTTP/1.1\n"
        "Host: www.limingze.cc:8888\n"
        "Connection: keep-alive\n"
        "Cache-Control: max-age=0\n"
        "Upgrade-Insecure-Requests: 1\n"
        "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\n"
        "Accept-Encoding: gzip, deflate\n"
        "Accept-Language: zh-CN,zh;q=0.9\n"
        "Cookie: __guid=65658408.2628692102594823000.1517197430221.772; UM_distinctid=161422d55ab604-0781bdc67cf53b-4323461-295d29-161422d55acd3c; CNZZDATA1272851374=2096119885-1517233721-%7C1520559133\n"
        "If-None-Match: \"4496-566a0d3fe1d40-gzip\"\n"
        "If-Modified-Since: Mon, 05 Mar 2018 02:10:21 GMT";

struct reqHeadersSeek {
    char *rh;
    int seek;
    int length;
} reqHeadersSeek;


typedef struct reqBaseInfo {
    string method;
    string path;
    string version;
} reqBaseInfo;

reqBaseInfo getReqBaseInfo();

reqHeadersStruct getDetailInfo();

reqHeaders parse() {

    reqHeadersSeek.rh = reqHeadersSource;
    reqHeadersSeek.seek = 0;
    reqHeadersSeek.length = sizeof(reqHeadersSource);

    reqHeaders r;
    reqBaseInfo rb;
    rb = getReqBaseInfo();

    r.method = rb.method;
    r.path = rb.path;
    r.version = rb.version;

    reqHeaders rh;
    rh = getDetailInfo();

    r.host = rh.host;
    r.connection = rh.connection;
    r.userAgent = rh.userAgent;
    r.accept = rh.accept;
    r.cookie = rh.cookie;


    return r;
}

string extract(int &start, char symbol, char *str) {
    int s = start;
    while (1) {
        start++;
        if (str[start] == symbol || str[start] == '\0') {
            break;
        }
    }

    string m;
    for (int i = s; i < start; i++) {
        m += str[i];
    }
    start++;
    return m;
}

//获取请求头部第一行内容
reqBaseInfo getReqBaseInfo() {
    reqBaseInfo rb;
    rb.method = extract(reqHeadersSeek.seek, ' ', reqHeadersSeek.rh);
    rb.path = extract(reqHeadersSeek.seek, ' ', reqHeadersSeek.rh);
    rb.version = extract(reqHeadersSeek.seek, '\n', reqHeadersSeek.rh);
    return rb;
}

reqHeadersStruct getDetailInfo() {
    reqHeadersStruct rh;
//    int l = sizeof(reqHeadersSeek.rh);

    char a = 64;
//    while (reqHeadersSeek.seek < reqHeadersSeek.length) {
    while (reqHeadersSeek.rh[reqHeadersSeek.seek-1] != '\0') {
//        cout << reqHeadersSeek.seek << "---" << reqHeadersSeek.length << endl;

        string str;
        str = extract(reqHeadersSeek.seek, '\n', reqHeadersSeek.rh);
        int s = 0;
        char *p = (char *) str.data();

        string k = extract(s, ':', p);
        s += 1;
        string v = extract(s, '\0', p);

        if(k=="Host"){
            rh.host = v;
        }else if(k=="Connection"){
            rh.connection = v;
        }else if(k=="User-Agent"){
            rh.userAgent = v;
        }else if(k=="Accept"){
            rh.accept = v;
        }else if(k=="Cookie"){
            rh.cookie = v;
        }

    }

    return rh;
}