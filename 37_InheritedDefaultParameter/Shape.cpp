/*
항목 37) 어떤 함수에 대해서도 상속받은 기본 매개변수 값은 절대로 재정의하지 말자
1. 상속받은 기본 매개변수 값은 절대로 재정의해서는 안 됩니다. 왜냐하면 기본 매개변수 값은 정적으로 바인딩되는 반면, 가상 함수(여러분이 오버라이드할 수 있는 유일한 함수이죠)는
동적으로 바인딩되기 때문입니다.
*/

#include <iostream>

class Shape
{
public:
	enum ShapeColor { Red, Green, Blue};
	// 모든 도형은 자기 자신을 그리는 함수를 제공해야 합니다.
	virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle : public Shape {
public:
	// 기본 매개변수 값이 달라진 부분을 놓치지 마세요. 큰일 났습ㅂ니다!
	virtual void draw(ShapeColor color = Green) const
	{
		std::cout << "Rectangle::draw / ShapeColor : " << color << std::endl;
	}
};

class Circle : public Shape {
public:
	virtual void draw(ShapeColor color) const
	{
		std::cout << "Circle::draw / ShapeColor : " << color << std::endl;
	}
};



/* 
해결책 : 비가상 인터페이스 관용구(NVI 관용구)를 사용 
이처럼 설계하면 draw 함수의 color 매개변수에 대한 기본값을 깔끔하게 Red로 고정시킬 수 있습니다.	
*/
class Shape_NVI {
public:
	enum ShapeColor { Red, Green, Blue };
	void draw(ShapeColor color = Red)
	{
		doDraw(color);
	}
private:
	virtual void doDraw(ShapeColor color) const = 0;
};

class Rectangle_NVI : public Shape_NVI {
private:
	virtual void doDraw(ShapeColor color) const // 기본 매개변수 값이 없습니다. 잘 보세요.
	{
		std::cout << "Rectangle::draw / ShapeColor : " << color << std::endl;
	}
};


int main()
{ 
	Shape *ps; // 정적 타입 = Shape*
	Shape *pc = new Circle; // 정적 타입 = Shape*
	Shape *pr = new Rectangle; // 정적 타입 = Shape*

	ps = pc; // ps의 동적 타입은 이제 Circle*이 됩니다.
	ps = pr; // ps의 동적 타입은 이제 Rectangle*이 됩니다.

	 /* 가상 함수는 동적으로 바인딩 됨 */
	pc->draw(Shape::Red); // Circle::draw(Shape::Red)를 호출합니다.
	ps->draw(Shape::Red); // Rectangle::draw(Shape::Red)을 호출합니다.

	/* 기본 매개변수는 정적으로 바인딩 됨 */
	pr->draw(); // (Rectangle::draw(Shape::Green)을 호출하기를 바라지만) Rectangle::draw(Shape::Red)를 호출한단 말입니다!

	/* 해결책 적용 */
	Shape_NVI *pr_NVI = new Rectangle_NVI;
	pr_NVI->draw();

	return 0;
}