/*
�׸� 46) Ÿ�� ��ȯ�� �ٶ����� ��쿡�� ���� �Լ��� Ŭ���� ���ø� �ȿ� ������ ����.
1. ��� �Ű������� ���� �Ͻ��� Ÿ�� ��ȯ�� �����ϴ� ���ø��� ���谡 �ִ� �Լ��� �����ϴ� Ŭ���� ���ø��� ������� �Ѵٸ�, �̷� �Լ��� Ŭ���� ���ø� �ȿ� ������ �Լ��μ� �����սô�.
*/

#include <iostream>
#include "Rational.h"

int main()
{
	Rational<int> oneEighth(1, 8);
	Rational<int> oneHalf(1, 2);

	Rational<int> result = oneHalf * oneEighth;
	result = oneHalf * 2; // �Ͻ��� ������ ȣ��(int(2)�� Rational��)
	result.showVal();
	result = 2 * oneHalf; 
	result.showVal();
}