#pragma once

/* 
(�������� ����)
�Ʒ��� #include���� Pserson�� ������ ���ϰ� �Ʒ��� ��� ���ϵ� ���̿� ������ �������� ���� ������.
�׷��� �Ʒ��� ��� ���� �� �� �ϳ��� �ٲ�� ���� �����̰� �̵�� �� ���� �ִ� ��� ���ϵ��� �ٲ�⸸ �ص�,
PersonŬ������ ������ ����, Person�� ����ϴ� �ٸ� ���ϵ���� ���� �ٽ� �����ϵǾ�� �Ѵ�.
*/
#include <string>
#include "Date.h"
#include "Address.h"

class Person {
public:
	Person(const std::string& name, const Date& birthday, const Address& addr);
	std::string name() const;
	std::string birthDate() const;
	std::string address() const;

private:
	std::string theName;
	Date theBirthDate;
	Address theAddress;
};
