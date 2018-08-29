/*
�׸� 49) new ó������ ���� ������ ����� ��������.
1. set_new_handler �Լ��� ���� �޸� �Ҵ� ��û�� �������� ������ �� ȣ��Ǵ� �Լ��� ������ �� �ֽ��ϴ�.
2. ���ܺҰ�(nothrow) new�� ������� ���ѵǾ� �ֽ��ϴ�. �޸� �Ҵ� ��ü���� ����Ǳ� �����Դϴ�. ���Ŀ� ȣ��Ǵ� �����ڿ����� �󸶵��� ���ܸ� ���� �� �ֽ��ϴ�.
*/
#include "NewHandler.h"
#include <iostream>
#include "Widget.h"
void outOfMem()
{
	std::cerr << "Unable to satisfy request for memory\n";
	std::abort();
}

int main()
{
	/* 1. operator new�� ���� �Ҵ翡 �����ϸ� outOfMem�Լ��� ȣ��˴ϴ�. */
	/*
	std::set_new_handler(outOfMem);
	int *pBigDataArray = new int[100000000L];
	int *pBigDataArray2 = new int[100000000L];
	int *pBigDataArray3 = new int[100000000L];
	int *pBigDataArray4 = new int[100000000L];
	int *pBigDataArray5 = new int[100000000L];
	int *pBigDataArray6 = new int[100000000L];
	int *pBigDataArray7 = new int[100000000L];
	int *pBigDataArray8 = new int[100000000L];
	int *pBigDataArray9 = new int[100000000L];
	int *pBigDataArray10 = new int[100000000L];
	int *pBigDataArray11 = new int[100000000L];
	int *pBigDataArray12 = new int[100000000L];
	*/

	/* 2. Ư�� Ŭ�������� ���� �Ҵ翡�� ó���� */
	Widget::set_new_handler(outOfMem); // Widget�� new ó���� �Լ��μ� outOfMem�� ��ġ�մϴ�.
	Widget *pw1 = new Widget; // �޸� �Ҵ��� �����ϸ� outOfMem�� ȣ��˴ϴ�.
	std::string *ps = new std::string; // �޸��Ҵ��� �����ϸ� ���� new ó���� �Լ���(������) ȣ��˴ϴ�.

	Widget::set_new_handler(0); // Widget Ŭ�������� ���� new ó���� �Լ��� �ƹ��͵� ������ �մϴ�(��, null�� �����մϴ�.)
	Widget *pw2 = new Widget; // �޸� �Ҵ��� �����ϸ� ������ ���ܸ� �ٷ� �����ϴ�.(widget Ŭ������ ���� new ó���� �Լ��� �����ϴ�.)

	Widget2::set_new_handler(outOfMem); // �ͽ��� ����� WidgetŬ����
	Widget2 *pw3 = new Widget2;

	/* 3. std::nothrow ����ϱ�(�Ҵ��� �����ϸ� bad_alloc ���� ��� 0(��)�� ��ȯ�մϴ�.) */
	int *pw4 = new int; // �Ҵ��� �����ϸ� bad_alloc ���ܸ� �����ϴ�.
	if (pw1 == 0) {} // �� ���� �ڵ�� �� �����մϴ�.
	int *pw5 = new(std::nothrow) int; // Widget�� �Ҵ��ϴ� �����ϸ� 0(��)�� ��ȯ�մϴ�.
	if (pw2 == 0) {} // �� ���� �ڵ�� ������ �� �ֽ��ϴ�.
}