#pragma once
#include <new>
/* 
파생 클래스 객체를 담을 메모리를 할당하는데 기본 클래스의 operatorn new(Base 객체의 메모리만 할당) 함수가 호출되는 경우
-> "틀린" 메모리 크기가 들어왔을때를 시작부분에서 검사한다. 
*/
class Base
{
public:
	static void* operator new(std::size_t size) throw(std::bad_alloc) 
	{
		if (size != sizeof(Base))
			return ::operator new(size); // 틀린 크기가 들어오면, 표준 operator new 쪽에서 메모리 할당 요구를 처리하도록 넘깁니다.
	}
	
	static void operator delete(void *rawMemory, std::size_t size) throw()
	{
		if (rawMemory == 0) return; // 널 포인터가 delete되려고 할 경우에는 아무것도 하지 않게 합니다.

		if (size != sizeof(Base)) { // 크기가 틀린 경우, 표준 operator delete가 메모리 삭제 요청을 맡도록 합니다.
			::operator delete(rawMemory);
			return;
		}

		//rawMemory가 가리키는 메모리를 해제합니다.

		return;
	}
};

/*
(틀린 메모리 크기를 검사하지 않았을 때 예상되는 문졔)
class Derived:public Base // Derived에서는 operator new가 선언되지 않았습니다.
{};

Derived *p = new Derived; // Base::operator new가 호출되네!
*/
