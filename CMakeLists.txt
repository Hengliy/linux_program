cmake_minimum_required(VERSION 3.9)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled file/file1.cpp file/mmap.cpp file/main.cpp file/defination.h file/fcntl.cpp file/ioctl.cpp)