#include "GoodPerson.h" // Person 클래스를 구현하고 있는 중이기 때문에, 이 Person의 클래스 정의를 #include해야 합니다.
#include "PersonImpl.h" // 이와 동시에 PersonImpl의 클래스 정의도 #include해야 하는데, 이렇게 하지 않으면 멤버 함수를 호출할 수 없습니다.
//잘 보시면 PersonImpl의 멤버 함수는 Person의 멤버 함수와 일대일로 대응되고 있음을 알 수 있습니다. 인터페이스가 똑같습니다.

Person::Person(const std::string& name, const Date& birthday, const Address& addr)
	:pImpl(new PersonImpl(name,birthday,addr)){}

std::string Person::name() const
{
	return pImpl->name();
}

