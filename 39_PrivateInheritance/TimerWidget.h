#pragma once
#include <iostream>

class Timer {
public:
	explicit Timer(int tickFrequency);

	virtual void onTick() const;
};

/* �ܺο��� onTick()�Լ��� ����ϰ� �ϰ� ���� ���� */
/* 
1. private ��� 
���� :
 - ���� �⺻ Ŭ���� ����ȭ(empty bas optimization : EBO)�� �����ϴ�.
 class Empty{};
 class HoldsAnInt: private Empty{
 private:
	int x;
};
�� �� HoldsAnInt�� int�� ũ�Ⱑ ����(���� ���� Ŭ������ ����� �����ϸ� �߰� �޸� �ʿ�).
 - �⺻ Ŭ������ protected ����� �����ؾ� �ϰų� ���� �Լ��� �������ؾ� �� �� �����ϴ�.
 */
class Widget1 : private Timer {
private:
	virtual void onTick() const; // public���� ����ϸ� �ܺο��� onTick�Լ��� ����� ����� ����(���ο����� ����ϴ� �Լ�
};


/* 
2. ��ü �ռ� : Timer�κ��� public ����� ���� Ŭ������ Widget �ȿ� private ��ø Ŭ������ ������ ����, 
�� Ŭ�������� onTick�� �������� ����, �� Ÿ���� ��ü �ϳ��� Widget �ȿ� ������ ����ν� �ִ´�.
���� :
- �Ļ� Ŭ�������� onTick�� �������� �� ������ ���� �������� ���� �� �ִ�.
- ������ �������� �ּ�ȭ�� �� �ִ�.
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
