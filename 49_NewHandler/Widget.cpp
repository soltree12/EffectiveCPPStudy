#include "Widget.h"
#include "NewHandlerHolder.h"
std::new_handler Widget::currentHandler = 0; // �η� �ʱ�ȭ�մϴ�.

/* �ڽſ��� �Ѿ�� �����͸� �ƹ��� ���� ���� ������ ����, �ٷ� ���� �����ߴ� �����͸� ���� �ƹ��� ���� ���� ��ȯ�մϴ�. */
std::new_handler Widget::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

void * Widget::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler)); // Widget�� new ó���ڸ� ��ġ�մϴ�.

	return ::operator new(size); // �޸𸮸� �Ҵ��ϰų� �Ҵ��� �����ϸ� ���ܸ� �����ϴ�.
} // ������ ���� enw ó���ڰ� �ڵ����� �����˴ϴ�.