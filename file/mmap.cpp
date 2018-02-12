//
// Created by hengliy on 2/12/18.
//

#include <iostream>
#include <fcntl.h>
#include <zconf.h>
#include <sys/mman.h>
#include <cstring>
using  namespace std;
#define FILELENGTH 800
/*
 * mmap()函数将普通文件映射到内存中，普通文件被映射到进程地址空间后，进程可以像访问普通内存一样对文件进行访问，
 * 不必再调用read()，write（）等操作。 mmap()系统调用使得进程之间通过映射同一个普通文件实现共享内存。
 * mmap()映射后，让用户程序直接访问设备内存，相比较在用户控件和内核空间互相拷贝数据，效率更高。在要求高性能的应用中比较常用。
 * mmap映射内存必须是页面大小的整数倍，面向流的设备不能进行mmap，mmap的实现和硬件有关。
 *
 *
 * 建立文件的内存映射的流程：
 * 首先使用open()函数打开一个文件，当操作成功后会返回一个文件描述符；
 * 使用mmap()函数将此文件描述符所代表的文件映射到一个地址空间，如果映射成功，会返回一个映射地址执政；
 * 对文件的操作可以通过mmap()映射得到的地址来进行，包括读数据、写数据、偏移等，与一般的指针操作相同，不过要注意不要进行越界访问；
 * 当对文件操作完毕后，需要使用munmap()函数将mmap()映射的地址取消;
 * 使用close()函数关闭文件。
 */
int mmap(char* filename)
{
    int fd = -1;
    char buf1[] = "Linux Command line and shell Scripting bible";
    char buf2[]= "a";
    char *addr = NULL;
    ssize_t size = -1;
    off_t cur_pos = 0;
    //打开文件，将文件的长度缩小为0
    fd = open(filename,O_RDWR|O_CREAT, S_IRWXU);
    if(-1==fd)
    {
        return -1;
    }
    cur_pos = lseek(fd,FILELENGTH-1, SEEK_SET);
    size = write(fd,buf2,strlen(buf2));//随意写入一个字符，此时文件长度为800
    if(1==size)
    {
        printf("write success\n");
    }

    //将文件mmap.txt中的数据段从开头到1M的数据映射到内存中，对文件的操作立刻显示在文件上，可读写.
    addr = (char *)mmap(NULL, FILELENGTH, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);//MAP_SHARED(共享映射)。MAP_PRIVATE(私有映射)
    if((char *)-1 == addr)
    {
        printf("mmap failure !\n");
        close(fd);
        return -1;
    }
    //将buf中的字符串复制到映射区域中，起始位置为addr偏移16
    memcpy(addr +16 ,buf1 ,strlen(buf1));
    munmap(addr,FILELENGTH);//解除内存映射
    close(fd);//关闭文件
    return 0;
}
