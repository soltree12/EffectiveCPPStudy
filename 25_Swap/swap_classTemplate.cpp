#include<iostream>

namespace WidgetStuff { // std�� �ƴ� ���ο� ���ӽ����̽�

	template<typename T>
	class WidgetImpl { // Widget�� ���� �����͸� ��Ÿ���� Ŭ����, ���λ����� ���� �߿����� �ʽ��ϴ�.
	public:
		WidgetImpl(T aa, T bb) : a(aa), b(bb) {}
		void showWidgetImpl()
		{
			std::cout << a << "," << b << std::endl;
		}
	private:
		T a, b;
	};


	template<typename T>
	class Widget { //pimpl ���뱸�� ����� Ŭ����
	public:
		Widget(const Widget& rhs);
		Widget(WidgetImpl *pIm) : pImpl(pIm) {}
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
		WidgetImpl * pImpl; // Widget�� ���� �����͸� ���� ��ü�� ���� ������
	};

	template<typename T> // ���� swap �Լ�
	void swap(Widget<T>& a, Widget<T>& b) // �̹��� std ���ӽ����̽��� �Ϻΰ� �ƴմϴ�.
	{
		a.swap(b);
	}
}


	/* ���� ���忡�� swap ��� */
	template<typename T>
	void doSomething(T& obj1, T& obj2)
	{
		using std::swap;

		/*
		std::swap�� T ���� ������ �Ϲ��� ���ø����� �켱������ ����,
		T�� WidgetStuff���ӽ����̽� ���� Widget�̶��, �����Ϸ��� ���� ���� ��Ģ�� �����Ͽ� WidgetStuff�� swap�� ã�Ƴ���.
		*/

		swap(obj1, obj2); // T Ÿ�� ������ swap�� ȣ���մϴ�. 
		// std::swap(obj1, obj2) // �̿� ���� ���� �� ��, std�� swap�̿ܿ��� �ŵ鶰������ ����.
	}

/*
1) ���ø� ���� Ư��ȭ : 
template<>
void swap<Widget>(Widget& a, Widget& b)
2) ���ø� �κ� Ư��ȭ : ex) �� ���ø� �Ķ���Ͱ� ���� ���������� ����
template <typename T>
class MyClass<T, T>
{
//...
};
MyClass<int> c; // �� ���� ���
3) �Լ� ���ø� �����ε�
template<typename T>
void swap(Widget<T>& a, Widget<T>&b)

1.�Լ� ���ø� - �κ� Ư��ȭ �Ұ���, ���� Ư��ȭ ����
Ŭ���� ���ø� - �κ� Ư��ȭ ����, ���� Ư��ȭ ����
2. std ���ӽ����̽��� ���ο� ���ø��� �߰��ϴ� ���� ������� ����(�����ε� �Ұ�)

(swap �����)
1. �������� Ÿ������ ������� �� ��ü�� ���� ������ ���� �¹ٲٴ� �Լ��� swap�̶�� �̸����� �����, �̰��� public ��� �Լ��� �νʽÿ�.
��, �� �ִٰ� ������ �����帮������, �� �Լ��� ����� ���ܸ� ������ �ȵ˴ϴ�.
2. �������� Ŭ���� Ȥ�� ���ø��� ��� �ִ� ���ӽ����̽��� ���� ���ӽ����̽��� ���� swap�� ����� �ֽ��ϴ�. �׸��� 1������ ���� swap
��� �Լ��� �� ���� �Լ��� ȣ���ϵ��� ����ϴ�.
3. ���ο� Ŭ����(Ŭ���� ���ø��� �ƴ϶�)�� ����� �ִٸ�, �� Ŭ������ ���� std::swap�� Ư��ȭ ������ �غ��� �Ӵϴ�. �׸��� �� Ư��ȭ
���������� swap ��� �Լ��� ȣ���ϵ��� ����ϴ�.
4. ����� ���忡�� swap�� ȣ���� ��, swap�� ȣ���ϴ� �Լ��� std::swap�� �� �� �ֵ��� using ������ �ݵ�� ���Խ�ŵ�ϴ�. �� ������ swap�� ȣ���ϵ�,
���ӽ����̽� �����ڸ� ������ �ʵ��� �Ͻʽÿ�.
5. ��� ������ swap�� ����� ���ܸ� ������ �ʾƾ� �մϴ�.
*/