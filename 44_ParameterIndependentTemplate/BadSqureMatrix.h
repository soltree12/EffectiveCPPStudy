#pragma once
#include <memory>
template<typename T, std::size_t n> // T 타입의 객체를 원소로 하는 n행 n열의 행렬을 나타내는 템플릿
class SquareMatrix {
public:
	void invert() {} // 주어진 행렬을 그 저장공간에서 역행렬로 만듭니다.
};

void func()
{
	SquareMatrix<double, 5> sm1;
	SquareMatrix<double, 10> sm2;

	/* 문제점 : 서로 다른 함수가 만들어진다 => 코드 비대화 */
	sm1.invert(); // SquareMatrix<double, 5>::invert를 호출합니다.
	sm2.invert(); // SquareMatrix<double, 10>::invert를 호출합니다.
}