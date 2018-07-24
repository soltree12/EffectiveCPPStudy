/*
항목 12) 객체의 모든 부분을 빠짐없이 복사하자
객체 복사 함수는 주어진 객체의 모든 데이터 멤버 및 모든 기본 클래스 부분을 빠뜨리지 말고 복사해야 합니다.
클래스의 복사 함수 두 개를 구현할 때, 한 쪽을 이용해서 다른 쪽을 구현하려는 시도는 절대로 하지 마세요. 그 대신, 공통된 동작을 제3의 함수에다 분리해 놓고
양쪽에서 이것을 호출하게 만들어서 해결합시다.
*/

#include "PriorityCustomer.h"
#include "Customer.h"
int main()
{
	PriorityCustomer prio("sfsf",13);
	PriorityCustomer prio2(prio);
}