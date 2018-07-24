/*
(Non-Executable)
항목)13 자원관리에는 객체가 그만!
1. 자원 누출을 막기 위해, 생성자 안에서 자원을 획득하고 소멸자에서 그것을 해제하는 RAII(자원 획득 즉 초기화)객체를 사용합시다.
2. 일반적으로 널리 쓰이는 RAII클래스는 tr1::shared_ptr 그리고 auto_ptr입니다. 이 둘 가운데 tr1::shared_ptr이 복사 시의 동작이 직관적이기 때문에
대개 더 좋습니다. 반면, auto_ptr은 복사되는 객체(원본 객체)를 null로 만들어 버립니다.
*/

#include <memory>

class Investment{};

Investment* createInvestment() // 팩토리 함수로 가정
{
	return new Investment;
}

void f()
{
	/*
	1. auto_ptr은 포인터와 비슷하게 동작하는 객체로서, 가리키고 있는 대상에 대해 소멸자가 자동으로 delete를 불러주도록 설계되어 있습니다.
	2. auto_ptr 객체를 복사하면 원본 객체는 null로 만드는 특성이 있습니다. -> STL 컨테이너의 경우엔 원소들이 '정상적인' 복사 동작을 가져야 하기 때문에,
	auto_ptr은 이들의 원소로 허용되지 않습니다.
	*/
	std::auto_ptr<Investment> pInv1(createInvestment()); // createInvestment 함수에서 반환된 객체입니다.
	std::auto_ptr<Investment> pInv2(pInv1);//pInv2는 현재 그 객체를 가리키고 있으며, pInv1은 null입니다.

	pInv1 = pInv2; // 지금 pInv1은 그 객체를 가리키고 있으며, pInv2는 null입니다.

	/*
	RSCP(reference-counting smart pointer)는 특정한 어떤 자원을 가리키는(참조하는) 외부 객체의 개수를 유지하고 있다가 그 개수가 0이 되면 해당 자원을
	자동으로 삭제하는 스마트 포인터입니다.
	*/
	std::tr1::shared_ptr<Investment> pInv(createInvestment());
}