#include<iostream>

namespace WidgetStuff { // std가 아닌 새로운 네임스페이스

	template<typename T>
	class WidgetImpl { // Widget의 실제 데이터를 나타내는 클래스, 세부사항은 별로 중요하지 않습니다.
	public:
		WidgetImpl(T aa, T bb) : a(aa), b(bb) {}
		void showWidgetImpl()
		{
			std::cout << a << "," << b << std::endl;
		}
	private:
		T a, b;
	};


	template<typename T>
	class Widget { //pimpl 관용구를 사용한 클래스
	public:
		Widget(const Widget& rhs);
		Widget(WidgetImpl *pIm) : pImpl(pIm) {}
		Widget& operator=(const Widget& rhs)
		{
			*pImpl = *(rhs.pImpl); // Widget을 복사하기 위해, 자신의 WidgetImpl 객체를 복사합니다.
		}

		void swap(Widget& other)
		{
			using std::swap; // std::swap을 쓸 수 있도록 결정하게 해줌(우선순위에 따라 안 쓸 수도 있음)
			swap(pImpl, other.pImpl); //Widget을 맞바꾸기 위해, 각 Widget의 pImpl 포인터를 맞바꿉니다. (계산 비용 절약)
		}

		void showWidget()
		{
			pImpl->showWidgetImpl();
		}

	private:
		WidgetImpl * pImpl; // Widget의 실제 데이터를 가진 객체에 대한 포인터
	};

	template<typename T> // 비멤버 swap 함수
	void swap(Widget<T>& a, Widget<T>& b) // 이번엔 std 네임스페이스의 일부가 아닙니다.
	{
		a.swap(b);
	}
}


	/* 고객의 입장에서 swap 사용 */
	template<typename T>
	void doSomething(T& obj1, T& obj2)
	{
		using std::swap;

		/*
		std::swap의 T 전용 버전을 일반형 템플릿보다 우선적으로 선택,
		T가 WidgetStuff네임스페이스 내의 Widget이라면, 컴파일러는 인자 의존 규칙을 적용하여 WidgetStuff의 swap을 찾아낸다.
		*/

		swap(obj1, obj2); // T 타입 전용의 swap을 호출합니다. 
		// std::swap(obj1, obj2) // 이와 같이 쓰지 말 것, std의 swap이외에는 거들떠보지도 않음.
	}

/*
1) 템플릿 완전 특수화 : 
template<>
void swap<Widget>(Widget& a, Widget& b)
2) 템플릿 부분 특수화 : ex) 두 템플릿 파라미터가 같은 데이터형을 가짐
template <typename T>
class MyClass<T, T>
{
//...
};
MyClass<int> c; // 와 같이 사용
3) 함수 템플릿 오버로딩
template<typename T>
void swap(Widget<T>& a, Widget<T>&b)

1.함수 템플릿 - 부분 특수화 불가능, 완전 특수화 가능
클래스 템플릿 - 부분 특수화 가능, 완전 특수화 가능
2. std 네임스페이스는 새로운 템플릿을 추가하는 것을 허용하지 않음(오버로딩 불가)

(swap 만들기)
1. 여러분의 타입으로 만들어진 두 객체의 값을 빛나게 빨리 맞바꾸는 함수를 swap이라는 이름으로 만들고, 이것을 public 멤버 함수로 두십시오.
단, 좀 있다가 이유를 말씀드리겠지만, 이 함수는 절대로 예외를 던져선 안됩니다.
2. 여러분의 클래스 혹은 템플릿이 들어 있는 네임스페이스와 같은 네임스페이스에 비멤버 swap을 만들어 넣습니다. 그리고 1번에서 만든 swap
멤버 함수를 이 비멤버 함수가 호출하도록 만듭니다.
3. 새로운 클래스(클래스 템플릿이 아니라)를 만들고 있다면, 그 클래스에 대한 std::swap의 특수화 버전을 준비해 둡니다. 그리고 이 특수화
버전에서도 swap 멤버 함수를 호출하도록 만듭니다.
4. 사용자 입장에서 swap을 호출할 때, swap을 호출하는 함수가 std::swap을 볼 수 있도록 using 선언을 반드시 포함시킵니다. 그 다음에 swap을 호출하되,
네임스페이스 한정자를 붙이지 않도록 하십시오.
5. 멤버 버전의 swap은 절대로 예외를 던지지 않아야 합니다.
*/