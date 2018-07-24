#include <iostream>
#include <memory>

class Investment {
public:
	Investment() { std::cout << "객체 생성" << std::endl; }
	~Investment() { std::cout << "객체 해제" << std::endl; }
	bool isTaxFree() const; // 여러 형태의 투자를 모델링한 투자 클래스들의 최상위 클래스
};

std::shared_ptr<Investment> createInvestment(); // 팩토리 함수(로 가정)

/* 팩토리 함수가 스마트 포인터를 반환하게 만드는 방법 */
std::shared_ptr<Investment> createInvestment()
{
	return std::shared_ptr<Investment>(new Investment);
}

bool Investment::isTaxFree() const
{
	return true;
}

int daysHeld(const Investment *pi) //Investment 객체를 사용하는 함수
{
	return 3;
}


int main()
{

	/* shared_ptr의 get함수 */
	std::shared_ptr<Investment> pInv=createInvestment();
	//int days = daysHeld(pInv); // 에러! 
	int days = daysHeld(pInv.get()); // 이제 문제없습니다. pInv에 들어 있는 실제 포인터를 daysHeld에 넘기니까요.


									 /* shared_ptr의 역참조연산자(operator-> 및 operator*) */
	std::shared_ptr<Investment> pi1 = createInvestment(); //tr1::shared_ptr이 자원 관리를 맡도록 합니다.

	bool taxable = !(pi1->isTaxFree()); // operator->를 써서 자원에 접근합니다.

	std::shared_ptr<Investment> pi2 = createInvestment(); // auto_ptr로 하여금 자원 관리를 맡도록 합니다.

	bool taxable2 = !((*pi2).isTaxFree()); // operator*를 써서 자원에 접근합니다.
	std::cout << taxable << "/" << taxable2 << std::endl;
	return 0;
}