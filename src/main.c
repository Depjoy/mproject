#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/stat.h>
#include "log/log.h"
#include "file/file.h"


#define SHARE_PATH "../lib/libshare.so"
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
    fprintf(stdout,"time %lu\n",func());
    dlclose(handle);

    /**/
    return 0;
}
