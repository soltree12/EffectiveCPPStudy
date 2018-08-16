/*
�׸� 38 : "has-a(~�� ~�� ����)" Ȥ�� "is-implemented-in-terms-of(~�� ~�� �Ἥ ������)"�� ����ȭ�� ���� ��ü �ռ��� �������
1. ��ü �ռ�(compositon)�� �ǹ̴� public ����� ���� �ǹ̿� ������ �ٸ��ϴ�.
2. ���� �������� ��ü �ռ��� �ǹ̴� has-a(~�� ~�� ����)�Դϴ�. ���� ���������� is-implemented-in-terms-of(~�� ~�� �Ἥ ������)�� �ǹ̸� �����ϴ�.
*/


/*
1. is-a ���� : ~�� ~�� ���� (Derived�� Base�� �����̴�.)
2. has-a���� : ~�� ~�� ������.(Person�� �̸�, �ּ�, ������ȭ�� ������.)

3. is-implemented-in-terms-of ���� : ~�� ~�� �Ἥ �����ȴ�,(Set ��ü�� list ��ü�� �Ἥ �����ȴ�,)
*/
#include "Set.h"
#include <iostream>

int main()
{
	Set<int> s;
	s.insert(3);
	s.insert(4);
	s.remove(4);
	std::cout << s.member(3) << std::endl;
	std::cout << s.member(4) << std::endl;

	return 0;
}