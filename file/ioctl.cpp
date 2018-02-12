//
// Created by hengliy on 2/12/18.
//

#include <iostream>
using namespace std;

#include <linux/cdrom.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <zconf.h>

int ioctl(char* filename)
{
    int fd=open(filename,O_RDONLY);
    if(fd<0)
    {
        cout<<"open cdrom error"<<endl;
    }
    if(!ioctl(fd,CDROMEJECT,NULL))
    {
        cout<<"弹出成功"<<endl;
    }else{
        cout<<"弹出失败"<<endl;
    }

    close(fd);
    return 0;
}
