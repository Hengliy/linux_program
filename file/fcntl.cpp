//
// Created by hengliy on 2/12/18.
//
//fcntl()函数用于获得和改变已经打开文件的性质。
#include "defination.h"
#include <iostream>
#include <fcntl.h>
#include <zconf.h>
#include <cstring>

using namespace std;


int fcntl(char* filename)
{
    int flags = -1;
    char buf[] = "FCNTL";
    int fd = open(filename,O_RDWR);
    flags  = fcntl(fd, F_GETFL, 0);

    flags |= O_APPEND;
    flags = fcntl(fd, F_SETFL, flags);
    if(flags<0)
    {
        printf("failure to use fcntl\n");
        return -1;
    }

    write(fd, buf, strlen(buf));
    close(fd);
    return 0;
}
