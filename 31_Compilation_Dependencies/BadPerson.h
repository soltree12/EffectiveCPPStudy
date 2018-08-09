#pragma once

/* 
(부적절한 구현)
아래의 #include문은 Pserson을 정의한 파일과 아래의 헤더 파일들 사이에 컴파일 의존성을 엮어 버린다.
그러면 아래의 헤더 파일 셋 중 하나라도 바뀌는 것은 물론이고 이들과 또 엮여 있는 헤더 파일들이 바뀌기만 해도,
Person클래스를 정의한 파일, Person을 사용하는 다른 파일들까지 몽땅 다시 컴파일되어야 한다.
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
