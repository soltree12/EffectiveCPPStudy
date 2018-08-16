#pragma once
#include <list>
#include <iostream>
/* set 템플릿을 List에서 파생된 형태로부터 만들기 : Set은 List의 (is implemented in terms of)의 관계임*/

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