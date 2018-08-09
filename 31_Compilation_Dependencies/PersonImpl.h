/* Person의 구현 클래스 */

#pragma once
#include <string>
#include "Date.h"
#include "Address.h"

class PersonImpl {
public:
	PersonImpl(const std::string& newName, const Date& newBirtday, const Address& newAddr)
		:theName(newName), theBirthday(newBirtday), theAddress(newAddr) {}
	std::string name() const { return theName; }
	Date birthday() const { return theBirthday; }
	Address addr() const { return theAddress; }


private:
	std::string theName;
	Date theBirthday;
	Address theAddress;
};

