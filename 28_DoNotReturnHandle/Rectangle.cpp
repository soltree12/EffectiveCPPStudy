/*
�׸�28) ���ο��� ����ϴ� ��ü�� ���� '�ڵ�'�� ��ȯ�ϴ� �ڵ�� �ǵ��� ������.
1. � ��ü�� ���ο�ҿ� ���� �ڵ�(������, ������, �ݺ���)�� ��ȯ�ϴ� ���� �ǵ��� ���ϼ���. ĸ��ȭ ������ ���̰�,
��� ��� �Լ��� ��ü�� ������� ������ ä�� ������ �� �ֵ��� �Ͽ�, ��ȿ���� �ڵ��� ����� ��츦 �ּ�ȭ�� �� �ֽ��ϴ�.
*/

#include <iostream>
#include <memory>


/* 1. const�� ���� ���� ������ ��ȯ�� ������ ���� */
/* �� */
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

/* �簢�� ������ */
struct RectData {

	RectData(Point newUlhc, Point newLrhc) : ulhc(newUlhc), lrhc(newLrhc){}
	Point ulhc; //upper left-hand corner
	Point lrhc; //lower right-hand corner
};

/* �簢�� �����͸� ����Ű�� ����Ʈ ������ */
class Rectangle{
public:
	Rectangle(RectData *Rd1)
	{
		pData = std::shared_ptr<RectData>(new RectData(*Rd1)); // �� ������ ��ü�� ����Ʈ �����ͷ� ��� �����ѵ�
	}

	/* �»��, ���ϴ� ���� ��ȯ�ϴ� �Լ� */
	/*
	�����ڸ� ��ȯ�ϸ� ���� �����͸� ������� ���� �����ϹǷ� �������� ���� ���
	Point & upperLeft() const { return pData->ulhc; }
	Point& lowerRight() const { return pData->lrhc; }
	*/
	Point upperLeft() const { return pData->ulhc; }
	Point lowerRight() const { return pData->lrhc; }

private:
	std::shared_ptr<RectData> pData;
};


/* 2. const�� ���� ������ ��ȯ�� ������ ���� */
class GUIObject {
public:
	GUIObject(Rectangle newRec) : rec(newRec){}
	Rectangle getRec() const { return rec; }
private:
	Rectangle rec;
};

const Rectangle& boundingBox(const GUIObject& obj) // �ӽ� ��ü �Ǵ� ���� ��ü�� �����ڸ� ��ȯ�ϸ� �� �ּҰ��� ���´�.
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


