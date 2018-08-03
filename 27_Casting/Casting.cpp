/*
(Non-Excutable)
항목 27) 캐스팅은 절약, 또 절약! 잊지 말자
1. 다른 방법이 가능하다면 캐스팅은 피하십시오. 특히 수행 성능에 민감한 코드에서 dynamic_cast는 몇 번이고 다시 생각하십시오. 설계 중에
캐스팅이 필요해졌다면, 캐스팅을 쓰지 않는 다른 방법을 시도해 보십시오.
2. 캐스팅이 어쩔 수 없이 필요하다면, 함수 안에 숨길 수 있도록 해 보십시오. 이렇게 하면 최소한 사용자는 자신의 코드에 캐스팅을 넣지 않고
이 함수를 호출할 수 있게 됩니다.
3. 구형 스타일의 캐스트를 쓰려거든 C++ 스타일의 캐스트를 선호하십시오. 발견하기도 쉽고, 설계자가 어떤 역할을 의도했는지가 더 자세하게 드러납니다.
*/

#include <iostream>
#include <vector>
class Window {
public:
	virtual void onResize(){...} // 기본 클래스의 onResize 구현 결과
};

/*
Case 1) 가상 함수를 파생 클래스에서 재정의해서 구현할 때 기본 클래스의 버전을 호출하는 문장을 가장 먼저 넣는 경우
*/

/* 잘못된 방법 */
class SpecialWindow : public Window { // 파생 클래스
public:
	virtual void onResize() {
		//파생 클래스의 onResize 구현 결과 *this를 Window로 캐스팅하고 그것에 대해 onResize를 호출합니다. 동작이 안 되어서 문제죠.
		//(static_cast가 일어나면서 *this의 기본 클래스 부분에 대한 사본이 임시적으로 만들어지는데, 이 임시 객체에서 onResize함수를 호출(사본이 변경됨)
		static_cast<Window>(*this).onResize();
	}
};


/* 옳은 방법 : 현재 객체에 대고 onResize의 기본 클래스 버전을 호출하도록 만든다. */
class SpecialWindow : public Window {
public:
	virtual void onResize() {
		Window::onResize();
	}
};


/*
Case 2) 파생 클래스 객체임이 분명한 녀석이 있어서 이에 대해 파생 클래스의 함수를 호출하고 싶은데, 그 객체를 조작할 수 있는 수단으로 
기본 클래스의 포인터밖에 없는 경우
*/

class BlinkWindow : public Window { // 파생 객체에만 있는 blink 함수
public:
	void blink();
};

/* 바람직하지 않은 방법 : dynamic_cast 사용(정말 느림) */
void func()
{
	typedef std::vector<std::shared_ptr<Window> > VPW; // Window를 가리키는 스마트 포인터들의 벡터
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		if (BlinkWindow *psw = dynamic_cast<BlinkWindow*>(iter->get()))
			psw->blink();
	}
}

/* 
좋은 방법 1: 파생 클래스 객체에 대한 포인터를 컨테이너에 담기 
단점 - 파생 클래스가 여러개일 때는 적용 불가
*/
void func()
{
	typedef std::vector<std::shared_ptr<BlinkWindow> > VPW; // Window를 가리키는 스마트 포인터들의 벡터
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		(*iter)->blink();
	}
}

/* 
좋은 방법 2 : 기본 blink를 구현해서 가상 함수로 제공
*/
class Window {
public:
	virtual void blink() {} // 기본 구현은 '아무 동작 안하기'
};

class BlinkWindow : public Window {
public:
	virtual void blink() {...} // 이 클래스에서는 blink 함수가 특정한 동작을 수행합니다.
};

void func()
{
	typedef std::vector<std::shared_ptr<Window> > VPW;
	VPW winPtrs; // 이 컨테이너에서는 Window에서 파생된 모든 타입의 객체들을 담습니다.
	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		(*iter)->blink();
	}
}

/* 
정말 안 좋은 방법 : 폭포식 dynamic_cast (파생 클래스가 추가될때마다 조건문을 추가해야함)
*/

void func()
{
	typedef std::vector<std::shared_ptr<Window> > VPW;
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		if (BlinkWindow1 *psw = dynamic_cast<BlinkWindow1*>(iter->get())){ ... }
		else if (BlinkWindow2 *psw = dynamic_cast<BlinkWindow2*>(iter->get())) { ... }
		else if (BlinkWindow3 *psw = dynamic_cast<BlinkWindow3*>(iter->get())) { ... }
	}
}