#pragma once
#include <memory>
template<typename T>


/*
�ذ�å : ���ø� �Ű������� �Լ��� �Ű������� ����. (�Ļ�Ŭ������ ���ø� �Ű������� ������.) 
=> ���� ���� Ÿ���� ��������� ����ϴ� �⺻ Ŭ���� ������ invert �Լ��� ���� �� ���� �纻�� �ȴ�.
*/
template<typename T>
class SquareMatrixBase {
protected: // �Ļ� Ŭ���������� ����� ����
	invert(int matrixsize){}
};

template<typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T> { // private ��� : �⺻ Ŭ������ �Լ��� ����� ����(������ ���)
private:
	using SquareMatrixBase::invert; // �⺻ Ŭ������ invert�� �������� ���� ���� ���� �����Դϴ�.

public:
	void invert()
	{
		this->invert(); // invert�� �⺻ Ŭ���� ������ ���� �ζ��� ȣ���� �����մϴ�.
	}
};

/*
������Ȳ������ �⺻Ŭ������ invert �Լ��� ���� ��ĵ�����(�Ļ� Ŭ������ �ִ�)�� �־������, ���?
1. ��� �����Ͱ� ��� �ִ� �޸� ����� �����ּҸ� ����Ű�� �Ű������� �߰��Ѵ�. (But ��� �Լ����� �Ű������� �޾��ֱ�� ����)
2. BestSquareMatrix ����(��� ���� ��� �޸𸮿� ���� �����͸� SquareMatrixBase�� �����ϰ� ��.) 
*/