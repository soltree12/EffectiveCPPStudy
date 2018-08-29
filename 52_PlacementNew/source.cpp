/*
�׸� 52) ��ġ���� new�� �ۼ��Ѵٸ� ��ġ���� delete�� ���� �غ�����
1. operator new �Լ��� ��ġ����(placement) ������ ���� ����, �� �Լ��� ¦�� �̷�� ��ġ���� ������ operator delete �Լ��� �� ����� �ּ���. �� ���� ���Ծ��ٰ���, ã�Ƴ��⵵
����� �� ����ٰ� �� ����� �ϴ� �޸� ���� ������ �����ϰ� �˴ϴ�.
2. new �� delete�� ��ġ���� ������ ������ ����, �ǵ��� �ٵ� �ƴѵ� �̵��� ǥ�� ������ �������� ���� ������ �ʵ��� ������ �ּ���.
*/

#include<new>
#include<iostream>

/* 1. �Ű����� ¦�� �´� new�� delete�� ���� ������. */
class Widget {
public:
	static void* operator new(std::size_t size, std::ostream& logStream) throw(std::bad_alloc) { return ::operator new(size); } // size�ܿ� �Ű������� �ִ� ������ new�� ��ġ���� new�� ��
	static void operator delete(void *pMemory, size_t size) throw() { return ::operator delete(pMemory, size); }// Ŭ���� ���� operator delete�� ǥ�� ����

	/* new�� ¦�� �´� �Ű������� delete�� �־� �־�� ��*/
	static void operator delete(void *pMemory, std::ostream& logStream) throw() { return ::operator delete(pMemory); }
};

/* 2. �⺻ Ŭ������ �ϳ� �����, �� �ȿ� new �� delete�� �⺻ ���¸� ���� �־����. */
class StandardNewDeleteForms {
public:
	//�⺻�� new/delete
	static void* operator new(std::size_t size) throw(std::bad_alloc) { return ::operator new(size); }

	static void operator delete(void *pMemory) throw() { ::operator delete(pMemory); }

	//��ġ���� new/delete
	static void* operator new(std::size_t size, void *ptr) throw() { return ::operator new(size, ptr); }

	static void operator delete(void *pMemory, void *ptr) throw() { return ::operator delete(pMemory, ptr); }

	//���ܺҰ� new/delete
	static void* operator new(std::size_t size, const std::nothrow_t& nt) throw() { return ::operator new(size, nt); }

	static void operator delete(void *pMemory, const std::nothrow_t&) throw() { return ::operator delete(pMemory); }

};
int main()
{
	Widget *pw = new (std::cerr) Widget;//operator new�� ȣ���ϴ� �� cerr�� ostream ���ڷ� �ѱ�µ�, �̶� Widget �����ڿ��� ���ܰ� �߻��ϸ� �޸𸮰� ����˴ϴ�.
	delete pw;
	StandardNewDeleteForms *sndf = new StandardNewDeleteForms;
	delete sndf;
}