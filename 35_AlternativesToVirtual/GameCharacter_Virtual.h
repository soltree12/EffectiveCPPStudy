/* virtual �Լ��� �̿��� �⺻ ���� */

#pragma once
class GameCharacter{
public:
	GameCharacter(int newHealth) : theHealth(newHealth){}
	
	virtual int healthValue() const// ĳ������ ü��ġ�� ��ȯ
	{
		return theHealth;
	}

private:
	int theHealth;
};