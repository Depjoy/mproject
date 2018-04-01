#include <iostream>

/*
 * difference of pointer and qupte
 * address and value of pointer both can be changed
 * value of quote can be changed,but address cannot be change
*/
int main(int argc, char *argv[])
{
    struct test{
        int a;
        float b;
    };

    struct test tmp,tmp0;
    tmp.a = 8;
    tmp.b = 3.14;

    tmp0.a = 6;
    tmp0.b = 8.65;

    struct test *tmp1 = &tmp;
    std::cout << std::endl <<  "adderss of tmp " << &tmp  <<  " adderss of tmp0 " << &tmp0 << std::endl;
    std::cout <<  "pointer                   " << tmp1->a << "\t"<< tmp1->b << "\t" << tmp1<< std::endl;
    tmp1 = &tmp0;
    std::cout << "pointer address change    " << tmp1->a << "\t"<< tmp1->b << "\t" << tmp1<< std::endl<< std::endl;

    struct test&tmp2(tmp);
    std::cout << std::endl <<  "pointer    " << tmp2.a << "\t" << tmp2.b << std::endl;
    tmp2 = tmp0;
    std::cout <<  "pointer value change " << tmp2.a << "\t" << tmp2.b << "\t" << &tmp2 << std::endl;
    tmp2.a = 30;
    tmp2.b = 90.21;
    std::cout <<  "quote value change " << tmp2.a << "\t" << tmp2.b << "\t" << &tmp2 << std::endl;
//    &tmp2 = &tmp0;
    return 0;

}

