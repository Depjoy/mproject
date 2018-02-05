#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    const char **pp;    //*(*pp + 1u) is read-only
    const char p;       //p is read-only
    const char *p1;     //*(p + 1u) is read-only
    char *const p2;     // p is read-only
    char * const * p3;  // *p3 read-only location
    
the best way to rember:
    * is taken as 'pointer to' and from back to front 
*/
void foo(const char **pp)
{
    //*(*pp + 1u) is read-only
    *pp=NULL; //allowed
    *pp="Hello world!"; //allowed
    *pp = (char *) malloc(10);
    snprintf((char *)*pp, 10, "hi google!");
    //(*pp)[1] = 'x'; //*(*pp + 1u) is read-only
    //free((char *)*pp); 
}

int main(int argc,char *argv[])
{
    const char *p="hello";
    printf("before foo %s\n",p);
    foo(&p);
    printf("after foo %s\n",p);

    const char p0 = 'a'; //p is read-only
    printf("p0 before change value %c\n",p0);
    //p = 'b';
    //printf("p0 after change value %c\n",p0);

    const char *p1 = "hello";//*(p + 1u) is read-only
    printf("p1 before change %s\n",p1);
    char *tmp1 = "change";
    p1 = tmp1;
    printf("p1 after change %s\n",p1);
    //p1[1] = 'x';
    
    char * const p2 = "hello"; // p is read-only
    printf("before change %s\n",p2);
    char *tmp2 = "change";
    //p2 = tmp2;
    //printf("const value after change %s\n",p2);
 
#if 0
    char * const * p3;// *p3 read-only location
    *p3 = NULL;
    char *tmp = "hello";
    *p3 = tmp;
    printf("change %s %s\n",tmp,*p3);
#endif
    
    return 0;
}
