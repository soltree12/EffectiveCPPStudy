/*
�׸�15) �ڿ� ���� Ŭ�������� �����Ǵ� �ڿ��� �ܺο��� ������ �� �ֵ��� ����
1. ���� �ڿ��� ���� �����ؾ� �ϴ� ���� API�鵵 ���� ������, RAII Ŭ������ ���� ���� �� Ŭ������ �����ϴ� �ڿ��� ���� �� �ִ� ����� ���� �־�� �մϴ�.
2. �ڿ� ������ ����� ��ȯ Ȥ�� �Ͻ��� ��ȯ�� ���� �����մϴ�. �������� ������ ����� ��ȯ�� ��ü������ �� ������, �� ���Ǽ��� ���� ���� �Ͻ��� ��ȯ�� �������ϴ�.
*/

#include <iostream>
#include <memory>

class Investment {
public:
	Investment() { std::cout << "��ü ����" << std::endl; }
	~Investment() { std::cout << "��ü ����" << std::endl; }
	bool isTaxFree() const; // ���� ������ ���ڸ� �𵨸��� ���� Ŭ�������� �ֻ��� Ŭ����
};

Investment* createInvestment(); // ���丮 �Լ�(�� ����)

Investment* createInvestment()
{
	return new Investment;
}

bool Investment::isTaxFree() const
{
	return true;
}

int daysHeld(const Investment *pi) //Investment ��ü�� ����ϴ� �Լ�
{
	return 3;
}


int main()
{

	/* shared_ptr�� get�Լ� */
	std::shared_ptr<Investment> pInv(createInvestment());
	//int days = daysHeld(pInv); // ����! 
	int days = daysHeld(pInv.get()); // ���� ���������ϴ�. pInv�� ��� �ִ� ���� �����͸� daysHeld�� �ѱ�ϱ��.


	/* shared_ptr�� ������������(operator-> �� operator*) */
	std::shared_ptr<Investment> pi1(createInvestment()); //tr1::shared_ptr�� �ڿ� ������ �õ��� �մϴ�.

	bool taxable = !(pi1->isTaxFree()); // operator->�� �Ἥ �ڿ��� �����մϴ�.

	std::auto_ptr<Investment> pi2(createInvestment()); // auto_ptr�� �Ͽ��� �ڿ� ������ �õ��� �մϴ�.

	bool taxable2 = !((*pi2).isTaxFree()); // operator*�� �Ἥ �ڿ��� �����մϴ�.
	std::cout << taxable << "/" << taxable2 << std::endl;
	return 0;
}