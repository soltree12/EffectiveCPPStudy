/* 
항목 31) 파일 사이의 컴파일 의존성을 최대로 줄이자
1. 컴파일 의존성을 최소화하는 작업의 배경이 되는 가장 기본적인 아이디어는 '정의' 대신에 '선언'에 의존하게 만들자는 것입니다. 이 아이디어에 기반한
두 가지 접근 방법은 핸들 클래스와 인터페이스 클래스입니다.
2. 라이브러리 헤더는 그 자체로 모든 것을 갖추어야 하며 선언부만 갖고 있는 형태여야 합니다. 이 규칙을 템플릿이 쓰이거나 쓰이지 않거나
동일하게 적용합시다.

*/

#include "PersonInterface.h" // 인터페이스만 include해도 구현부의 함수도 쓸 수 있다.
#include "GoodPerson.h"

int main()
{

	std::string name = "Min";
	Date dateOfBirth("1000");
	Address address("Seoul");

	/* pimpl(핸들 클래스)을 이용한 객체 생성 */
	Person p(name, dateOfBirth, address);
	std::cout << "My name is "<<p.name() << std::endl;
	
	/* 인터페이스 클래스를 이용한 객체 생성 */
	std::shared_ptr<PersonInterface> pp(PersonInterface::create(name, dateOfBirth, address));
	std::cout << pp->name()
		<< " was born on "
		<< pp->birthDate()
		<< " and now lives at "
		<< pp->address()
		<< std::endl;


	return 0;
}