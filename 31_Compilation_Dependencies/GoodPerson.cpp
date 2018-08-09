#include "GoodPerson.h" // Person Ŭ������ �����ϰ� �ִ� ���̱� ������, �� Person�� Ŭ���� ���Ǹ� #include�ؾ� �մϴ�.
#include "PersonImpl.h" // �̿� ���ÿ� PersonImpl�� Ŭ���� ���ǵ� #include�ؾ� �ϴµ�, �̷��� ���� ������ ��� �Լ��� ȣ���� �� �����ϴ�.
//�� ���ø� PersonImpl�� ��� �Լ��� Person�� ��� �Լ��� �ϴ��Ϸ� �����ǰ� ������ �� �� �ֽ��ϴ�. �������̽��� �Ȱ����ϴ�.

Person::Person(const std::string& name, const Date& birthday, const Address& addr)
	:pImpl(new PersonImpl(name,birthday,addr)){}

std::string Person::name() const
{
	return pImpl->name();
}

