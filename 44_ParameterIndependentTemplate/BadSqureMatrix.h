#pragma once
#include <memory>
template<typename T, std::size_t n> // T Ÿ���� ��ü�� ���ҷ� �ϴ� n�� n���� ����� ��Ÿ���� ���ø�
class SquareMatrix {
public:
	void invert() {} // �־��� ����� �� ����������� ����ķ� ����ϴ�.
};

void func()
{
	SquareMatrix<double, 5> sm1;
	SquareMatrix<double, 10> sm2;

	/* ������ : ���� �ٸ� �Լ��� ��������� => �ڵ� ���ȭ */
	sm1.invert(); // SquareMatrix<double, 5>::invert�� ȣ���մϴ�.
	sm2.invert(); // SquareMatrix<double, 10>::invert�� ȣ���մϴ�.
}