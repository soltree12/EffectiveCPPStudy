/* 가상 생성자(팩토리 함수)는 따로 cpp파일 만들어서 정의(파생 클래스를 Include해야하기 때문인듯) */

#include "PersonInterface.h"
#include "RealPerson.h"

std::shared_ptr<PersonInterface> PersonInterface::create(const std::string& name, const Date& birthday, const Address& addr)
{
	return std::shared_ptr<PersonInterface>(new RealPerson(name, birthday, addr));
}