#pragma once
#include <string>
class Date{
public:
	Date(const std::string& newStr) : str(newStr){}
	std::string getDate() const { return str; }
private:
	std::string str;
};