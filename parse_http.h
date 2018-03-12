#include <iostream>
#include <string>

using namespace std;

typedef struct reqHeadersStruct {
    string method;
    string path;
    string version;
    string host;
    string connection;
    string userAgent;
    string accept;
    string cookie;
} reqHeaders;

reqHeaders parse();