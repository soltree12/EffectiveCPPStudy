/*
생성자의 호출 순서
파생 생성자에서 기본생성자 호출 -> 기본 생성자 실행 -> 파생 생성자 초기화 -> 파생 생성자 실행
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