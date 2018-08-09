/* PersonInterface를 상속하는 구체 클래스(구현부) */
#pragma once
#include "PersonInterface.h"

class RealPerson : public PersonInterface {
public:
	RealPerson(const std::string& name, const Date& birthday, const Address& addr)
		:theName(name), theBirthDate(birthday), theAddress(addr){}
	virtual ~RealPerson(){}

	virtual std::string name() const;
	virtual std::string birthDate() const;
	virtual std::string address() const;

private:
	std::string theName;
	Date theBirthDate;
	Address theAddress;
};