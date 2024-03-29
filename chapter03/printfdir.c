/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Wythe Chao
#   Email         : hi@bug.js.cn
#   File Name     : printfdir.c
#   Last Modified : 2019-11-21 17:18
#   Describe      :
#
# ====================================================*/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth);


int main(void){
    printf("Directory scan of /home/codetoday:\n");
    printdir("/home/codetoday",0);
    printf("done.\n");

    exit(0);
}

void printdir(char *dir, int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if( (dp = opendir(dir)) == NULL ){
        fprintf(stderr,"cannot open directory: %s\n",dir);
        return;
    }

    chdir(dir);
    while( (entry = readdir(dp)) != NULL){
        lstat(entry->d_name,&statbuf);
        if( S_ISDIR(statbuf.st_mode) ) {
            if (strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0){
                continue;
            }
            printf("%*s%s/\n",depth,"",entry->d_name);
            printdir(entry->d_name,depth+4);
        }else{
            printf("%*s%s\n",depth,"",entry->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}


