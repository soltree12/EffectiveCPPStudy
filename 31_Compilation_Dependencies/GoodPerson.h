#pragma once
/*
(�ذ�å)
1. �ڵ� Ŭ���� : pimpl(pointer to implementation) ���뱸�� �̿��� Ŭ����(������ ����� ����Ŭ����(PersonImpl)�� ���� �����͹ۿ� ������ ����)
�̷��� �����صθ�, Person�� ����ڴ� ���������� ���λ��װ� ������ ���󼭰� �ȴ�. Person Ŭ������ ���� ���� Ŭ���� �κ���
�ٽ� ���ĵ�, Person�� ����� �ʿ����� �������� �ٽ� �� �ʿ䰡 ����.
*/
#include <string> // ǥ�� ���̺귯�� ������Ҵ� ���� ������ �ϸ� �� �˴ϴ�.
#include <memory> // shared_ptr�� ���� ���

class PersonImpl; // Person�� ���� Ŭ������ ���� ���漱��

class Date; // Person Ŭ���� �ȿ��� ����ϴ� �͵鿡 ���� ���� ����
class Address;

class Person {
public:
	Person(const std::string& name, const Date& birthday, const Address& addr);
	std::string name() const;
	std::string birthDate() const;
	std::string address() const;

private:
	std::shared_ptr<PersonImpl> pImpl; // ����Ŭ���� ��ü�� ���� ������
};