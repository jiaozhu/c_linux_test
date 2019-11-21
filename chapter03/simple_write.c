/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Wythe Chao
#   Email         : hi@bug.js.cn
#   File Name     : simple_write.c
#   Last Modified : 2019-11-21 12:54
#   Describe      :
#
# ====================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    if((write(1,"Here is some data\n",18)) != 18)
        write(2,"A write error has occurred on file desriptor 1\n",46);
    exit(0);
}

