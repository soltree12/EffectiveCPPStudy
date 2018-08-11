/* 
�Լ� �����ͷ� ������ ���� ����
=> ü��ġ ����� ���¿� � ĳ������ �Ϻ��� �ʿ�� ����. �� ĳ������ �����ڿ� ü��ġ ���� �Լ��� �����͸� �ѱ�� �����, �� �Լ��� ȣ���ؼ�
���� ����� �����ϵ��� ����.
*/

#pragma once
class GameCharacter; // ���� ����

int defaultHealthCalc(const GameCharacter& gc);
int loseHealthQuickly(const GameCharacter& gc);
int loseHealthSlowly(const GameCharacter& gc);
class GameCharacter {
public :
	typedef int(*HealthCalcFunc)(const GameCharacter&); // �Լ� ������

	explicit GameCharacter(int newHealth, HealthCalcFunc hcf = defaultHealthCalc): theHealth(newHealth),healthFunc(hcf){} // �����ڿ� �Լ������� �ѱ��

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


// ü��ġ ��꿡 ���� �⺻ �˰����� ������ �Լ�(ü���� ��Ƽ� ��ȯ�Ѵٰ� ����)
int defaultHealthCalc(const GameCharacter& gc) {
	if (gc.getHealth() >= 10) return gc.getHealth() - 10;
	else return 0;
}

// �ٸ� ���� ������ ������ ü��ġ ��� �Լ���
int loseHealthQuickly(const GameCharacter& gc) {
	if (gc.getHealth() >= 100) return gc.getHealth() - 100;
	else return 0;
}

int loseHealthSlowly(const GameCharacter& gc) {
	if (gc.getHealth() >= 1) return gc.getHealth() - 1;
	else return 0;
}