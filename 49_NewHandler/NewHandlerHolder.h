#pragma once
#include <new>
class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh):handler(nh){} // ������ new ó���ڸ� ȹ���մϴ�.
	~NewHandlerHolder()
	{
		std::set_new_handler(handler); // �̰��� �����մϴ�.
	}

private:
	std::new_handler handler; // �̰��� ����� �Ӵϴ�.
	
	NewHandlerHolder(const NewHandlerHolder&); // ���縦 ���� ���� �κ�
	NewHandlerHolder& operator= (const NewHandlerHolder&); // ���縦 ���� ���� �κ�
};