/*
�׸� 17) new �� delete�� ����� ���� ���¸� �ݵ�� ������
1. new ǥ���Ŀ� []�� ������, �����Ǵ� delete ǥ���Ŀ��� []�� ��� �մϴ�. ���������� new ǥ���Ŀ� []�� �� ������, �����Ǵ� delete ǥ���Ŀ��� []�� ���� ���ƾ� �մϴ�.
*/

#include <iostream>
#include <string>

int main()
{
	std::string *stringPtr1 = new std::string;
	std::string *stringPtr2 = new std::string[100];

	delete stringPtr1; // ��ü �� ���� �����մϴ�.
	delete[] stringPtr2; // ��ü�� �迭�� �����մϴ�.

	typedef std::string AddressLines[4]; //�ּҴ� �� �ٷ� �Ǿ� �ְ�, ������ string�Դϴ�.(�ǵ����̸� �迭 Ÿ���� typedef Ÿ������ ������ �ʰ�, vector�� �����ϴ� ����� �ֽ��ϴ�.)

	std::string *pal = new AddressLines;
	pal[0] = "124.";
	pal[1] = "192.";
	pal[2] = "255.";
	pal[3] = "1";
	std::cout << pal[1];
	delete [] pal;

	return 0;
}