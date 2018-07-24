/* 
�׸�10) ���� �����ڴ� *this�� �����ڸ� ��ȯ�ϰ� ����
���� �����ڴ� *this�� �����ڸ� ��ȯ�ϵ��� ���弼��. 
*/

#include <iostream>

class Widget {
public:
	Widget& operator=(const Widget& rhs)
	{
		this->val = rhs.val;
		return *this;
	}
	
	Widget& operator+=(const Widget& rhs)
	{
		this->val = rhs.val;
		return *this;
	}

	Widget(const int& input)
		:val(input){}

	Widget() : val(0){}

	void showVal()
	{
		std::cout << val << std::endl;
	}
private:
	int val;
};

int main()
{
	Widget w1(3);
	Widget w2;
	w2 = w1;
	w2.showVal();
	return 0;
}