#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <syslog.h>
#include "log/log.h"

/*first bit  : terminate
 *second bit : daemon
 *third  bit : specific file
*/
int log_to_stderr = 5; 
static FILE *fp = NULL;

int open_log_file(const char *name)
{   
    if((fp = fopen(name,"a+"))== NULL){
        printf("open %s failed\n",name);
        return -1;
    }
    return 0;
}

void close_log_file(void)
{
    fclose(fp);
    fp = NULL;
}
/*
 * initialize syslog(),if running as daemon
*/                      
void log_open(const char *ident,int option,int facility)
{
    if(!log_to_stderr){
        openlog(ident,option,facility);
    }
}
/*
 * Print a message and return to caller
*/
static void log_doit(int errno_flag,int error,int priority,const char *fmt,va_list ap)
{
    char buf[MAXLEN] = {0}; 
    vsprintf(buf,fmt,ap);
    //vsnprintf(buf,MAXLEN - 1,fmt,ap);
    int len = strlen(buf);
    if(errno_flag){
        if(buf[len - 1] == 10)
            sprintf(buf + strlen(buf) - 1,": %s",strerror(error));
        else
            sprintf(buf + strlen(buf),": %s",strerror(error));
        //snprintf(buf + strlen(buf),MAXLEN - strlen(buf) - 1,": %s",strerror(errno));
    }
    if(buf[len - 1] != 10)
        strcat(buf,"\n");
    if(log_to_stderr & 0x02){
        syslog(priority,"%s",buf);
    }
}

/*
* Nonfatal error related to system call.
*/
void log_ret(const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt);
    log_doit(1,errno,LOG_ERR,fmt,ap);
    va_end(ap);
}

/*
 * Fatal error ralated to a system call
*/
void log_sys(const char * fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    log_doit(1,errno,LOG_ERR,fmt,ap);
    va_end(ap);
    exit(2);
}
/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
* */
void log_msg(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    log_doit(0,0,LOG_ERR,fmt,ap);
    va_end(ap);
}
/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
 void log_quit(const char *fmt,...)
 {
    va_list ap;
    va_start(ap,fmt);
    log_doit(0,0,LOG_ERR,fmt,ap);
    va_end(ap);
    exit(2);   
 }
/*
 * Nonfatal error ralated to a system call.
 * Error code passed as explict parameter.
*/
void log_exit(int error,const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    log_doit(1,error,LOG_ERR,fmt,ap);
    va_end(ap);
    exit(2);
}
/*
 * Print a message and return to caller
*/
static void err_doit(int errno_flag,int error,const char *fmt,va_list ap)
{
    char buf[MAXLEN] = {0}; 
    vsprintf(buf,fmt,ap);
    //vsnprintf(buf,MAXLEN - 1,fmt,ap);
    int len = strlen(buf);
    if(errno_flag){
        if(buf[len - 1] == 10)
            sprintf(buf + strlen(buf) - 1,": %s",strerror(error));
        else
            sprintf(buf + strlen(buf),": %s",strerror(error));
        //snprintf(buf + strlen(buf),MAXLEN - strlen(buf) - 1,": %s",strerror(errno));
    }
    if(buf[len - 1] != 10)
        strcat(buf,"\n");
    if(log_to_stderr & 0x01){
        fflush(stdout);
        fputs(buf,stderr);
        fflush(NULL);
    }
    if(log_to_stderr & 0x04){
        if(fp == NULL){
          open_log_file(NO_TIME_LOG_FILE_PATH);
        }
        fputs(buf,fp);
    }
}
/*
* Nonfatal error related to system call.
*/
void err_ret(const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
}

/*
 * Fatal error ralated to a system call
*/
void err_sys(const char * fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
    exit(1);
}
/*
 * Nonfatal error ralated to a system call.
 * Error code passed as explict parameter.
*/
void err_cont(int error,const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,error,fmt,ap);
    va_end(ap);
}
/*
 * Nonfatal error ralated to a system call.
 * Error code passed as explict parameter.
*/
void err_exit(int error,const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,error,fmt,ap);
    va_end(ap);
    exit(1);
}
/*
* Fatal error related to a system call.
* Print a message,dump core and terminate.
*/
void err_dump(const char *fmt,...)
{ 
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
    abort();
    exit(1);
    
}
/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
* */
void err_msg(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(0,0,fmt,ap);
    va_end(ap);
}
/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
 void err_quit(const char *fmt,...)
 {
    va_list ap;
    va_start(ap,fmt);
    err_doit(0,0,fmt,ap);
    va_end(ap);
    exit(1);   
 }
