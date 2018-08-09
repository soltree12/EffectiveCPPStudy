#pragma once
/*
(해결책)
1. 핸들 클래스 : pimpl(pointer to implementation) 관용구를 이용한 클래스(데이터 멤버는 구현클래스(PersonImpl)에 대한 포인터밖에 없도록 설계)
이렇게 설계해두면, Person의 사용자는 자질구레한 세부사항과 완전히 갈라서게 된다. Person 클래스에 대한 구현 클래스 부분을
다시 고쳐도, Person의 사용자 쪽에서는 컴파일을 다시 할 필요가 없다.
*/
#include <string> // 표준 라이브러리 구성요소는 전방 선언을 하면 안 됩니다.
#include <memory> // shared_ptr을 위한 헤더

class PersonImpl; // Person의 구현 클래스에 대한 전방선언

class Date; // Person 클래스 안에서 사용하는 것들에 대한 전방 선언
class Address;

class Person {
public:
	Person(const std::string& name, const Date& birthday, const Address& addr);
	std::string name() const;
	std::string birthDate() const;
	std::string address() const;

private:
	std::shared_ptr<PersonImpl> pImpl; // 구현클래스 객체에 대한 포인터
};