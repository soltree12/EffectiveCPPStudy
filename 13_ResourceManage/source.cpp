/*
(Non-Executable)
�׸�)13 �ڿ��������� ��ü�� �׸�!
1. �ڿ� ������ ���� ����, ������ �ȿ��� �ڿ��� ȹ���ϰ� �Ҹ��ڿ��� �װ��� �����ϴ� RAII(�ڿ� ȹ�� �� �ʱ�ȭ)��ü�� ����սô�.
2. �Ϲ������� �θ� ���̴� RAIIŬ������ tr1::shared_ptr �׸��� auto_ptr�Դϴ�. �� �� ��� tr1::shared_ptr�� ���� ���� ������ �������̱� ������
�밳 �� �����ϴ�. �ݸ�, auto_ptr�� ����Ǵ� ��ü(���� ��ü)�� null�� ����� �����ϴ�.
*/

#include <memory>

class Investment{};

Investment* createInvestment() // ���丮 �Լ��� ����
{
	return new Investment;
}

void f()
{
	/*
	1. auto_ptr�� �����Ϳ� ����ϰ� �����ϴ� ��ü�μ�, ����Ű�� �ִ� ��� ���� �Ҹ��ڰ� �ڵ����� delete�� �ҷ��ֵ��� ����Ǿ� �ֽ��ϴ�.
	2. auto_ptr ��ü�� �����ϸ� ���� ��ü�� null�� ����� Ư���� �ֽ��ϴ�. -> STL �����̳��� ��쿣 ���ҵ��� '��������' ���� ������ ������ �ϱ� ������,
	auto_ptr�� �̵��� ���ҷ� ������ �ʽ��ϴ�.
	*/
	std::auto_ptr<Investment> pInv1(createInvestment()); // createInvestment �Լ����� ��ȯ�� ��ü�Դϴ�.
	std::auto_ptr<Investment> pInv2(pInv1);//pInv2�� ���� �� ��ü�� ����Ű�� ������, pInv1�� null�Դϴ�.

	pInv1 = pInv2; // ���� pInv1�� �� ��ü�� ����Ű�� ������, pInv2�� null�Դϴ�.

	/*
	RSCP(reference-counting smart pointer)�� Ư���� � �ڿ��� ����Ű��(�����ϴ�) �ܺ� ��ü�� ������ �����ϰ� �ִٰ� �� ������ 0�� �Ǹ� �ش� �ڿ���
	�ڵ����� �����ϴ� ����Ʈ �������Դϴ�.
	*/
	std::tr1::shared_ptr<Investment> pInv(createInvestment());
}