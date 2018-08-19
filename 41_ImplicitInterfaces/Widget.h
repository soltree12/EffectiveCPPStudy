#pragma once
#include <iostream>
class Widget {
public:
	Widget(std::size_t newSize):_size(newSize){}
	virtual ~Widget(){}
	virtual std::size_t size() const
	{
		return _size;
	}
	virtual void normalize(){}
	void swap(Widget& other) {
		std::swap(other._size, _size);
	}

private:
	std::size_t _size;
};


/*
객체지향 프로그래밍의 세계 :
명시적 인터페이스 - w는 Widget 인터페이스를 지원해야함, 이 인터페이스를 소스코드(.h파일 등)에서 찾으면 어떤 형태인지를 확인할 수 있음(명시적)
런타임 다형성 - 가상 함수 여러개 있음, 호출은 런타임 에 결정됨.
*/
void doProcessing(Widget& w)
{
	if (w.size() > 1) {
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
		std::cout << "temp::_size : " << temp.size()<<std::endl;
	}
};


/* 
템플릿과 일반화 프로그래밍의 세계 :
암시적 인터페이스 - 유효 표현식의 집합(size,normalize,swap 멤버 함수를 지원(T 타입의 객체에 대해 '유효'해야함), 복사생성자 지원, 부등 비교를 위한 연산도 지원)
컴파일 타임 다형성 - w가 수반되는 함수 호출이 일어날때(> 등) 호출을 성공시키기 위해 템플릿의 인스턴스화가 일어난다.(컴파일타임에)
*/
template<typename T>
void doProcessingTemplate(T& w)
{
	if (w.size() > 1)
	{
		T temp(w);
		temp.normalize();
		temp.swap(w);
		std::cout << "temp::_size : " << temp.size() << std::endl;
	}
}