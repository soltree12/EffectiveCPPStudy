#include <iostream>
/* 
(Non-Executable 
항목 42) typename의 두 가지 의미를 제대로 파악하자
1. 템플릿 매개변수를 선언할 때, class 및 typename은 서로 바꾸어 써도 무방합니다.
2. 중첩 의존 이름을 식별하는 용도에는 반드시 typename을 사용합니다. 단, 중첩 의존 이름이 기본 클래스 리스트에 있거나 멤버 초기화 리스트 내의 기본 클래스 식별자로 있는 경우에는 예외입니다.
*/

/* 1. typename의 쓰임새 : 중첩 의존 이름이 type임을 알린다. */
/* 템플릿 매개변수를 선언하는 경우의 class 및 typename은 완전히 같은 의미를 지닌다. */
template <typename C>
void print2nd(const C& container) // 컨테이너에 들어있는 두 번째 원소를 출력합니다. 도저히 제 정신으로 짠 코드가 아닙니다!
{
	if (container.size() >= 2)
	{
		typename C::const_iterator iter(container.begin()); // 첫째 원소에 대한 반복자를 얻습니다.
		++iter; // iter를 두 번째 원소로 옮깁니다.
		int value = *iter; // 이 원소를 다른 int로 복사합니다.
		std::cout << value; // 이 int를 출력합니다.
	}

	/* C::const_iterator처럼 템플릿매개변수(C)에 종속된 것을 가리켜 의존 이름이라고 한다.(클래스 안에 중첩되어 있으면 중첩 의존 이름) */
	//C::const_iterator * x; // 중첩 의존 이름은 기본적으로 타입이 아닌 것으로 해석 -> C::const_iterator라는 전역변수와 x의 곱으로 해석할 수 있음
	typename C::const_iterator *x //앞에 typename을 붙여줘 타입임을 알린다.
}

template<typename C> //typename 쓸 수 있음(class와 같은 의미)
void f(const C& container, // typename 쓰면 안됨
	typename C::iterator iter); // typename 꼭 써야 함

template <typename T>
class Derived:public Base<T>::Nested { // 상속되는 기본 클래스 리스트, typename 쓰면 안 됨
public:
	explicit Derived(int x) : Base<T>::Nested(x) // 멤버 초기화 리스트에 있는 기본 클래스 식별자: typename 쓰면 안 됨
	{
		typename Base<T>::Nested temp; // 중첩 의존 타입 이름이며 기본 클래스 리스트에도 없고 멤버 초기화 리스트의 기본 클래스 식별자도 아님 : typename 필요
	}
};

/* 2. typename에 관한 예제 */
template <typename IterT>
void workWithIterator(IterT iter)
{
	/* 중첩 의존 타입 이름이므로 typename을 앞에 붙인다. */
	typename std::iterator_traits<IterT>::value_type temp(*iter); // IterT 객체가 가리키는 것과 똑같은 타입의 지역변수를 선언한 후, iter가 가리키는 객체로 그 temp를 초기화하는 문장
	
	/* 아래처럼 재정의도 가능 */
	typedef typename std::iterator_traits<IterT>::value_type value_type;
	value_type temp(*iter);
}