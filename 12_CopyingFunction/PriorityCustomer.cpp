#include "PriorityCustomer.h"

PriorityCustomer::PriorityCustomer(const std::string& str, const int& pri)
	:Customer(str), priority(pri)
{
	logCall("PriorityCustomer initializer");
}

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
	:Customer(rhs), priority(rhs.priority)
{
	logCall("PriorityCustomer copy constructor");
}


PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
	logCall("PriorityCustomer copy assignment operator");

	Customer::operator=(rhs);
	priority = rhs.priority;

	return *this;
}
