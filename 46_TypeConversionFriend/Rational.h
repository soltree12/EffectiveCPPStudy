#pragma once

template<typename T> 
class Rational;

/* ����� ���� ����� �Լ� ���ø��� �����մϴ�. */
template<typename T>
const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs); // ����� �Լ� ���ø��� �����մϴ�.

template<typename T>
class Rational {
public:
	Rational(const T& numerator = 0, const T& denominator = 1) : num(numerator), den(denominator) {}

	const T numerator() const { return num; }
	const T denominator() const { return den; }


	/* 
	Ŭ���� ���ø��� ���ø� ���� �߷� ������ �¿���� �����Ƿ�(���ø� ���� �߷��� �Լ� ���ø����� ����Ǵ� �����Դϴ�.) 
	T�� ��Ȯ�� ������ Rational<T> Ŭ������ �ν��Ͻ�ȭ��	��ÿ� �ٷ� �� �� �ֽ��ϴ�.(int->Rational�� �Ͻ��� ��ȯ ����) => Friend�Լ��� operator* �Լ��� �����մϴ�.
	=> �Լ� ���ø����μ��� ������ ���� �ʰ� Ư���� �Լ� �ϳ��� ��Ÿ�� �� �ִ�.
	*/
	friend const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs)
	{
		return doMultiply(lhs, rhs);
	}

	void showVal()
	{
		std::cout << num << "/" << den << std::endl;
	}

private:
	int num;
	int den;
};

template<typename T>
const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs)
{
	return Rational<T>(lhs.numerator()*rhs.numerator(), lhs.denominator()*rhs.denominator());
}
