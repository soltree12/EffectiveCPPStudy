/*
항목 17) new 및 delete를 사용할 때는 형태를 반드시 맞추자
1. new 표현식에 []를 썼으면, 대응되는 delete 표현식에도 []를 써야 합니다. 마찬가지로 new 표현식에 []를 안 썼으면, 대응되는 delete 표현식에도 []를 쓰지 말아야 합니다.
*/

#include <iostream>
#include <string>

int main()
{
	std::string *stringPtr1 = new std::string;
	std::string *stringPtr2 = new std::string[100];

	delete stringPtr1; // 객체 한 개를 삭제합니다.
	delete[] stringPtr2; // 객체의 배열을 삭제합니다.

	typedef std::string AddressLines[4]; //주소는 네 줄로 되어 있고, 각각은 string입니다.(되도록이면 배열 타입을 typedef 타입으로 만들지 않고, vector로 정의하는 방법도 있습니다.)

	std::string *pal = new AddressLines;
	pal[0] = "124.";
	pal[1] = "192.";
	pal[2] = "255.";
	pal[3] = "1";
	std::cout << pal[1];
	delete [] pal;

	return 0;
}