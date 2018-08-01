/* 
�׸� 20) '���� ���� ����'���ٴ� '�����ü �����ڿ� ���� ����' ����� ���ϴ� ���� �밳 ����. 
1. '���� ���� ����'���ٴ� '��� ��ü �����ڿ� ���� ����'�� ��ȣ�սô�. ��ü������ ȿ������ �Ӹ� �ƴ϶� ����ս� �������� �����ݴϴ�.
2. �̹� �׸񿡼� �ٷ� ��Ģ�� �⺻���� Ÿ�� �� STL �ݺ���. �׸��Ӱ� �Լ� ��ü Ÿ�Կ��� ���� �ʽ��ϴ�. �̵鿡 ���ؼ��� '���� ���� ����'�� �� �����մϴ�.
*/

#include <iostream>
#include <string>

class Window {
public:
	std::string name() const; // �������� �̸��� ��ȯ�մϴ�.
	virtual void display() const; // ������ �׵θ� �� ���θ� �׸��ϴ�.
};


std::string Window::name() const
{
	return "MyWindow";
}

void Window::display() const
{
	std::cout << "�θ� Ŭ���� display() ȣ��" << std::endl;
}


class WindowWithScrollBars : public Window { // Window�� �ڽ� Ŭ����
public:
	virtual void display() const;
};

void WindowWithScrollBars::display() const
{
	std::cout << "�ڽ� Ŭ���� display() ȣ��" << std::endl;
}

// void printNameAndDisplay(Window w) // ����! �Ű������� ���� �սǿ� ���ϰ� ���ϴ�. (�ڽ� Ŭ������ �μ� ������ �ϵ� ��� �����ϴ�.)
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