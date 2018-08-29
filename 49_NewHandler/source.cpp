/*
항목 49) new 처리자의 동작 원리를 제대로 이해하자.
1. set_new_handler 함수를 쓰면 메모리 할당 요청이 만족되지 못했을 때 호출되는 함수를 지정할 수 있습니다.
2. 예외불가(nothrow) new는 영향력이 제한되어 있습니다. 메모리 할당 자체에만 적용되기 때문입니다. 이후에 호출되는 생성자에서는 얼마든지 예외를 던질 수 있습니다.
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
	/* 1. operator new가 정수 할당에 실패하면 outOfMem함수가 호출됩니다. */
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

	/* 2. 특정 클래스만을 위한 할당에러 처리자 */
	Widget::set_new_handler(outOfMem); // Widget의 new 처리자 함수로서 outOfMem을 설치합니다.
	Widget *pw1 = new Widget; // 메모리 할당이 실패하면 outOfMem이 호출됩니다.
	std::string *ps = new std::string; // 메모리할당이 실패하면 전역 new 처리자 함수가(있으면) 호출됩니다.

	Widget::set_new_handler(0); // Widget 클래스만을 위한 new 처리자 함수가 아무것도 없도록 합니다(즉, null로 설정합니다.)
	Widget *pw2 = new Widget; // 메모리 할당이 실패하면 이제는 예외를 바로 던집니다.(widget 클래스를 위한 new 처리자 함수가 없습니다.)

	Widget2::set_new_handler(outOfMem); // 믹스인 양식의 Widget클래스
	Widget2 *pw3 = new Widget2;

	/* 3. std::nothrow 사용하기(할당이 실패하면 bad_alloc 예외 대신 0(널)을 반환합니다.) */
	int *pw4 = new int; // 할당이 실패하면 bad_alloc 예외를 던집니다.
	if (pw1 == 0) {} // 이 점검 코드는 꼭 실패합니다.
	int *pw5 = new(std::nothrow) int; // Widget을 할당하다 실패하면 0(널)을 반환합니다.
	if (pw2 == 0) {} // 이 점검 코드는 성공할 수 있습니다.
}