/*
tr1::function���� ������ ���� ����
��ȯ��, �Ű������� ȣȯ ���ɼ��� ���̴� ����(�ñ״�ó�� ȣȯ�Ǵ� �Լ�ȣ�⼺ ��ü)
ex) ��ȯ���� int�� �ƴ����� int�� �ٲ� �� �ִ� ������ Ÿ������ �Լ��� ���� ȣȯ�ǵ��� �����.
*/

#pragma once
#include <functional>
class GameCharacter; // ���� ����

int defaultHealthCalc(const GameCharacter& gc);
short calcHealth(const GameCharacter& gc); // ü��ġ ��� �Լ��Դϴ�. ��ȯ Ÿ���� int�� �ƴ� �κп� �ָ�!

/* ü��ġ ���� �Լ� ��ü�� ����� ���� Ŭ���� */
struct HealthCalculator { 
	int operator()(const GameCharacter& gc) const; 
};

class GameLevel {
public:
	float health(const GameCharacter&) const; // ü��ġ ��꿡 ���� ��� �Լ��Դϴ�. ��ȯ Ÿ���� int�� �ƴ� �κп� �ָ��ϼ���
};

class GameCharacter {
public:
	/*
	HealthCalcFunc�� �Լ�ȣ�⼺ ��ü�μ�, GameCharacter�� ȣȯ���� � ���̵� �Ѱܹ޾Ƽ� ȣ��� �� ������
	int�� ȣȯ�Ǵ� ��� Ÿ���� ��ü�� ��ȯ�մϴ�.
	*/
	typedef std::function<int (const GameCharacter&)> HealthCalcFunc; // funtcion ���ø��� �ν��Ͻ�ȭ�� �Ϳ� ���� typedef Ÿ��

	explicit GameCharacter(int newHealth, HealthCalcFunc hcf = defaultHealthCalc) : theHealth(newHealth), healthFunc(hcf) {} // �����ڿ� �Լ������� �ѱ��

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


// ü��ġ ��꿡 ���� �⺻ �˰����� ������ �Լ�(ü���� ��Ƽ� ��ȯ�Ѵٰ� ����)
int defaultHealthCalc(const GameCharacter& gc) {
	if (gc.getHealth() >= 5) return gc.getHealth() - 5;
	else return 0;
}

// �ٸ� ���� ������ ������ ü��ġ ��� �Լ���
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