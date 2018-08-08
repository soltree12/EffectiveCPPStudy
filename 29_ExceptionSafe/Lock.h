#pragma once

#include <memory>

class Mutex {
};

void lock(Mutex *pm) {}

void unlock(Mutex *pm) {}

class Lock {
public:
	explicit Lock(Mutex *pm) : mutexPtr(pm, unlock) // shared_ptr�� �ʱ�ȭ�ϴµ�, ����ų �����ͷ� Mutex ��ü�� �����͸� ����ϰ� �����ڷ� unlock �Լ��� ����մϴ�.
	{
		lock(mutexPtr.get()); //�ڿ��� ȹ���մϴ�.
	}

	~Lock() { unlock(mutexPtr.get()); } // �ڿ��� �����մϴ�.

private:
	std::shared_ptr<Mutex> mutexPtr; // ���� ������ ��ſ� shared_ptr�� ����մϴ�.
};