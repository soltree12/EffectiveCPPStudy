#pragma once
#include <list>
#include <iostream>
class A {
public:
	int i;
};

int main()
{
	A a;
	a.i = 3;
	A b;
	b.i = 4;

	std::swap(a.i, b.i);

	std::cout << a.i << std::endl;
	

}