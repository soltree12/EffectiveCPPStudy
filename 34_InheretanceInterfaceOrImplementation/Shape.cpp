/*
항목 34) 인터페이스 상속과 구현 상속의 차이를 제대로 파악하고 구별하자.
1. 인터페이스 상속은 구현 상속과 다릅니다. public 상속에서, 파생 크래스는 항상 기본 클래스의 인터페이스를 모두 물려받습니다.
2. 순수 가상 함수는 인터페이스 상속만을 허용합니다.
3. 단순(비순수) 가상 함수는 인터페이스 상속과 더불어 기본 구현의 상속도 가능하도록 지정됩니다.
4. 비가상 함수는 인터페이스 상속과 더불어 필수 구현의 상속도 가하도록 지정합니다.
*/

#include<iostream>
#include <string>
class Shape {
public:

	/*
	1. 순수 가상 함수를 선언하는 목적은 파생클래스에게 함수의 인터페이스만을 물려주려는 것입니다.
	" draw 함수는 여러분이 직접 제공하도록 하시우. 하지만 당신이 어떻게 구현할지에 대해선 난 아무 생각 없소. "
	*/
	virtual void draw() const = 0;

	/*
	2. 단순 가상 함수를 선언하는 목적은 파생 클래스로 하여금 함수의 인터페이스뿐만 아니라 그 함수의 기본 구현도 물려받게 하자는 것입니다.
	"error 함수는 여러분이 지원해야 한다우. 그러나 굳이 새로 만들 생각이 없다면 Shape 클래스에 있는 기본 버전을 그냥 쓰시구려."
	*/
	virtual void error(const std::string& msg) { std::cout << "Shape::error" << std::endl; }

	/*
	3. 비가상 함수를 선언하는 목적은 파생 클래스가 함수 인터페이스와 더불어 그 함수의 필수적인 구현을 물려받게 하는 것입니다.
	"Shape 및 이것에서 파생된 모든 객체는 객체의 식별자를 내어 주는 함수를 갖게 되겠지. 객체 식별자를 계산하는 방법은 항상 똑같겠군.
	실제 계산 방법은 Shape::objectID의 정의에서 결정되고, 파생 클래스는 이것을 바꿀 수 없겠는걸."
	*/
	int objectID() const { std::cout << "Shape::objectID" << std::endl; }
};

void Shape::draw() const
{
	std::cout << "Shape::draw" << std::endl;
}

class Rectangle: public Shape{
public:
	virtual void draw() const { std::cout << "Rectangle::draw" << std::endl; }
};
class Ellipse : public Shape{
public:
	virtual void draw() const { std::cout << "Ellipse::draw" << std::endl; }
};


int main()
{
	/* 1.*/
	//Shape *ps = new Shape; //에러! Shape는 추상 클래스입니다.

	Shape *ps1 = new Rectangle;
	ps1->draw();

	Shape *ps2 = new Ellipse;
	ps2->draw();

	ps1->Shape::draw(); // Shape::draw를 호출합니다.(구현이 붙은 순수 가상함수 호출하기)
	ps2->Shape::draw(); 
}