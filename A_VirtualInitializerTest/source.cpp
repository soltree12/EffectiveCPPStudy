/*
�������� ȣ�� ����
�Ļ� �����ڿ��� �⺻������ ȣ�� -> �⺻ ������ ���� -> �Ļ� ������ �ʱ�ȭ -> �Ļ� ������ ����
*/

#include <iostream>
#include <string>

class Base {
public:
	Base();
};

class Derived : public Base{
public:
	Derived(int in_val):val(in_val),
	Base(){
		std::cout << "I'm Derived" << std::endl; }
private:
	int val;
};

Base::Base()
{
	std::cout << "I'm Base" << std::endl;
}

/*
Derived::Derived()
{
	std::cout << "I'm Derived" << std::endl;
}
*/
int main()
{
	Derived der(5);
}