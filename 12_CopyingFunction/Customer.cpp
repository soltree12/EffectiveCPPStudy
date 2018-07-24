#include "Customer.h"

Customer::Customer(const std::string& str)
	: name(str)
{
	logCall("Customer initializer");
}


Customer::Customer(const Customer& rhs)
	:name(rhs.name)
{
	logCall("Customer copy constructor");
}


Customer& Customer::operator=(const Customer& rhs)
{
	logCall("Customer copy assignment operator");
	name = rhs.name;

	return *this;
}

void logCall(const std::string& func)
{
	std::cout << func << std::endl;
}