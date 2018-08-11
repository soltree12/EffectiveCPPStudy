/*
"��������" ���� ����
=> 1. �Լ� Ŭ������ ���� �����.
2. ��ü�� �ش� �Լ� Ŭ������ �����͸� ������.
3. ������ ��ü���� �Լ� Ŭ������ �Լ��� �ҷ����� ������ �����.
*/

#pragma once
class GameCharacter; //���漱��

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