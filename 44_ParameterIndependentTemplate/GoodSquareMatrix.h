#pragma once
#include <memory>
template<typename T>


/*
해결책 : 템플릿 매개변수를 함수의 매개변수로 뺀다. (파생클래스로 템플릿 매개변수를 내린다.) 
=> 같은 원소 타입의 정방행렬이 사용하는 기본 클래스 버전의 invert 함수도 오직 한 개의 사본이 된다.
*/
template<typename T>
class SquareMatrixBase {
protected: // 파생 클래스에서만 사용할 목적
	invert(int matrixsize){}
};

template<typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T> { // private 상속 : 기본 클래스의 함수를 사용할 목적(구현만 상속)
private:
	using SquareMatrixBase::invert; // 기본 클래스의 invert가 가려지는 것을 막기 위한 문장입니다.

public:
	void invert()
	{
		this->invert(); // invert의 기본 클래스 버전에 대해 인라인 호출을 수행합니다.
	}
};

/*
실제상황에서는 기본클래스의 invert 함수에 실제 행렬데이터(파생 클래스에 있는)도 넣어줘야함, 어떻게?
1. 행렬 데이터가 들어 있는 메모리 덩어리의 시작주소를 가리키는 매개변수를 추가한다. (But 모든 함수마다 매개변수를 달아주기는 귀찮)
2. BestSquareMatrix 참조(행렬 값을 담는 메모리에 대한 포인터를 SquareMatrixBase가 저장하게 함.) 
*/