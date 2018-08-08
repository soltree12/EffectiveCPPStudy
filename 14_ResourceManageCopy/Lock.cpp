/*
(non-excutable)
�׸�14) �ڿ����� Ŭ������ ���� ���ۿ� ���� �����ϰ� ��������
1. RAII ��ü�� ����� �� ��ü�� �����ϴ� �ڿ��� ���� ������ �Ȱ� ���� ������, �� �ڿ��� ��� �����ϴ��Ŀ� ���� RAII ��ü�� ���� ������ �����˴ϴ�.
2. RAII Ŭ������ �����ϴ� �Ϲ����� ���� ������ ���縦 �����ϰų� ���� ī������ �� �ִ� ������ �������ϴ� ���Դϴ�. ������ �� ����
����鵵 �����ϴ� ������ �ӽô�.
*/

#include <iostream>

class Mutex
{

};

void lock(Mutex *pm)// pm�� ����Ű�� ���ؽ��� ����� �̴ϴ�.
{}

void unlock(Mutex *pm) // pm�� ����Ű�� �ش� ���ؽ��� ����� Ǳ�ϴ�.
{}
class Lock {
public:
	explicit Lock(Mutex *pm) : mutexPtr(pm, unlock) // shared_ptr�� �ʱ�ȭ�ϴµ�, ����ų �����ͷ� Mutex ��ü�� �����͸� ����ϰ� �����ڷ� unlock �Լ��� ����մϴ�.
	{
		lock(mutexPtr.get()); //�ڿ��� ȹ���մϴ�.
	}

	~Lock(){unlock(mutexPtr.get()) } // �ڿ��� �����մϴ�.

private:
	std::shared_ptr<Mutex> mutexPtr; // ���� ������ ��ſ� shared_ptr�� ����մϴ�.
};

Mutex m;

void func()
{
	Lock m1(&m);
}