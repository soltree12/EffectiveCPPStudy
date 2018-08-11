/*
항목 35) 가상 함수 대신 쓸 것들도 생각해 두는 자세를 시시때때로 길러 두자.
1. 가상 함수 대신에 쓸 수 있는 다른 방법으로 NVI 관용구 및 전략 패턴을 들 수 있습니다. 이 중 NVI 관용구는 그 자체가 템플릿 메서드 패턴의 한 예입니다.
2. 객체에 필요한 기능을 멤버 함수로부터 클래스 외부의 비멤버 함수로 옮기면, 그 비멤버 함수는 그 클래스의 public 멤버가 아닌 것들을 접근할 수 없다는 단점이 생깁니다.
3. tr1::function 객체는 일반화된 함수 포인터처럼 동작합니다. 이 객체는 주어진 목적 시그니처와 호환되는 모든 함수호출성 개체를 지원합니다.
*/

/*
어떤 문제를 해결하기 위한 설계를 찾을 때 가상 함수를 대신하는 방법들도 고려해 보자.
1. 비가상 인터페이스 관용구(NVI 관용구)를 사용합니다 : 공개되지 않은 가상 함수를 비가상 public 멤버 함수로 감사서 호출하는, 템플릿 메서도 패턴의 한 형태입니다.
2. 가상 함수를 함수 포인터 데이터 멤버로 대체합니다. : 군더더기 없이 전략 패턴의 핵심만을 보여주는 형태입니다.
3. 가상 함수를 tr1::function 데이터 멤버로 대체하여, 호환되는 시그니처를 가진 함수호출성 개체를 사용할 수 있도록 만듭니다 : 역시 전략 패턴의 한 형태입니다.
4. 한쪽 클래스 계통에 속해 있는 가상 함수를 다른 쪽 계통에 속해 있는 가상 함수로 대체합니다. : 전략 패턴의 전통적인 구현 형태입니다.
*/

#include <iostream>
#include <functional>
//#include "GameCharacter_FuncPointer.h"
//#include "GameCharacter_NVI.h"
//#include "GameCharacter_TR1Func.h"
#include "GameCharacter_Pattern.h"
using namespace std::placeholders;

int main()
{
	/* GameCharacter_FuncPointer */
	/*
	EvilBadGuy ebg1(125);
	std::cout<<ebg1.healthFunction()<<std::endl;
	return 0;
	*/


	/* GameCharacter_TR1Func */
	/*
	EvilBadGuy ebg1(120, calcHealth);
	std::cout << ebg1.healthFunction() << std::endl;

	EvilBadGuy ebg2(130, HealthCalculator());
	std::cout << ebg2.healthFunction() << std::endl;
	
	GameLevel currentLevel;
	
	//GameLevel::health 함수는 매개변수 하나를 받는 것으로 선언되어 있지만, 실제로는 두 개를 받습니다. GameLevel 객체 하나를 암시적으로 받아들이니까 말이죠. 
	//currentLevel : 사용할 객체 , _1 : 자유 매개변수(&GameLevel::health의 매개변수는 &GameCharacter이므로 이 타입은 맞춰줘야함
	EvilBadGuy ebg3(10, bind(&GameLevel::health, currentLevel, _1)); 
	std::cout << ebg3.healthFunction() << std::endl;
	*/


	/* GameCharacter_Pattern */
	HealthCalcFunc myHealthCalc;
	GameCharacter gc(10, &myHealthCalc);
	std::cout << gc.healthValue() << std::endl;
}