/*
"고전적인" 전략 패턴
=> 1. 함수 클래스를 따로 만든다.
2. 본체는 해당 함수 클래스의 포인터를 가진다.
3. 연산은 본체에서 함수 클래스의 함수를 불러오는 식으로 만든다.
*/

#pragma once
class GameCharacter; //전방선언

class HealthCalcFunc {
public:
	virtual int calc(const GameCharacter& gc) const;
};

HealthCalcFunc defaultHealthCalc;

class GameCharacter {
public:
	explicit GameCharacter(int newHealth, HealthCalcFunc *phcf = &defaultHealthCalc) : theHealth(newHealth), pHealthCalc(phcf){}
	int health() const { return theHealth; }
	int healthValue() const { return pHealthCalc->calc(*this); }
private:
	int theHealth;
	HealthCalcFunc* pHealthCalc;
};

int HealthCalcFunc::calc(const GameCharacter& gc) const
{
	return gc.health();
}