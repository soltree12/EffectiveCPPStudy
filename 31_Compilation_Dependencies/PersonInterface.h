/*
(해결책)
2. 인터페이스 클래스 : 어떤 기능을 나타내는 인터페이스를 추상 기본 클래스를 통해 마련해 놓고, 이 클래스로부터 파생 클래스를
만들 수 있게 하자.
인터페이스 클래스를 사용하기 위해서는 객체 생성 수단이 최소한 하나는 있어야 한다. 이 문제는 파생 클래스의 생성자 역할을 대신하는
어떤 함수를 만들어 놓고 이것을 호출함으로써 해결한다.(팩토리함수 혹은 가상 생성자 이용)

*/

#pragma once
#include <iostream>
#include "Date.h"
#include "Address.h"

class PersonInterface {
public:
	/* 주어진 인터페이스 클래스의 인터페이스를 지원하는 객체를 동적으로 할당한 후, 그 객체의 포인터를 반환(정적 멤버로 선언되는 경우가 많음)*/
	static std::shared_ptr<PersonInterface> create(const std::string& name, const Date& birthday, const Address& addr);

	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;
	virtual std::string address() const = 0;
};

