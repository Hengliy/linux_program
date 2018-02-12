#include<iostream>
#include <fcntl.h>
#include <zconf.h>
#include <error.h>
#include <sys/stat.h>
#include <cstring>

using namespace std;
#include"defination.h"

int file(char filename[])
{
    int fd;
    //char filename[]="../file/test.txt";
    char * buffer=new char[1000];

    fd=open(filename,O_RDWR|O_APPEND);//打开文件
    if(fd==-1) {
        cout << "open error" << endl;
        return -1;
    }

    int size=-1;
    size=write(fd,filename,sizeof(filename));//写入数据
    if(size==-1) {
        cout<<"write false"<<endl;
        return -1;
    }
    cout<<"write success length size= "<<size;
    size=-1;
    lseek(fd,0,SEEK_SET);//修改偏移量到头SEEK_CUR（当前位置）/SEEK_END（尾部）
    while(size){
       size=read(fd,buffer,1000);// 读数据
       if(size==-1){
           cout<<"read file error"<<endl;
       }else if(size>0){
           cout<<"read info = "<<buffer<<endl;
       }else {
           cout<<"end file"<<endl;
           break;
       }
    }
    memset(buffer,0,1000);
    struct stat st;
    int state=fstat(fd,&st);//读取文件状态
    if(state==-1){
        cout<<"read state error"<<endl;
        return -1;
    }else{
        cout<<st.st_size<<endl;
        cout<<st.st_uid<<endl;
        cout<<st.st_mode<<endl;
        cout<<st.st_mtime<<endl;
    }
    close(fd);
    return 0;
}