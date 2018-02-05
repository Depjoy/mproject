#if 1
#include <iostream>
#include "BulkQuote.h"

/*
	parent : Quote
	child  : BulkQuote
	@brife : This demo try to test and displsy the unstanding inherit and dynamic binding
			 only virtual function can be overrided ,otherwise that function will be inherited
			 by child directly.
*/
void inheritUnstandingTest(void)
{
	std::cout << "================== test 0 ================== " << std::endl;
	BulkQuote* _bulkQuote = new BulkQuote("Hello Inherit");
	std::string name = _bulkQuote->name0();
	std::cout << name << std::endl;

	name = _bulkQuote->name1();
	std::cout << name << std::endl;

	name = _bulkQuote->name2();
	std::cout << name << std::endl;

	float total1 = _bulkQuote->total(12.8, 10);
	float total2 = _bulkQuote->total(12.8, 10, 0.1);
	std::cout << "Dynamic binding test " << total1 << "  " << total2 << std::endl;

	name = _bulkQuote->unoverridedFun();
	std::cout << "insteresting Dynamic binding to BulkQuote's name0 " << name << std::endl;
	std::cout << std::endl << "================== test 1 ================== " << std::endl;
	_bulkQuote->potectedTest();

	std::cout << std::endl << "================== test 2 ================== " << std::endl;
	/*not allowed as pure virtual fuction is contained */
	//Quote* _quote = new Quote();
	Quote* _quote = _bulkQuote;
	name = _quote->name1();
	std::cout << name << std::endl;

	std::cout << std::endl << "================== test 3 ================== " << std::endl;
	const BulkQuote constBulkQuote;
	std::string name3 = constBulkQuote.name3();
	std::cout << name3 << std::endl;
	// name3 = constBulkQuote.name1(); //not allowed
}

int main(int argc, char*argv[])
{
	inheritUnstandingTest();
	system("pause");
}
#endif
