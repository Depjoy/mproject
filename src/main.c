#include <unistd.h>
#include <sys/stat.h>
#include "log/log.h"
#include "file/file.h"
#include "log/log.h"

int main(int argc,char *argv[])
{
    term_sys_t_log("Yeah,test successfully");
    term_com_t_log("Yeah,test successfully");
    s_mkdir("file",W_OK,S_IRWXU);
    return 0;
}
