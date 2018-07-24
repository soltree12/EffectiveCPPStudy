/*
항목5) C++가 은근슬쩍 만들어 호출해 버리는 함수들에 촉각을 세우자
1. 컴파일러는 경우에 따라 클래스에 대해 기본 생성자, 복사 생성자, 복사 대입 연산자, 소멸자를 암시적으로 만들어 놓을 수 있습니다.

* 궁금한 점 : C++의 참조자는 원래 자신이 참조하고 있는 것과 다른 객체를 참조할 수 없기 때문 -> 참조할 수 있지 않나?
암시적 복사 대입 연산자를 통한 참조자의 대입은 안된다는 것을 확인했다. 하지만 직접 참조자를 대입하니 잘 되던데.

std::string str1("str1");
std::string str2("str2");
std::string& strr1 = str1;
std::string& strr2 = str2;
str1 = str2; //잘 됨
*/

#include <string>
#include <iostream>
template<typename T>
class NamedObject
{
public:
	NamedObject(std::string& name, const T& value)
		: nameValue(name), objectValue(value){}
	// 멤버 변수에 참조자가 있을 경우에는 명시적 복사 생성자를 만들어놓자.
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