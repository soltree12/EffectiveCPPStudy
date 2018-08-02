/*
�׸�24) Ÿ�� ��ȯ�� ��� �Ű������� ���� ����Ǿ�� �Ѵٸ� ���� �Լ��� ��������.
1. � �Լ��� ���� ��� �Ű�����(this �����Ͱ� ����Ű�� ��ü�� �����ؼ�)�� ���� Ÿ�� ��ȯ�� �� �� �ʿ䰡 �ִٸ�, �� �Լ��� �����̾�� �մϴ�.
*/

#include <iostream>

class Rational {
public:
	Rational(int numerator = 0, int denominator = 1) : num(numerator), den(denominator){}

	int numerator() const { return num; }
	int denominator() const { return den; }
	
	/* 
	��� �Լ� ����
	const Rational operator* (const Rational& rhs) const
	{
		return Rational(numerator()*rhs.numerator(), denominator()*rhs.denominator());
	}
	*/
	void showVal()
	{
		std::cout << num << "/" << den << std::endl;
	}

private:
	int num;
	int den;
};

/* friend �Լ��� �ƴϾ �ش� ��ü�� ����� ������ ���� (��� �Ű������� ���� Ÿ�� ��ȯ�� ����� �ϴ� ��� 
��ó�� ���� �Լ��� ������ ����� ���� ����) */
const Rational operator* (const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator()*rhs.numerator(), lhs.denominator()*rhs.denominator());
}

int main()
{
	Rational oneEighth(1, 8);
	Rational oneHalf(1, 2);

	Rational result = oneHalf * oneEighth;
	result = oneHalf * 2; // �Ͻ��� ������ ȣ��(int(2)�� Rational��)
	result.showVal();
	result = 2 * oneHalf; // ���� �Լ��� ���� ������ ����
	result.showVal();
}