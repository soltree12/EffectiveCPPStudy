/* 
함수 포인터로 구현한 전략 패턴
=> 체력치 계산이 구태여 어떤 캐릭터의 일부일 필요는 없다. 각 캐릭터의 생성자에 체력치 계산용 함수의 포인터를 넘기게 만들고, 이 함수를 호출해서
실제 계산을 수행하도록 하자.
*/

#pragma once
class GameCharacter; // 전방 선언

int defaultHealthCalc(const GameCharacter& gc);
int loseHealthQuickly(const GameCharacter& gc);
int loseHealthSlowly(const GameCharacter& gc);
class GameCharacter {
public :
	typedef int(*HealthCalcFunc)(const GameCharacter&); // 함수 포인터

	explicit GameCharacter(int newHealth, HealthCalcFunc hcf = defaultHealthCalc): theHealth(newHealth),healthFunc(hcf){} // 생성자에 함수포인터 넘기기

	int getHealth() const { return theHealth; }

	int healthFunction() const
	{
		return healthFunc(*this);
	}

private:
	HealthCalcFunc healthFunc; 
	int theHealth;
};

class EvilBadGuy :public GameCharacter {
public:
	explicit EvilBadGuy(int newHealth, HealthCalcFunc hcf = defaultHealthCalc) : GameCharacter(newHealth, hcf){}
};


// 체력치 계산에 대한 기본 알고리즘을 구현한 함수(체력을 깎아서 반환한다고 가정)
int defaultHealthCalc(const GameCharacter& gc) {
	if (gc.getHealth() >= 10) return gc.getHealth() - 10;
	else return 0;
}

// 다른 동작 원리로 구현된 체력치 계산 함수들
int loseHealthQuickly(const GameCharacter& gc) {
	if (gc.getHealth() >= 100) return gc.getHealth() - 100;
	else return 0;
}

int loseHealthSlowly(const GameCharacter& gc) {
	if (gc.getHealth() >= 1) return gc.getHealth() - 1;
	else return 0;
}