/*
�׸�5) C++�� ���ٽ�½ ����� ȣ���� ������ �Լ��鿡 �˰��� ������
1. �����Ϸ��� ��쿡 ���� Ŭ������ ���� �⺻ ������, ���� ������, ���� ���� ������, �Ҹ��ڸ� �Ͻ������� ����� ���� �� �ֽ��ϴ�.

* �ñ��� �� : C++�� �����ڴ� ���� �ڽ��� �����ϰ� �ִ� �Ͱ� �ٸ� ��ü�� ������ �� ���� ���� -> ������ �� ���� �ʳ�?
�Ͻ��� ���� ���� �����ڸ� ���� �������� ������ �ȵȴٴ� ���� Ȯ���ߴ�. ������ ���� �����ڸ� �����ϴ� �� �Ǵ���.

std::string str1("str1");
std::string str2("str2");
std::string& strr1 = str1;
std::string& strr2 = str2;
str1 = str2; //�� ��
*/

#include <string>
#include <iostream>
template<typename T>
class NamedObject
{
public:
	NamedObject(std::string& name, const T& value)
		: nameValue(name), objectValue(value){}
	// ��� ������ �����ڰ� ���� ��쿡�� ����� ���� �����ڸ� ��������.
	NamedObject& operator=(const NamedObject& rhs) 
	{

		this->nameValue = rhs.nameValue;
		this->objectValue = rhs.objectValue;
		return *this;
	}
	void show()
	{
		std::cout << nameValue << "/" << objectValue << std::endl;
	}

private:
	std::string& nameValue;
	T objectValue;
};





int main()
{
	std::string newDog("Persephone");
	std::string oldDog("Satch");

	NamedObject<int> p(newDog, 2);
	NamedObject<int> s(oldDog, 36);
	p = s;
	p.show();
	s.show();
	return 0;
}