#ifndef __LOG_H__
#define __LOG_H__
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define MAXLEN 512
#define NO_TIME_LOG_FILE_PATH "./debug/mylog.txt"

/*
    record with system time,line and function in terminal
*/
#define term_sys_t_log(fmt,...){\
	do{\
		time_t cur_t;\
		time(&cur_t);\
		struct tm *cur_tm = localtime(&cur_t);\
		fprintf(stdout,"[%d-%d-%d %d:%d:%d %s:%d %s] ",\
						cur_tm->tm_year + 1900,cur_tm->tm_mon + 1,cur_tm->tm_mday,\
						cur_tm->tm_hour,cur_tm->tm_min,cur_tm->tm_sec,\
						__FILE__,__LINE__,__FUNCTION__);\
		fprintf(stdout,fmt"\n",##__VA_ARGS__);\
	}while(0);\
}

/*
	record compiled time ,line and function in terminal
*/
#define term_com_t_log(fmt,...){\
    do \
    {\
		fprintf(stdout,"[%s %s  %s:%d %s]",\
			__DATE__,__TIME__,\
			__FILE__,__LINE__,\
			__FUNCTION__);\
		fprintf(stdout, fmt"\n",##__VA_ARGS__);\
    }while(0);\
}

void log_ret(const char *fmt, ...);
void log_sys(const char * fmt,...);
void log_msg(const char *fmt,...);
void log_quit(const char *fmt,...);

void log_exit(int error,const char *fmt,...);
void err_ret(const char *fmt, ...);
void err_sys(const char * fmt,...);
void err_cont(int error,const char *fmt,...);
void err_exit(int error,const char *fmt,...);
void err_dump(const char *fmt,...);
void err_msg(const char *fmt,...);
void err_quit(const char *fmt,...);

#endif
