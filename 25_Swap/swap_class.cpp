/*
항목25) 예외를 던지지 않는 swap에 대한 지원도 생각해 보자
1. std::swap이 여러분의 타입에 대해 느리게 동작할 여지가 있다면 swap 멤버 함수를 제공합시다. 이 멤버 swap은 예외를 던지지 않도록 만듭시다.
2. 멤버 swap을 제공했으면, 이 멤버를 호출하는 비멤버 swap도 제공합니다. 클래스(템플릿이 아닌)에 대해서는, std::swap도 특수화해 둡시다.
3. 사용자 입장에서 swap을 호출할 때는, std::swap에 대한 using 선언을 넣어 준 후에 네임스페이스 한정없이 swap을 호출합시다.
4. 사용자 정의 타입에 대한 std 템플릿을 완전 특수화하는 것은 가능합니다. 그러나 std에 어떤 것이라도 새로 '추가'하려고 들지는 마십시오.
*/

#include <iostream>
#include <vector>

class WidgetImpl { // Widget의 실제 데이터를 나타내는 클래스, 세부사항은 별로 중요하지 않습니다.
public:
	WidgetImpl(int aa, int bb): a(aa), b(bb) {}
	void showWidgetImpl()
	{
		std::cout << a << "," << b << std::endl;
	}
private:
	int a, b;
};

class Widget { //pimpl 관용구를 사용한 클래스
public:
	Widget(const Widget& rhs);
	Widget(WidgetImpl *pIm) : pImpl(pIm){}
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
	WidgetImpl *pImpl; // Widget의 실제 데이터를 가진 객체에 대한 포인터
};


namespace std { // std::swap을 Widget에 대해 특수화
	template<> // 완전 템플릿 특수화(매개변수가 완전히 구체적인 타입으로 정의된 경우)
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b); // swap 멤버 함수를 호출합니다.
	}
}

int main()
{
	WidgetImpl wid1(1, 2);
	WidgetImpl wid2(3, 4);
	Widget w1(&wid1);
	Widget w2(&wid2);

	using std::swap;

	swap(w1, w2);
	w1.showWidget();
}