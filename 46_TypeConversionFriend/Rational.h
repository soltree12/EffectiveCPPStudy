#pragma once
/*
항목24) 타입 변환이 모든 매개변수에 대해 적용되어야 한다면 비멤버 함수를 선언하자.
1. 어떤 함수에 들어가는 모든 매개변수(this 포인터가 가리키는 객체도 포함해서)에 대해 타입 변환을 해 줄 필요가 있다면, 그 함수는 비멤버이어야 합니다.
*/

template<typename T> 
class Rational;

/* 계산을 맡을 도우미 함수 템플릿을 선언합니다. */
template<typename T>
const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs); // 도우미 함수 템플릿을 선언합니다.

template<typename T>
class Rational {
public:
	Rational(const T& numerator = 0, const T& denominator = 1) : num(numerator), den(denominator) {}

	const T numerator() const { return num; }
	const T denominator() const { return den; }


	/* 
	클래스 템플릿은 템플릿 인자 추론 과정에 좌우되지 않으므로(템플릿 인자 추론은 함수 템플릿에만 적용되는 과정입니다.) 
	T의 정확한 정보는 Rational<T> 클래스가 인스턴스화될	당시에 바로 알 수 있습니다.(int->Rational로 암시적 변환 가능) => Friend함수로 operator* 함수를 선언합니다.
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
