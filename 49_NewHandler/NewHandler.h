#pragma once
#include <new>
namespace std {
	typedef void(*new_handler)();
	new_handler set_new_handler(new_handler p) throw();
}