/*
항목 52) 위치지정 new를 작성한다면 위치지정 delete도 같이 준비하자
1. operator new 함수의 위치지정(placement) 버전을 만들 때는, 이 함수와 짝을 이루는 위치지정 버전의 operator delete 함수도 꼭 만들어 주세요. 이 일을 빼먹었다가는, 찾아내기도
힘들며 또 생겼다가 안 생겼다 하는 메모리 누출 현상을 경험하게 됩니다.
2. new 및 delete의 위치지정 버전을 선언할 때는, 의도한 바도 아닌데 이들의 표준 버전이 가려지는 일이 생기지 않도록 주의해 주세요.
*/

#include<new>
#include<iostream>

/* 1. 매개변수 짝이 맞는 new와 delete를 같이 만들자. */
class Widget {
public:
	static void* operator new(std::size_t size, std::ostream& logStream) throw(std::bad_alloc) { return ::operator new(size); } // size외에 매개변수가 있는 형태의 new를 위치지정 new라 함
	static void operator delete(void *pMemory, size_t size) throw() { return ::operator delete(pMemory, size); }// 클래스 전용 operator delete의 표준 형태

	/* new와 짝이 맞는 매개변수의 delete를 넣어 주어야 함*/
	static void operator delete(void *pMemory, std::ostream& logStream) throw() { return ::operator delete(pMemory); }
};

/* 2. 기본 클래스를 하나 만들고, 이 안에 new 및 delete의 기본 형태를 전부 넣어두자. */
class StandardNewDeleteForms {
public:
	//기본형 new/delete
	static void* operator new(std::size_t size) throw(std::bad_alloc) { return ::operator new(size); }

	static void operator delete(void *pMemory) throw() { ::operator delete(pMemory); }

	//위치지정 new/delete
	static void* operator new(std::size_t size, void *ptr) throw() { return ::operator new(size, ptr); }

	static void operator delete(void *pMemory, void *ptr) throw() { return ::operator delete(pMemory, ptr); }

	//예외불가 new/delete
	static void* operator new(std::size_t size, const std::nothrow_t& nt) throw() { return ::operator new(size, nt); }

	static void operator delete(void *pMemory, const std::nothrow_t&) throw() { return ::operator delete(pMemory); }

};
int main()
{
	Widget *pw = new (std::cerr) Widget;//operator new를 호출하는 데 cerr을 ostream 인자로 넘기는데, 이때 Widget 생성자에서 예외가 발생하면 메모리가 누출됩니다.
	delete pw;
	StandardNewDeleteForms *sndf = new StandardNewDeleteForms;
	delete sndf;
}