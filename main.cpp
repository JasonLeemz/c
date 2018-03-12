#include "parse_http.h"
#include <iostream>
#include "process.h"

using namespace std;

int main() {
    reqHeaders req;
    req = parse();

    cout << req.host << endl << endl;

    process();
    return 0;
}