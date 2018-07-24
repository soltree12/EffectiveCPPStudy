/*
항목15) 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할 수 있도록 하자
1. 실제 자원을 직접 접근해야 하는 기존 API들도 많기 때문에, RAII 클래스를 만들 때는 그 클래스가 관리하는 자원을 얻을 수 있는 방법을 열어 주어야 합니다.
2. 자원 접근은 명시적 변환 혹은 암시적 변환을 통해 가능합니다. 안전성만 따지면 명시적 변환이 대체적으로 더 낫지만, 고객 편의성을 놓고 보면 암시적 변환이 괜찮습니다.
*/

#include <iostream>
#include <memory>

class Investment {
public:
	Investment() { std::cout << "객체 생성" << std::endl; }
	~Investment() { std::cout << "객체 해제" << std::endl; }
	bool isTaxFree() const; // 여러 형태의 투자를 모델링한 투자 클래스들의 최상위 클래스
};

Investment* createInvestment(); // 팩토리 함수(로 가정)

Investment* createInvestment()
{
	return new Investment;
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
	std::shared_ptr<Investment> pInv(createInvestment());
	//int days = daysHeld(pInv); // 에러! 
	int days = daysHeld(pInv.get()); // 이제 문제없습니다. pInv에 들어 있는 실제 포인터를 daysHeld에 넘기니까요.


	/* shared_ptr의 역참조연산자(operator-> 및 operator*) */
	std::shared_ptr<Investment> pi1(createInvestment()); //tr1::shared_ptr이 자원 관리를 맡도록 합니다.

	bool taxable = !(pi1->isTaxFree()); // operator->를 써서 자원에 접근합니다.

	std::auto_ptr<Investment> pi2(createInvestment()); // auto_ptr로 하여금 자원 관리를 맡도록 합니다.

	bool taxable2 = !((*pi2).isTaxFree()); // operator*를 써서 자원에 접근합니다.
	std::cout << taxable << "/" << taxable2 << std::endl;
	return 0;
}