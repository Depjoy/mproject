#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int s_mkdir(const char *name,int wr_mode,int mk_mode)
{
    if(access(name,wr_mode) != 0){
        if(mkdir(name,mk_mode) != 0){
            printf("create file name %s failed\n",name);
            return -1;
        }else{
            return 0;
        }
    }
    return 0;
}

