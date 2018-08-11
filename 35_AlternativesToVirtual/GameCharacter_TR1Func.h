/*
tr1::function으로 구현한 전략 패턴
반환값, 매개변수의 호환 가능성을 높이는 설계(시그니처가 호환되는 함수호출성 개체)
ex) 반환값이 int가 아니지만 int로 바꿀 수 있는 임의의 타입으로 함수를 만들어도 호환되도록 만든다.
*/

#pragma once
#include <functional>
class GameCharacter; // 전방 선언

int defaultHealthCalc(const GameCharacter& gc);
short calcHealth(const GameCharacter& gc); // 체력치 계산 함수입니다. 반환 타입이 int가 아닌 부분에 주목!

/* 체력치 계산용 함수 객체를 만들기 위한 클래스 */
struct HealthCalculator { 
	int operator()(const GameCharacter& gc) const; 
};

class GameLevel {
public:
	float health(const GameCharacter&) const; // 체력치 계산에 쓰일 멤버 함수입니다. 반환 타입이 int가 아닌 부분에 주목하세요
};

class GameCharacter {
public:
	/*
	HealthCalcFunc는 함수호출성 개체로서, GameCharacter와 호환노디는 어떤 것이든 넘겨받아서 호출될 수 있으며
	int와 호환되는 모든 타입의 객체를 반환합니다.
	*/
	typedef std::function<int (const GameCharacter&)> HealthCalcFunc; // funtcion 템플릿을 인스턴스화한 것에 대한 typedef 타입

	explicit GameCharacter(int newHealth, HealthCalcFunc hcf = defaultHealthCalc) : theHealth(newHealth), healthFunc(hcf) {} // 생성자에 함수포인터 넘기기

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
	explicit EvilBadGuy(int newHealth, HealthCalcFunc hcf = defaultHealthCalc) : GameCharacter(newHealth, hcf) {}
};


// 체력치 계산에 대한 기본 알고리즘을 구현한 함수(체력을 깎아서 반환한다고 가정)
int defaultHealthCalc(const GameCharacter& gc) {
	if (gc.getHealth() >= 5) return gc.getHealth() - 5;
	else return 0;
}

// 다른 동작 원리로 구현된 체력치 계산 함수들
short calcHealth(const GameCharacter& gc){
	if (gc.getHealth() >= 10) return gc.getHealth() - 10;
	else return 0;
}

int HealthCalculator::operator()(const GameCharacter& gc) const {
		if (gc.getHealth() >= 100) return gc.getHealth() - 100;
		else return 0;
}

int loseHealthQuickly(const GameCharacter& gc) {
	if (gc.getHealth() >= 100) return gc.getHealth() - 100;
	else return 0;
}

float GameLevel::health(const GameCharacter& gc) const {
	if (gc.getHealth() >= 1) return gc.getHealth() - 1;
	else return 0;
}