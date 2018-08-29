#include "Widget.h"
#include "NewHandlerHolder.h"
std::new_handler Widget::currentHandler = 0; // 널로 초기화합니다.

/* 자신에게 넘어온 포인터를 아무런 점검 없이 저장해 놓고, 바로 전에 저장했던 포인터를 역시 아무런 점검 없이 반환합니다. */
std::new_handler Widget::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

void * Widget::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler)); // Widget의 new 처리자를 설치합니다.

	return ::operator new(size); // 메모리를 할당하거나 할당이 실패하면 예외를 던집니다.
} // 이전의 전역 enw 처리자가 자동으로 복원됩니다.