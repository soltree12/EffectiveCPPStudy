/*
항목 44) 매개변수에 독립적인 코드는 템플릿으로부터 분리시키자.
1. 템플릿을 사용하면 비슷비슷한 클래스와 함수가 여러 벌 만들어집니다. 따라서 템플릿 매개변수에 종속되지 않은 템플릿 코드는 비대화의 원인이 됩니다.
2. 비타입 템플릿 매개변수로 생기는 코드 비대화의 경우, 템플릿 매개변수를 함수 매개변수 혹은 클래스 데이터 멤버로 대체함으로써 비대화를 종종 없앨 수 있습니다.
3. 타입 매개변수로 생기는 코드 비대화의 경우, 동일한 이진 표현구조를 가지고 인스턴스화되는 타입들이 한 가지 함수 구현을 공유하게 만듦으로써 비대화를 감소시킬 수 있습니다.
*/

#include <iostream>
#include "BestSquareMatrix.h"

int main()
{
	SquareMatrix<int, 5> s;
	s.invert();
}