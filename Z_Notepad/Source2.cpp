#pragma once
#include <list>
#include <iostream>
/* set ���ø��� List���� �Ļ��� ���·κ��� ����� : Set�� List�� (is implemented in terms of)�� ������*/

int main()
{
	std::list<int> rep;
	rep.push_back(3);
	rep.push_back(5);
	rep.push_back(4);
	std::list<int>::iterator iter;
	iter=std::find(rep.begin(), rep.end(), 4);
	std::cout << *(--iter) << std::endl;
}