#pragma once
#include <iostream>

class Timer {
public:
	explicit Timer(int tickFrequency);

	virtual void onTick() const;
};

/* 외부에서 onTick()함수를 사용하게 하고 싶지 않음 */
/* 
1. private 상속 
장점 :
 - 공백 기본 클래스 최적화(empty bas optimization : EBO)가 가능하다.
 class Empty{};
 class HoldsAnInt: private Empty{
 private:
	int x;
};
일 때 HoldsAnInt와 int의 크기가 같다(만약 공백 클래스를 멤버로 선언하면 추가 메모리 필요).
 - 기본 클래스의 protected 멤버에 접근해야 하거나 가상 함수를 재정의해야 할 때 유용하다.
 */
class Widget1 : private Timer {
private:
	virtual void onTick() const; // public으로 상속하면 외부에서 onTick함수를 사용할 우려가 있음(내부에서만 사용하는 함수
};


/* 
2. 객체 합성 : Timer로부터 public 상속을 받은 클래스를 Widget 안에 private 중첩 클래스로 선언해 놓고, 
이 클래스에서 onTick을 재정의한 다음, 이 타입의 객체 하나를 Widget 안에 데이터 멤버로써 넣는다.
장점 :
- 파생 클래스에서 onTick을 재정의할 수 없도록 설계 차원에서 막을 수 있다.
- 컴파일 의존성을 최소화할 수 있다.
*/
class Widget2 {
private:
	class WidgetTimer : public Timer {
	public:
		virtual void onTick() const;
	};

	void WidgetTimer::onTick()
	{
		std::cout << "WidgetTimer::onTick" << endl;
	}

	WidgetTimer timer;
};

void Timer::onTick() const 
{
	std::cout << "Timer::onTick" << endl;
}
