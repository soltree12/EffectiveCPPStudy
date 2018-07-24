#pragma once
#include "Customer.h"

class PriorityCustomer : public Customer {
public:
	PriorityCustomer(const PriorityCustomer& rhs);
	PriorityCustomer(const std::string& str, const int& pri);
	PriorityCustomer& operator=(const PriorityCustomer& rhs);

private:
	int priority;
};
