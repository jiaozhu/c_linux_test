/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Wythe Chao
#   Email         : hi@bug.js.cn
#   File Name     : copy_system.c
#   Last Modified : 2019-11-21 15:11
#   Describe      : 每次接受一个字符
#
# ====================================================*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){
    char c;
    int in,out;

    in = open("file.in",O_RDONLY);
    out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    while( read(in,&c,1)== 1 ){
        write(out,&c,1);
    }

    exit(0);
}

