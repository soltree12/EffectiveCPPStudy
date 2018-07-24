/*
�׸�11) operator=������ �ڱ���Կ� ���� ó���� ������ �ʵ��� ����
1. operator=�� ������ ��, � ��ü�� �� �ڽſ� ���ԵǴ� ��츦 ����� ó���ϵ��� ����ô�. ���� ��ü�� ������ ��ü�� �ּҸ� ���ص� �ǰ�,
������ ������ ������ ������ ���� ������, ���� �� �¹ٲٱ� ����� �ᵵ �˴ϴ�.
2. �� �� �̻��� ��ü�� ���� �����ϴ� �Լ��� �ִٸ�, �� �Լ��� �Ѱ����� ��ü���� ��� ���� ��ü�� ��쿡 ��Ȯ�ϰ� �����ϴ��� Ȯ���� ������.
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
	1. ������ �����ϰ�, ������ ���� �纻�� �����Ͱ� ����Ű�� ���� ��, ������ ����
	*/
	
	int *pOrig = pb;
	pb = new int(*rhs.pb);
	delete pOrig;
	return *this;
	
	/*
	2. ���� �� �¹ٲٱ�
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
	w1 = w1; // �ڰ����Կ��� �����ϴ��� Ȯ��
	w1 = w2;
	w1.showVal();
}