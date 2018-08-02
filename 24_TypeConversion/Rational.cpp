/*
항목24) 타입 변환이 모든 매개변수에 대해 적용되어야 한다면 비멤버 함수를 선언하자.
1. 어떤 함수에 들어가는 모든 매개변수(this 포인터가 가리키는 객체도 포함해서)에 대해 타입 변환을 해 줄 필요가 있다면, 그 함수는 비멤버이어야 합니다.
*/

#include <iostream>

class Rational {
public:
	Rational(int numerator = 0, int denominator = 1) : num(numerator), den(denominator){}

	int numerator() const { return num; }
	int denominator() const { return den; }
	
	/* 
	멤버 함수 연산
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

/* friend 함수가 아니어도 해당 객체를 사용한 연산이 가능 (모든 매개변수에 대해 타입 변환을 해줘야 하는 경우 
이처럼 비멤버 함수로 연산을 만드는 것을 권장) */
const Rational operator* (const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator()*rhs.numerator(), lhs.denominator()*rhs.denominator());
}

int main()
{
	Rational oneEighth(1, 8);
	Rational oneHalf(1, 2);

	Rational result = oneHalf * oneEighth;
	result = oneHalf * 2; // 암시적 생성자 호출(int(2)를 Rational로)
	result.showVal();
	result = 2 * oneHalf; // 비멤버 함수일 때만 가능한 연산
	result.showVal();
}