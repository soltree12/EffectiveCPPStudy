#pragma once

/* 0����Ʈ�� �䱸�Ǿ��� ��, 1����Ʈ �䱸�� ������ �����ϰ� ó���ϱ� */
/*
#include <new>

void* operator new(std::size_t size) throw(std::bad_alloc)
{
	using namespace std;

	if (size == 0) { size = 1; } // 0����Ʈ ��û�� ������, �̰��� 1����Ʈ �䱸�� �����ϰ� ó���մϴ�.

	while (true)
	{
		size ����Ʈ �Ҵ��ϱ�
		if (�Ҵ��� ��������)
			return (�Ҵ�� �޸𸮿� ���� ������);
		//�Ҵ��� �������� ���, ������ new ó���� �Լ��� ��� ������ �����Ǿ� �ִ��� ã�Ƴ��ϴ�.
		new_handler globalHandler = set_new_handler(0);
		set_new_handler(globalHandler);

		if(globalHandler) (*globalHandler)();
		else throw std::bad_alloc();

	}
}

*/