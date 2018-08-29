#pragma once
#include <new>
/* 
�Ļ� Ŭ���� ��ü�� ���� �޸𸮸� �Ҵ��ϴµ� �⺻ Ŭ������ operatorn new(Base ��ü�� �޸𸮸� �Ҵ�) �Լ��� ȣ��Ǵ� ���
-> "Ʋ��" �޸� ũ�Ⱑ ���������� ���ۺκп��� �˻��Ѵ�. 
*/
class Base
{
public:
	static void* operator new(std::size_t size) throw(std::bad_alloc) 
	{
		if (size != sizeof(Base))
			return ::operator new(size); // Ʋ�� ũ�Ⱑ ������, ǥ�� operator new �ʿ��� �޸� �Ҵ� �䱸�� ó���ϵ��� �ѱ�ϴ�.
	}
	
	static void operator delete(void *rawMemory, std::size_t size) throw()
	{
		if (rawMemory == 0) return; // �� �����Ͱ� delete�Ƿ��� �� ��쿡�� �ƹ��͵� ���� �ʰ� �մϴ�.

		if (size != sizeof(Base)) { // ũ�Ⱑ Ʋ�� ���, ǥ�� operator delete�� �޸� ���� ��û�� �õ��� �մϴ�.
			::operator delete(rawMemory);
			return;
		}

		//rawMemory�� ����Ű�� �޸𸮸� �����մϴ�.

		return;
	}
};

/*
(Ʋ�� �޸� ũ�⸦ �˻����� �ʾ��� �� ����Ǵ� ����)
class Derived:public Base // Derived������ operator new�� ������� �ʾҽ��ϴ�.
{};

Derived *p = new Derived; // Base::operator new�� ȣ��ǳ�!
*/
