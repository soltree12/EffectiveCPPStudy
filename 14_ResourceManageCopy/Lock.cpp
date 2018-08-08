/*
(non-excutable)
항목14) 자원관리 클래스의 복사 동작에 대해 진지하게 고찰하자
1. RAII 객체의 복사는 그 객체가 관리하는 자원의 복사 문제를 안고 가기 때문에, 그 자원을 어떻게 복사하느냐에 따라 RAII 객체의 복사 동작이 결정됩니다.
2. RAII 클래스에 구현하는 일반적인 복사 동작은 복사를 금지하거나 참조 카운팅을 해 주는 선으로 마무리하는 것입니다. 하지만 이 외의
방법들도 가능하니 참조해 둡시다.
*/

#include <iostream>

class Mutex
{

};

void lock(Mutex *pm)// pm이 가리키는 뮤텍스에 잠금을 겁니다.
{}

void unlock(Mutex *pm) // pm이 가리키는 해당 뮤텍스의 잠금을 풉니다.
{}
class Lock {
public:
	explicit Lock(Mutex *pm) : mutexPtr(pm, unlock) // shared_ptr을 초기화하는데, 가리킬 포인터로 Mutex 객체의 포인터를 사용하고 삭제자로 unlock 함수를 사용합니다.
	{
		lock(mutexPtr.get()); //자원을 획득합니다.
	}

	~Lock(){unlock(mutexPtr.get()) } // 자원을 해제합니다.

private:
	std::shared_ptr<Mutex> mutexPtr; // 원시 포인터 대신에 shared_ptr을 사용합니다.
};

Mutex m;

void func()
{
	Lock m1(&m);
}