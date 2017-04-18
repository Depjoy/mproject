#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/stat.h>
#include <setjmp.h>
#include "log/log.h"
#include "file/file.h"

#define SHARE_PATH "../lib/libshare.so"
//#define SETJMP_DEBUG

#ifdef SETJMP_DEBUG
static jmp_buf jmp;
static int glob_val;
static void f1(int i,int j,int k,int l){
    fprintf(stdout,"in function named f1 :\n");
    fprintf(stdout,"\tglobal %d auto %d regeister %d volatile %d static %d\n",
                glob_val,i,j,k,l);
    longjmp(jmp,1);
}
#endif
int main(int argc,char *argv[])
{
    /* creat a file in specific path */
    s_mkdir("file",W_OK,S_IRWXU);

    /* denamic call .so */
    typedef uint64_t (*SHARE_FUN)(void);
    void * handle;
    SHARE_FUN func = NULL;

    if((handle = dlopen(SHARE_PATH,RTLD_LAZY)) == NULL){
        fprintf(stderr,"dlopen %s failed %s\n",SHARE_PATH,dlerror());
        return -1;
    }
    dlerror();//clear exsited error
    if((func = dlsym(handle,"micro64")) ==NULL){
        fprintf(stderr,"dlsym failed %s\n",dlerror());
        return -1;
    }
    fprintf(stdout,"time %llu\n",func());
    dlclose(handle);

    /*whethe the value of the varible will be changed after longjmp*/
#ifdef SETJMP_DEBUG
    glob_val = 1;
    int ato_val = 2;
    register int reg_val = 3;
    volatile int vol_val = 4;
    static int sta_val = 5;

    if(setjmp(jmp) != 0){
        fprintf(stdout,"after call longjmp\n");
        fprintf(stdout,"\tglobal %d auto %d regeister %d volatile %d static %d\n",
                glob_val,ato_val,reg_val,vol_val,sta_val);
        exit(0);
    }

    glob_val = 95;
    ato_val = 96;
    reg_val = 97;
    vol_val = 98;
    sta_val = 99;

    f1(ato_val,reg_val,vol_val,sta_val);
    exit(0);
#endif
    return 0;
}
