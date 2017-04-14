#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define min(x,y) ({ \
typeof(x) _min1 = (x); \
typeof(y) _min2 = (y); \
(void)(&_min1 == &_min2); \
(_min1 > _min2) ? _min2:_min1; \
})
#define _STR(s) #s
#define STR(s) _STR(s)
#define _CONS(a,b) a##b
#define CONS(a,b) _CONS(a,b)
int main(int argc,char *argv[])
{
    struct t{
        char *name;
        int age;
    };
    struct t t1;
    t1.name = "neil";
    t1.age = 26;
    printf("%s\n",STR(TEST));
    printf("%s\n",STR());
    printf("%s\n",STR(INT_MAX));
    printf("%s\n",t1.CONS(name,));
    int x = 2;
    char y = "\0";
    printf("%d\n",*(int *)&y);
    printf("%d\n",min(x,y));
    return 0;
}
