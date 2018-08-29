#pragma once
#include <new>
#include "NewHandlerHolder.h"
/* 다른 파생클래스들이 한 가지의 특정 기능만을 물려받아 갈 수 있도록 설계된 "믹스인 클래스" */
template<typename T>
class NewHandlerSupport {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void * operator new(std::size_t size) throw(std::bad_alloc);

private:
	static std::new_handler currentHandler;
};

template<typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;

}

template <typename T>
void * NewHandlerSupport<T>::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler)); 
	return ::operator new(size); 
} 

//클래스별로 만들어지는 currentHandler 멤버를 널로 초기화합니다.
template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = 0;