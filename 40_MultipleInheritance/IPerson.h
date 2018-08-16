#pragma once
#include <string>
#include "DatabaseID.h"
/* 이 클래스가 나타내는 것은 용도에 따라 구현될 인터페이스입니다. */
class IPerson {
public:
	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;

	static std::shared_ptr<IPerson> makePerson(DatabaseID personIdentifier, std::string name);
};

