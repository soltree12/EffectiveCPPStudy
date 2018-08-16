/*
항목40) 다중 상속은 심사숙고해서 사용하자.
1. 다중 상속은 단일 상속보다 확실히 복잡합니다. 새로운 모호성 문제를 일으킬 뿐만 아니라 가상 상속이 필요해질 수도 있습니다.
2. 가상 상속을 쓰면 크기 비용, 속도 비용이 늘어나며, 초기화 및 대입 연산의 복잡도가 커집니다. 따라서 가상 기본 클래스에는 데이터를 두지 않는 것이 현실적으로 가장 실용적입니다.
3. 가상 상속을 적법하게 쓸 수 있는 경우가 있습니다. 여러 시나리오 중 하나는, 인터페이스 클래스로부터 public 상속을 시킴과 동시에 구현을 돕는 클래스로부터 private 상속을 시키는 것입니다.
*/


#include "BadMI.h"
#include "IPerson.h"


int main()
{
	/* BadMI */
	MP3Player mp;
	// mp.checkOut(); // 모호성 발생! 대관절 어느 checkOut이란 말씀?'
	mp.BorrowableItem::checkOut(); // 이런 식으로 호출


	/* IPerson */
	DatabaseID id(2);
	std::string myName = "Brown";

	std::shared_ptr<IPerson> ip; // IPerson 인터페이스를 지원하는 객체를 하나 만들고 pp로 가리키게 합니다. 이후에는 *pp의 조작을 위해 IPerson의 멤버 함수를 사용합니다
	ip = IPerson::makePerson(id, myName);
	
	std::cout<<ip->name()<<std::endl;
}