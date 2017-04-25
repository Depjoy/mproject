#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
/* make a dir if dir is not existed */
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
/* get the length of file */
int get_file_len(char *name){
    FILE *fp = NULL;
    int len = -1;
    if((fp = fopen(name,"r+")) == NULL){
        printf("open %s\n",name);
        return 0;
    }
    fseek(fp,0,SEEK_END);
    len = ftell(fp);
    fclose(fp);
    fp = NULL;
    return len; 
}
/* get all the data of file */
char *read(char *name)
{
    int len = -1;
    char *data = NULL;
    FILE *fp = NULL;

    if((len = get_file_len(name)) == 0){
        printf("%s has not data\n",name);
        return -1;
    }
    if((fp = fopen(name,"r+")) == NULL){
        printf("open %s\n",name);
        return -1;
    }

    fseek(fp,0,SEEK_SET);
    if((fread(data,len,1,fp)) != 1){
        printf("read %s failed\n");
        fclose(fp);
        fp = NULL;
        return NULL;
    }
    return data;
}
/* insert 'str'at the position with offset 'off' in the file with 'name' */
int insert(const char *name,long off,char *str)
{
    FILE *fp = NULL;
    if((fp = fopen(name,"r+")) == NULL){
        printf("open %s\n failed",name);
        return -1;
    }

}
