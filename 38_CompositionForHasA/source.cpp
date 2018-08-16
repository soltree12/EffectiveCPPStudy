/*
항목 38 : "has-a(~는 ~를 가짐)" 혹은 "is-implemented-in-terms-of(~는 ~를 써서 구현됨)"를 모형화할 때는 객체 합성을 사용하자
1. 객체 합성(compositon)의 의미는 public 상속이 가진 의미와 완전히 다릅니다.
2. 응용 영역에서 객체 합성의 의미는 has-a(~는 ~를 가짐)입니다. 구현 영역에서는 is-implemented-in-terms-of(~는 ~를 써서 구현됨)의 의미를 갖습니다.
*/


/*
1. is-a 관계 : ~는 ~의 일종 (Derived는 Base의 일종이다.)
2. has-a관계 : ~는 ~를 가진다.(Person은 이름, 주소, 음성전화를 가진다.)

3. is-implemented-in-terms-of 관계 : ~는 ~를 써서 구현된다,(Set 객체는 list 객체를 써서 구현된다,)
*/
#include "Set.h"
#include <iostream>

int main()
{
	Set<int> s;
	s.insert(3);
	s.insert(4);
	s.remove(4);
	std::cout << s.member(3) << std::endl;
	std::cout << s.member(4) << std::endl;

	return 0;
}