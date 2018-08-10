/*
항목32) public 상속 모형은 반드시 "is-a(...는 ...의 일종이다)"를 따르도록 만들자.
1. public 상속의 의미는 "is-a(...는 ...의 일종)"입니다. 기본 클래스에 적용되는 모든 것들이 파생 클래스에 그대로 적용되어야 합니다. 
왜냐하면 모든 파생 클래스 객체는 기본 클래스 객체의 일종이기 때문입니다.
*/

#include <assert.h>

/* 1. public 상속은 is-a(~는 ~의 일종이다)를 의미한다. */
class Person{};

class Student : public Person{};

void eat(const Person& p){} // 먹는 것은 누구나 합니다.
void study(const Student& s){} // 학과 공부는 학생만 합니다.

/* 2. is-a 관계는 기본 클래스 객체가 가진 '모든' 것들이 파생 클래스 객체에도 그대로 적용되는 것을 보장한다. */
class Rectangle {
public:
	Rectangle(int newHeight, int newWidth) : theHeight(newHeight), theWidth(newWidth){}
	virtual void setHeight(int newHeight) { theHeight = newHeight; }
	virtual void setWidth(int newWidth) { theWidth = newWidth; }

	virtual int height() const {return theHeight;} // 현재의 값을 반환합니다.
	virtual int width() const { return theWidth; }

private:
	int theHeight;
	int theWidth;
};

void makeBigger(Rectangle& r) // r의 넓이를 늘리는 함수
{
	int oldHeight = r.height();
	r.setWidth(r.width() + 10);
	assert(r.height() == oldHeight); //조건이 참이면 넘어감, 거짓이면 에러 출력후 종료.(r의 세로 길이가 변하지 않는다는 조건에 단정문을 걸어둡니다.)
}

class Square : public Rectangle {
public:
	Square(int newLength) : Rectangle(newLength,newLength){}
};

int main()
{
	/*1*/
	Person p; // p는 Person의 일종입니다.(사람도 사람이니까)
	Student s; // s는 Student의 일종입니다.(학생도 학생이니까)

	eat(p); // 문제없습니다. p는 Person이니까요.
	eat(s); // 문제없습니다. s는 Student이고, Student는 Person의 일종이니까요.

	study(s); // 좋습니다.
	//study(p); // 에러입니다! p는 Student가 아닙니다.

	/*2*/
	Square sq(10);
	assert(sq.width() == sq.height());// 이 단정문은 모든 정사각형에 대해 참이어야 합니다.
	makeBigger(sq); // 상속된 것이므로, s는 Rectangle의 일종입니다. 즉, s의 넓이를 늘릴 수 있습니다.
	//assert(sq.width() == sq.height()); // 이번에도 이 단정문이 모든 정사각형에 대해 참이어야 합니다.(하지만 에러!) 
	/* 직사각형의 성질(가로 길이가 세로 길이에 상관 없이 바뀔 수 있습니다.)는 정사각형(가로와 세로 길이가 같아야 합니다.)에 적용할 수 없습니다.*/

}