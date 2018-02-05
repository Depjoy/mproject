#include <iostream>
#include "Quote.h"

Quote::Quote(){
	std::cout << "Quote - structure Quote without parameter" << std::endl;
}

Quote::Quote(std::string name)
{
	std::cout << "Quote - Structure Quote with Parameter of string " << name << std::endl;
	_protectedValue = 666;
}

std::string Quote::name1()
{
	return "Quote - virtual";
}

std::string Quote::name2()
{
	return "Not Override";
}

std::string Quote::unoverridedFun(void)
{
	return name0();
}