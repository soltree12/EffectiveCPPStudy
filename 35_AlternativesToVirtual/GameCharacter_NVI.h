/* 
비가상 인터페이스 관용구를 통한 템플릿 메서드 패턴(NVI(non-virtual interface))
=> healthValue를 public 멤버 함수로 그대로 두되 비가상 함수로 선언하고, 내부적으로는 실제 동작은 맡은 private 가상 함수를 호출한다.
*/


#pragma once
class GameCharacter {
public:

	GameCharacter(int newHealth) : theHealth(newHealth){}

	int healthValue() const // 파생 클래스는 이제 이 함수를 재정의할 수 없습니다. 항목 36 참조. (가상함수의 Wrapper)
	{
		/* 사전 동작을 수행합니다.(뮤텍스 잠금, 로그 정보, 클래스 불변속성 or 함수의 사전조건 검증) */
		
		int retVal = doHealthValue(); // 실제 동작을 수행합니다.

		/* 사후 동작을 수행합니다.(뮤텍스 잠금 해제, 함수의 사후조건 or 클래스의 불변속성 재검증) */

		return retVal;
	}
	
private:
	virtual int doHealthValue() const // 파생 클래스에서 호출은 불가능하지만 재정의는 가능하다.
	{
		return theHealth; // 캐릭터의 체력치 계산을 위한 기본 알고리즘 구현
	}

	int theHealth;
};