#pragma once

#include <memory>

class Mutex {
};

void lock(Mutex *pm) {}

void unlock(Mutex *pm) {}

class Lock {
public:
	explicit Lock(Mutex *pm) : mutexPtr(pm, unlock) // shared_ptr을 초기화하는데, 가리킬 포인터로 Mutex 객체의 포인터를 사용하고 삭제자로 unlock 함수를 사용합니다.
	{
		lock(mutexPtr.get()); //자원을 획득합니다.
	}

	~Lock() { unlock(mutexPtr.get()); } // 자원을 해제합니다.

private:
	std::shared_ptr<Mutex> mutexPtr; // 원시 포인터 대신에 shared_ptr을 사용합니다.
};