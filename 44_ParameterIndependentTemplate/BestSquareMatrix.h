#pragma once
#include <memory>
#include <iostream>
/* ��� ���� ��� �޸𸮿� ���� �����͸� SquareMatrixBase�� �����ϰ� �ϱ� */
template<typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(std::size_t n, T *pMem) : size(n), pData(pMem){} // ��� ũ�⸦ �����ϰ�, ��� ���� ���� �����͸� �����մϴ�.
	void setDataPtr(T *ptr) { pData = ptr; } // pData�� �ٽ� �����մϴ�.
	void invert(std::size_t matrixsize) { std::cout << "SquareMatrixBase::invert" << std::endl; }
private:
	std::size_t size; // ����� ũ��
	T *pData; // ��� ���� ���� ������
};

template<typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T> {
private:
	using SquareMatrixBase<T>::invert;
public:
	SquareMatrix():SquareMatrixBase<T>(n,0), pData(new T[n*n]) // �⺻ Ŭ������ �����͸� �η� �����ϰ�, ��� ���� �޸𸮸� �Ҵ��ϰ�,
	{
		this->setDataPtr(pData.get()); // �Ļ� Ŭ������ �����Ϳ� �� �޸𸮸� ���� ���� ��, �� �������� �纻�� �⺻ Ŭ������ �÷������ϴ�.
	}
	void invert()
	{
		this->invert(n); // invert�� �⺻ Ŭ���� ������ ���� �ζ��� ȣ���� �����մϴ�.
	}
private:
	std::unique_ptr<T> pData; 
};