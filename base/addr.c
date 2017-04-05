#include <stdlib.h>
#include <stdio.h>
/*
    change a pointer to other address,just content of the pointer is changed.
    change the content of a pointer of pointer to other address,
    old content and the new content of the pointer of pointer is both changed.

result:
    mp 18 0x7fff990a0e30	m 18 0x7fff990a0e30
    mp 28 0x7fff990a0e34	m 18 0x7fff990a0e30	n 28 0x7fff990a0e34

    ip1 6 0x7fff990a0e38	ip2 8 0x7fff990a0e3c
    ip1 6 0x7fff990a0e38	ip2 6 0x7fff990a0e38	ipip 8 0x7fff990a0e3c
    ip1 8 0x7fff990a0e3c	ip2 8 0x7fff990a0e3c	ipip 8 0x7fff990a0e3c
    
    the tested code is following:
*/

int main(int argc,char *argv[])
{
    int m = 18,n = 28;
    int *mp = &m;
    printf("mp %d %p\tm %d %p\n",*mp,mp,m,&m);
    mp = &n;
    printf("mp %d %p\tm %d %p\tn %d %p\n\n",*mp,mp,m,&m,n,&n);

    int i = 6,j = 8;
    int *ip1 = &i,*ip2 = &j;
    printf("ip1 %d %p\tip2 %d %p\n",*ip1,ip1,*ip2,ip2);
    int **ipip = &ip1;
    printf("ip1 %d %p\tip2 %d %p\tipip %d %p\n",**ipip,*ipip,*ip1,ip1,*ip2,ip2);
    *ipip = ip2;
    printf("ip1 %d %p\tip2 %d %p\tipip %d %p\n",**ipip,*ipip,*ip1,ip1,*ip2,ip2);
    return 0;
}
