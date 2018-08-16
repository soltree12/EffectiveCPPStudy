#pragma once
#include <string>
#include "DatabaseID.h"
/* �� Ŭ������ ��Ÿ���� ���� �뵵�� ���� ������ �������̽��Դϴ�. */
class IPerson {
public:
	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;

	static std::shared_ptr<IPerson> makePerson(DatabaseID personIdentifier, std::string name);
};

