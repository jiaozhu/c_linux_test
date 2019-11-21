/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Wythe Chao
#   Email         : hi@bug.js.cn
#   File Name     : copy_block.c
#   Last Modified : 2019-11-21 15:34
#   Describe      : 利用缓存区，批量输入输出字符
#
# ====================================================*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){
    char buffer[1024];

    int in,out;
    int nread;

    in = open("file.in",O_RDONLY);
    out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

    while( (nread = read(in,buffer,sizeof(buffer))) > 0 ){
        write(out,buffer,nread);
    }

    exit(0);
}
