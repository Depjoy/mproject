#include "Quote.h"

class BulkQuote : public Quote
{
public:
	BulkQuote();
	BulkQuote(std::string name);
	virtual std::string name0() override;
	virtual std::string name1();
	virtual std::string name3() const;
	float total(float price, int num);
	float total(float price, int num, float discout);
	void potectedTest();
};
