/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Wythe Chao
#   Email         : hi@bug.js.cn
#   File Name     : simple_read.c
#   Last Modified : 2019-11-21 13:49
#   Describe      :
#
# ====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    char buffer[128];
    int nread;

    nread = read(0,buffer,128);
    if(nread == -1){
        write(2,"A read error has occurred\n",26);
    }

    if( (write(1,buffer,nread)) != nread ){
        write(1,"A write error has occurred\n",27);
    }

    exit(0);
}

