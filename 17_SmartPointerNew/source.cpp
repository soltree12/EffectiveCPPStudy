/*
항목17) new로 생성한 객체를 스마트 포인터에 저장하는 코드는 별도의 한 문장으로 만들자
1. new로 생성한 객체를 스마트 포인터로 넣는 코드는 별도의 한 문장으로 만듭시다. 이것이 안 되어 있으면, 예외가 발생될 때 디버깅하기 힘든 자원 누출이 초래될 수 있습니다.
*/                                                                                                                                                                                                                                                                                                                                                                                            

#include <iostream>
#include <memory>

class Widget {

};

int priority()
{
	return 1;
}
void processWidget(std::shared_ptr<Widget> pw, int priority)
{

}

int main()
{
	// processWidget(new Widget, priority()); // shared_ptr의 생성자는 explicit로 선언되어 있기 때문에, 암시적인 변환이 불가능하다.
	
	/*
	C++은 컴파일러에 따라 매개변수의 연산이 실행되는 순서가 다르기 때문에,
	1. "new Widget"을 실행합니다.
	2. priority를 호출합니다.
	3. tr1::shared_ptr 생성자를 호출합니다.
	와 같은 순서에서 priority 호출 부분에서 예외가 발생되면 "new Widget"으로 만들어졌던 포인터가 유실될 수 있다.
	*/
	processWidget(std::shared_ptr<Widget>(new Widget), priority());

	/* 안전한 방법 */
	std::shared_ptr<Widget> pw(new Widget);
	processWidget(pw, priority());

}