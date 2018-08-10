/* ������ �ܼ� ���� �Լ� ����� : �������̽��� ������ �и� */

/* 
1.
�⺻ ������ ���� ���� Ŭ����(ModelA)�� fly �Լ��� ���� �ȿ��� defaultFly�Լ��� �ζ��� ȣ��,
�Ļ� ������ ����� ���� Ŭ����(ModelB)�� fly �Լ��� �������̵��� �Լ� ����
�ƹ��͵� �� �� ��쿡�� ������ ���Ƿ� ���ܸ� ������ �� �ִ�.
*/
#include <iostream>
class Airport{}; // ������ ��Ÿ���� Ŭ����

class Airplane {
public:
	virtual void fly(const Airport& destination) = 0 ;

protected: // ���������� ����ϴ� ���� ���λ����̱⶧���� protected ���
	void defaultFly(const Airport& destination);
};

void Airplane::defaultFly(const Airport& destination)
{
	std::cout << "Airplane::defaultFly" << std::endl;
}

class ModelA :public Airplane {
public:
	virtual void fly(const Airport& destination)
	{
		defaultFly(destination); // �⺻ ���� ���
	}
};

class ModelB :public Airplane {
public:
	virtual void fly(const Airport& destination)
	{
		std::cout << "ModelB::fly" << std::endl; // �Ļ� ���� ����
	}
};

/*
2. ���������Լ��� �����ع�����
*/
/*
void Airplane::fly(const Airport& destination)
{
	std::cout << "Airplane::fly" << std::endl;
}

class ModelA :public Airplane {
virtual void fly(const Airport& destination)
{
	Airplane::fly(destination);
}
};

class ModelB :public Airplane {
virtual void fly(const Airport& destination)
{
	std::cout << "ModelB::fly" << std::endl;
}
};
*/

int main2()
{
	Airport airp;
	ModelB b;
	b.fly(airp);

	return 0;
}