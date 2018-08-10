#include <iostream>

class C {
public:
	void f1() { std::cout << "c_f1" << std::endl; };
	virtual void f2(){ std::cout << "c_f2" << std::endl; };
};

class D : public C {
public:
	void f1(){ std::cout << "d_f1" << std::endl; };
	virtual void f2(){ std::cout << "d_f2" << std::endl; };
	void f3() { f1(); }
};

void ff(C *c) {
	c->f2();
}

int main()
{
	D d;
	ff(&d);
}

