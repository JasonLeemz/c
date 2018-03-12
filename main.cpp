#include "parse_http.h"
#include <iostream>

using namespace std;

int main() {
    reqHeaders req;
    req = parse();

    cout << req.host;
    return 0;
}