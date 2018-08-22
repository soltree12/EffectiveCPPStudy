/*
항목 45) "호환되는 모든 타입"을 받아들이는 데는 멤버 함수 템플릿이 직방!
1. 호환되는 모든 타입을 받아들이는 멤버 함수를 만들려면 멤버 함수 템플릿을 사용합시다.
2. 일반화된 복사 생성 연산과 일반화된 대입 연산을 위해 멤버 템플릿을 선언했다 하더라도, 보통의 복사 생성자와 복사 대입 연산자는 여전히 직접 선언해야 합니다.
*/

#include <iostream>
#include "SmartPtr.h"

int main()
{
	int a = 3;
	SmartPtr<int> s(&a);

	std::cout << *(s.get()) << std::endl;

	return 0;
}