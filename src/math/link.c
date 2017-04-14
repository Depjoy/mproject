#include <stdio.h>
#include "stime.h"

int main(int argc,char *argv[])
{
    fprintf(stdout,"time %lu\n",micro64());
    return 0;
}
