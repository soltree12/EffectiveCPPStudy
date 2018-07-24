#include <iostream>

int main()
{
	/*
	new 사용법 : 포인터 = new 자료형(값)
	*/
	int val = 11;
	int *pval1 = &val;
	int *pval2;
	pval2 = new int(*pval1);
	std::cout << *pval2 << std::endl;

	/*
	원본 복사 -> 포인터가 새 값 가리키기 -> 원본 삭제
	*/
	int *p1 = new int(11);
	int *p2 = new int(12);
	int *pOrig = p1;
	p1 = new int(*p2);
	delete pOrig;
	std::cout << *p1 << std::endl;


	return 0;
}