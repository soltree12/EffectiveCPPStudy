#pragma once
#include <memory>
#include <iostream>
/* 행렬 값을 담는 메모리에 대한 포인터를 SquareMatrixBase가 저장하게 하기 */
template<typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(std::size_t n, T *pMem) : size(n), pData(pMem){} // 행렬 크기를 저장하고, 행렬 값에 대한 포인터를 저장합니다.
	void setDataPtr(T *ptr) { pData = ptr; } // pData에 다시 대입합니다.
	void invert(std::size_t matrixsize) { std::cout << "SquareMatrixBase::invert" << std::endl; }
private:
	std::size_t size; // 행렬의 크기
	T *pData; // 행렬 값에 대한 포인터
};

template<typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T> {
private:
	using SquareMatrixBase<T>::invert;
public:
	SquareMatrix():SquareMatrixBase<T>(n,0), pData(new T[n*n]) // 기본 클래스의 포인터를 널로 설정하고, 행렬 값의 메모리를 할당하고,
	{
		this->setDataPtr(pData.get()); // 파생 클래스의 포인터에 그 메모리를 물려 놓은 후, 이 포인터의 사본을 기본 클래스로 올려보냅니다.
	}
	void invert()
	{
		this->invert(n); // invert의 기본 클래스 버전에 대해 인라인 호출을 수행합니다.
	}
private:
	std::unique_ptr<T> pData; 
};