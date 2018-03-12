//
// Created by 李明泽 on 2018/3/12.
//

#include "read_file.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void read_file() {
    const char *file_path = "./conf/cfg.ini";

//    FILE *fd;
    fstream fd(file_path);

    string line;

    while (getline(fd, line)) {
        cout << line << endl;
    }
    fd.close();

}