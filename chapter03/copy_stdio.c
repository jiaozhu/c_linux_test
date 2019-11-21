/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Wythe Chao
#   Email         : hi@bug.js.cn
#   File Name     : copy_stdio.c
#   Last Modified : 2019-11-21 17:06
#   Describe      : 使用内部缓存区进行复制
#
# ====================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int c;
    FILE *in, *out;

    in = fopen("file.in","r");
    out = fopen("file.out","w");
    
    while( (c = fgetc(in)) != EOF) {
        fputc(c,out);
    }

    exit(0);
}

