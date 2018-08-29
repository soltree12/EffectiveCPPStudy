#pragma once
#include <new>
#include "NewHandlerSupport.h"
class Widget {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;
};

class Widget2 : public NewHandlerSupport<Widget> {

};
