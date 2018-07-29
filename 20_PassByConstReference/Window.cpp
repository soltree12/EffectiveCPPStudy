/* 
항목 20) '값에 의한 전달'보다는 '상수객체 참조자에 의한 전달' 방식을 택하는 편이 대개 낫다. 
1. '값에 의한 전달'보다는 '상수 객체 참조자에 의한 전달'을 선호합시다. 대체적으로 효율적일 뿐만 아니라 복사손실 문제까지 막하줍니다.
2. 이번 항목에서 다룬 법칙은 기본제공 타입 및 STL 반복자. 그리ㅣ고 함수 객체 타입에는 맞지 않습니다. 이들에 대해서는 '값에 대한 전달'이 더 적절합니다.
*/

#include <iostream>
#include <string>

class Window {
public:
	std::string name() const; // 윈도우의 이름을 반환합니다.
	virtual void display() const; // 윈도우 테두리 및 내부를 그립니다.
};


std::string Window::name() const
{
	return "MyWindow";
}

void Window::display() const
{
	std::cout << "부모 클래스 display() 호출" << std::endl;
}


class WindowWithScrollBars : public Window { // Window의 자식 클래스
public:
	virtual void display() const;
};

void WindowWithScrollBars::display() const
{
	std::cout << "자식 클래스 display() 호출" << std::endl;
}

// void printNameAndDisplay(Window w) // 저런! 매개변수가 복사 손실에 당하고 맙니다. (자식 클래스의 부속 정보가 싹둑 썰려 나갑니다.)
void printNameAndDisplay(const Window& w)
{
	std::cout << w.name()<<std::endl;
	w.display();
}

int main()
{
	WindowWithScrollBars wwsb;
	printNameAndDisplay(wwsb);
}