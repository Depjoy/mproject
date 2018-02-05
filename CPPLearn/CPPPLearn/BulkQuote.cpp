#include <iostream>
#include <string>

#include "BulkQuote.h"

BulkQuote::BulkQuote()
	:Quote()
{
	std::cout << "BulkQuote - struct BulkQuote witout name " << std::endl;
}

BulkQuote::BulkQuote(std::string name)
	: Quote(name){
	std::cout << "BulkQuote - struct BulkQuote with name " << name << std::endl;
}

std::string BulkQuote::name0()
{
	//Pure virtual function has to be override.
	return "BulkQuote - Pure Virtual";
}

std::string BulkQuote::name1()
{
	return "BulkQuote - Override name1";
}

std::string BulkQuote::name3() const
{ 
	return "BulkQuote - Const";
}

void BulkQuote::potectedTest()
{
	//child can get protected value in parent.
	std::cout << "Protected value in Quote : " << _protectedValue << std::endl;
}

float BulkQuote::total(float price, int num)
{
	return price * num;
}

float BulkQuote::total(float price, int num, float discout)
{
	return price * num * discout;
}