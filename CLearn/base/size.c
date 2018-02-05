#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(int argc,char *argv[])
{
/*
 * pragma pack(n)               align with n bytes.n have to be 2^m
 * pragma pack()                no aligned
 * __attribute__((aligned(n)))  align with n bytes and n = max(sizeof(member's type),n),n have to be 2^m
 * __attribute__((packed))      no aligned
 */

/************************************************************************/
    #pragma pack(1)
    struct s1{
        int d1;
        char d2;
        int d3;
    };
    #pragma pack()
    struct s2{
        int d1;
        char d2;
        int d3;
    };
    struct s3{
        int d1;
        char d2;
        int d3;
    }__attribute__((packed));
    
    struct s4{
        int d1;
        char d2;
        int d3;
    }__attribute__((aligned(1)));
    
    printf("sizeof(s1) = %lu\tsizeof(s2) = %lu sizeof(s3) = %lu sizeof(s4) = %lu sizeof(int)=%lu sizeof(char)=%lu\n",
           sizeof(struct s1),sizeof(struct s2),sizeof(struct s3),
           sizeof(struct s4),sizeof(int),sizeof(char));
    struct s1 t1 = {8,6,7};
    struct s2 t2 = {8,6,7};
    struct s3 t3 = {8,6,7};
    struct s4 t4 = {8,6,7};
    char buf[32] = {0};
    memcpy(buf,&t1,sizeof(t1));
    int i = 0;
    printf("t1\t");
    for(;i < sizeof(t1);i++)
        printf("%d ",buf[i]);
    printf("\n");

    memcpy(buf,&t2,sizeof(t2));
    i = 0;
    printf("t2\t");
    for(;i < sizeof(t2);i++)
        printf("%d ",buf[i]);
    printf("\n");
    
    memcpy(buf,&t3,sizeof(t3));
    i = 0;
    printf("t3\t");
    for(;i < sizeof(t3);i++)
        printf("%d ",buf[i]);
    printf("\n");
    
    memcpy(buf,&t4,sizeof(t4));
    i = 0;
    printf("t4\t");
    for(;i < sizeof(t4);i++)
        printf("%d ",buf[i]);
    printf("\n");
    return 0;
/*****************************************************************/
}
