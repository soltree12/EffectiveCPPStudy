/* 
�׸�48) ���ø� ��Ÿ���α׷���, ���� �ʰڴ°�? 
1. ���ø� ��Ÿ���α׷����� ���� �۾��� ��Ÿ�ӿ��� ������ Ÿ������ ��ȯ�ϴ� ȿ���� ���ϴ�. ���� TMP�� ���� ���� ���� Ž���� ���� ��Ÿ�� ȿ���� �տ� �Ÿ��� �� �ֽ��ϴ�.
2. TMP�� ��å ������ ���տ� ����Ͽ� ����� ���� �ڵ带 �����ϴ� �� �� �� ������, ���� Ư�� Ÿ�Կ� ���� �������� �ڵ尡 ��������� ���� ���µ��� �� �� �ֽ��ϴ�.
*/

#include<iostream>

template<unsigned n> // �Ϲ����� ���: Factorial<n>�� ���� Factorial<n-1>�� ���� n�� ���ؼ� ����ϴ�.
struct Factorial {
	enum{value =n *Factorial<n-1>::value};
};

template<>
struct Factorial<0> {
	enum { value = 1 };
};

int main()
{
	std::cout << Factorial<5>::value<<std::endl;
	std::cout << Factorial<10>::value<<std::endl;
}