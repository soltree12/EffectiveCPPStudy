#pragma once
#include <iostream>
#include <string>
void logCall(const std::string& function);

class Customer {
public:
	Customer(const Customer &rhs);
	Customer(const std::string& str);
	Customer& operator=(const Customer &rhs);

private:
	std::string name;
};