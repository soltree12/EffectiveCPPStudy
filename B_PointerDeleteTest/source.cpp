#include <iostream>

int main()
{
	/*
	new ���� : ������ = new �ڷ���(��)
	*/
	int val = 11;
	int *pval1 = &val;
	int *pval2;
	pval2 = new int(*pval1);
	std::cout << *pval2 << std::endl;

	/*
	���� ���� -> �����Ͱ� �� �� ����Ű�� -> ���� ����
	*/
	int *p1 = new int(11);
	int *p2 = new int(12);
	int *pOrig = p1;
	p1 = new int(*p2);
	delete pOrig;
	std::cout << *p1 << std::endl;


	return 0;
}