/*
항목28) 내부에서 사용하는 객체에 대한 '핸들'을 반환하는 코드는 되도록 피하자.
1. 어떤 객체의 내부요소에 대한 핸들(참조자, 포인터, 반복자)을 반환하는 것은 되도록 피하세요. 캡슐화 정도를 높이고,
상수 멤버 함수가 객체의 상수성을 유지한 채로 동작할 수 있도록 하여, 무효참조 핸들이 생기는 경우를 최소화할 수 있습니다.
*/

#include <iostream>
#include <memory>


/* 1. const가 붙지 않은 참조자 반환이 위험한 이유 */
/* 점 */
class Point {
public:
	Point(int newX, int newY) : x(newX), y(newY){}

	void setX(int newVal) { x = newVal; }
	void setY(int newVal) { y = newVal; }
	int getX() const { return x; }
	int getY() const { return y; }
private:
	int x;
	int y;
};

/* 사각형 데이터 */
struct RectData {

	RectData(Point newUlhc, Point newLrhc) : ulhc(newUlhc), lrhc(newLrhc){}
	Point ulhc; //upper left-hand corner
	Point lrhc; //lower right-hand corner
};

/* 사각형 데이터를 가리키는 스마트 포인터 */
class Rectangle{
public:
	Rectangle(RectData *Rd1)
	{
		pData = std::shared_ptr<RectData>(new RectData(*Rd1)); // 힙 영역의 객체만 스마트 포인터로 사용 가능한듯
	}

	/* 좌상단, 우하단 점을 반환하는 함수 */
	/*
	참조자를 반환하면 내부 데이터를 마음대로 수정 가능하므로 적절하지 않은 방법
	Point & upperLeft() const { return pData->ulhc; }
	Point& lowerRight() const { return pData->lrhc; }
	*/
	Point upperLeft() const { return pData->ulhc; }
	Point lowerRight() const { return pData->lrhc; }

private:
	std::shared_ptr<RectData> pData;
};


/* 2. const가 붙은 참조자 반환이 위험한 이유 */
class GUIObject {
public:
	GUIObject(Rectangle newRec) : rec(newRec){}
	Rectangle getRec() const { return rec; }
private:
	Rectangle rec;
};

const Rectangle& boundingBox(const GUIObject& obj) // 임시 객체 또는 지역 객체의 참조자를 반환하면 빈 주소값만 남는다.
{
	return obj.getRec();
}
int main()
{
	Point p1(1, 2);
	Point p2(3, 4);
	RectData rd1(p1, p2);
	Rectangle r1(&rd1);
	std::cout << r1.lowerRight().getX() << std::endl;
	
	GUIObject gui1(r1);
	GUIObject *pgo = &gui1;

	const Point *pUpperLeft = &(boundingBox(*pgo).upperLeft());

	std::cout << pUpperLeft->getX() << std::endl;
}


