/*
(non-excutable)
�׸�14) �ڿ����� Ŭ������ ���� ���ۿ� ���� �����ϰ� ��������
1. RAII ��ü�� ����� �� ��ü�� �����ϴ� �ڿ��� ���� ������ �Ȱ� ���� ������, �� �ڿ��� ��� �����ϴ��Ŀ� ���� RAII ��ü�� ���� ������ �����˴ϴ�.
2. RAII Ŭ������ �����ϴ� �Ϲ����� ���� ������ ���縦 �����ϰų� ���� ī������ �� �ִ� ������ �������ϴ� ���Դϴ�. ������ �� ����
����鵵 �����ϴ� ������ �ӽô�.
*/

#include <iostream>
#include <mutex>

void lock(std::mutex *pm); // pm�� ����Ű�� ���ؽ��� ����� �̴ϴ�.

void unlock(std::mutex *pm); // pm�� ����Ű�� �ش� ���ؽ��� ����� Ǳ�ϴ�.

class Lock {
public:
	explicit Lock(std::mutex *pm) : mutexPtr(pm, unlock) // shared_ptr�� �ʱ�ȭ�ϴµ�, ����ų �����ͷ� Mutex ��ü�� �����͸� ����ϰ� �����ڷ� unlock �Լ��� ����մϴ�.
	{
		lock(mutexPtr.get()); //�ڿ��� ȹ���մϴ�.
	}

	~Lock(){unlock(mutexPtr) } // �ڿ��� �����մϴ�.

private:
	std::tr1::shared_ptr<std::mutex> *mutexPtr; // ���� ������ ��ſ� shared_ptr�� ����մϴ�.
};

std::mutex m;

void func()
{
	Lock m1(&m);
}