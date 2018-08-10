/* 엄격한 단순 가상 함수 만들기 : 인터페이스와 구현을 분리 */

/* 
1.
기본 동작을 쓰고 싶은 클래스(ModelA)는 fly 함수의 본문 안에서 defaultFly함수를 인라인 호출,
파생 동작을 만들고 싶은 클래스(ModelB)는 fly 함수를 오버라이드해 함수 구현
아무것도 안 쓸 경우에는 에러가 나므로 예외를 방지할 수 있다.
*/
#include <iostream>
class Airport{}; // 공항을 나타내는 클래스

class Airplane {
public:
	virtual void fly(const Airport& destination) = 0 ;

protected: // 내부적으로 사용하는 구현 세부사항이기때문에 protected 사용
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
		defaultFly(destination); // 기본 구현 사용
	}
};

class ModelB :public Airplane {
public:
	virtual void fly(const Airport& destination)
	{
		std::cout << "ModelB::fly" << std::endl; // 파생 동작 구현
	}
};

/*
2. 순수가상함수를 구현해버리기
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