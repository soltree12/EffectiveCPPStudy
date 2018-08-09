#pragma once
#include <string>
class Address{
public:
	Address(const std::string& newStr) : str(newStr){}
	std::string getAddress() const { return str; }
private:
	std::string str;
};