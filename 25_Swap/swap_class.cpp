/*
�׸�25) ���ܸ� ������ �ʴ� swap�� ���� ������ ������ ����
1. std::swap�� �������� Ÿ�Կ� ���� ������ ������ ������ �ִٸ� swap ��� �Լ��� �����սô�. �� ��� swap�� ���ܸ� ������ �ʵ��� ����ô�.
2. ��� swap�� ����������, �� ����� ȣ���ϴ� ���� swap�� �����մϴ�. Ŭ����(���ø��� �ƴ�)�� ���ؼ���, std::swap�� Ư��ȭ�� �ӽô�.
3. ����� ���忡�� swap�� ȣ���� ����, std::swap�� ���� using ������ �־� �� �Ŀ� ���ӽ����̽� �������� swap�� ȣ���սô�.
4. ����� ���� Ÿ�Կ� ���� std ���ø��� ���� Ư��ȭ�ϴ� ���� �����մϴ�. �׷��� std�� � ���̶� ���� '�߰�'�Ϸ��� ������ ���ʽÿ�.
*/

#include <iostream>
#include <vector>

class WidgetImpl { // Widget�� ���� �����͸� ��Ÿ���� Ŭ����, ���λ����� ���� �߿����� �ʽ��ϴ�.
public:
	WidgetImpl(int aa, int bb): a(aa), b(bb) {}
	void showWidgetImpl()
	{
		std::cout << a << "," << b << std::endl;
	}
private:
	int a, b;
};

class Widget { //pimpl ���뱸�� ����� Ŭ����
public:
	Widget(const Widget& rhs);
	Widget(WidgetImpl *pIm) : pImpl(pIm){}
	Widget& operator=(const Widget& rhs)
	{
		*pImpl = *(rhs.pImpl); // Widget�� �����ϱ� ����, �ڽ��� WidgetImpl ��ü�� �����մϴ�.
	}

	void swap(Widget& other)
	{
		using std::swap; // std::swap�� �� �� �ֵ��� �����ϰ� ����(�켱������ ���� �� �� ���� ����)
		swap(pImpl, other.pImpl); //Widget�� �¹ٲٱ� ����, �� Widget�� pImpl �����͸� �¹ٲߴϴ�. (��� ��� ����)
	}

	void showWidget()
	{
		pImpl->showWidgetImpl();
	}

private: 
	WidgetImpl *pImpl; // Widget�� ���� �����͸� ���� ��ü�� ���� ������
};


namespace std { // std::swap�� Widget�� ���� Ư��ȭ
	template<> // ���� ���ø� Ư��ȭ(�Ű������� ������ ��ü���� Ÿ������ ���ǵ� ���)
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b); // swap ��� �Լ��� ȣ���մϴ�.
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