/*
항목11) operator=에서는 자기대입에 대한 처리가 빠지지 않도록 하자
1. operator=을 구현할 때, 어떤 객체가 그 자신에 대입되는 경우를 제대로 처리하도록 만듭시다. 원본 객체와 복사대상 객체의 주소를 비교해도 되고,
문장의 순서를 적절히 조정할 수도 있으며, 복사 후 맞바꾸기 기법을 써도 됩니다.
2. 두 개 이상의 객체에 대해 동작하는 함수가 있다면, 이 함수에 넘겨지는 객체들이 사실 같은 객체인 경우에 정확하게 동작하는지 확인해 보세요.
*/

#include <iostream>

class Widget{
public:
	Widget(int* in)
		:pb(in){}
	Widget & operator= (const Widget& rhs);
	void showVal();
	void swap(Widget &rhs);
private:
	int *pb;
};


Widget& Widget::operator=(const Widget& rhs)
{
	/*
	1. 원본을 복사하고, 복사해 놓은 사본을 포인터가 가리키게 만든 후, 원본을 삭제
	*/
	
	int *pOrig = pb;
	pb = new int(*rhs.pb);
	delete pOrig;
	return *this;
	
	/*
	2. 복사 후 맞바꾸기
	*/
	/*
	Widget temp(rhs);
	swap(temp);
	return *this;
	*/
}

void Widget::showVal()
{
	std::cout << *pb << std::endl;
}

void Widget::swap(Widget &rhs)
{
	int *temp = this->pb;
	this->pb = rhs.pb;
	rhs.pb = temp;
}

int main()
{
	int *val1 = new int(3);
	int *val2 = new int(4);
	Widget w1(val1);
	Widget w2(val2);
	w1 = w1; // 자가대입에도 동작하는지 확인
	w1 = w2;
	w1.showVal();
}