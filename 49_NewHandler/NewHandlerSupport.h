#pragma once
#include <new>
#include "NewHandlerHolder.h"
/* �ٸ� �Ļ�Ŭ�������� �� ������ Ư�� ��ɸ��� �����޾� �� �� �ֵ��� ����� "�ͽ��� Ŭ����" */
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

//Ŭ�������� ��������� currentHandler ����� �η� �ʱ�ȭ�մϴ�.
template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = 0;