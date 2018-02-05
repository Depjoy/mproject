#include <string>

class Quote{
public:
	Quote();
	Quote(std::string name);
	virtual std::string name0() = 0;
	virtual std::string name1();
	virtual std::string name2();
	std::string unoverridedFun(void);
protected:
	int _protectedValue;
};