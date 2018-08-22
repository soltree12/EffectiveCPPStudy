/*
항목 46) 타입 변환이 바람직할 경우에는 비멤버 함수를 클래스 템플릿 안에 정의해 두자.
1. 모든 매개변수에 대해 암시적 타입 변환을 지원하는 템플릿과 관계가 있는 함수를 제공하는 클래스 템플릿을 만들려고 한다면, 이런 함수는 클래ㅡ 템플릿 안에 프렌드 함수로서 정의합시다.
*/

#include <iostream>
#include "Rational.h"

int main()
{
	Rational<int> oneEighth(1, 8);
	Rational<int> oneHalf(1, 2);

	Rational<int> result = oneHalf * oneEighth;
	result = oneHalf * 2; // 암시적 생성자 호출(int(2)를 Rational로)
	result.showVal();
	result = 2 * oneHalf; 
	result.showVal();
}