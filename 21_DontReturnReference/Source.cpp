/*
항목21) 함수에서 객체를 반환해야 할 경우에 참조자를 반환하려고 들지 말자.
1. 지역 스택 객체에 대한 포인터나 참조자를 반환하는 일, 혹은 힙에 할당된 객체에 대한 참조자를 반환하는 일, 또는 지역 정적 객체에 대한 포인터나 참조자를 반환하는 일은
그런 객체가 두 개 이상 필요해질 가능성이 있다면 절대로 하지 마세요.(항목 4를 보시면 지역 정적 객체에 대한 참조자를 반환하도록 설계된 올바른 코드 예제를 찾을 수 있습니다.
최소한 단일 스레드 환경에서는 통합니다.
*/

#include <iostream>

class Rational {
public:
	Rational(int numerator = 0, int dominator = 1) : n(numerator), d(dominator){}
	friend void showRational(const Rational& rat);
private:
	int n, d;

	friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};

/*
참조자는 '존재하는' 객체에 붙는 다른 이름
=> 함수 내에 새로운 객체를 생성하지 않으면 참조자 반환 불가능
=> 방법은 3개, 새로운 객체를 스택에 만들거나, 힙에 만들거나, 정적 객체로 함수 안에 정의하거나
1) 스택
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
	Rational result(lhs.n*rhs.n, lhs.d*rhs.d);
	return result;
}
=> 함수가 끝나면 객체가 소멸되므로 사용불가

2) 힙
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
Rational *result = new Rational(lhs.n*rhs.n, lhs.d*rhs.d);
return result;
}
=> delete는 누가 해줄까? (메모리 누출 문제) 

3) 정적 객체
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
static Rational result;
result = ....
return result;
}
=> static 객체은 하나밖에 존재하지 않으므로 새로운 연산이 이전의 연산 결과를 덮어씌운다. 
*/

/* 올바른 방법 */
inline const Rational operator* (const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}


int main()
{
	Rational a(1, 3);
	Rational b(2, 5);
	showRational(a*b);
}


void showRational(const Rational& rat)
{
	std::cout << rat.n << "/" << rat.d << std::endl;
}