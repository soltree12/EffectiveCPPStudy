/* virtual 함수를 이용한 기본 구현 */

#pragma once
class GameCharacter{
public:
	GameCharacter(int newHealth) : theHealth(newHealth){}
	
	virtual int healthValue() const// 캐릭터의 체력치를 반환
	{
		return theHealth;
	}

private:
	int theHealth;
};