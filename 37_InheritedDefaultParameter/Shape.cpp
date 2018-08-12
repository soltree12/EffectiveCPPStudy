/*
�׸� 37) � �Լ��� ���ؼ��� ��ӹ��� �⺻ �Ű����� ���� ����� ���������� ����
1. ��ӹ��� �⺻ �Ű����� ���� ����� �������ؼ��� �� �˴ϴ�. �ֳ��ϸ� �⺻ �Ű����� ���� �������� ���ε��Ǵ� �ݸ�, ���� �Լ�(�������� �������̵��� �� �ִ� ������ �Լ�����)��
�������� ���ε��Ǳ� �����Դϴ�.
*/

#include <iostream>

class Shape
{
public:
	enum ShapeColor { Red, Green, Blue};
	// ��� ������ �ڱ� �ڽ��� �׸��� �Լ��� �����ؾ� �մϴ�.
	virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle : public Shape {
public:
	// �⺻ �Ű����� ���� �޶��� �κ��� ��ġ�� ������. ū�� �������ϴ�!
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
�ذ�å : �񰡻� �������̽� ���뱸(NVI ���뱸)�� ��� 
��ó�� �����ϸ� draw �Լ��� color �Ű������� ���� �⺻���� ����ϰ� Red�� ������ų �� �ֽ��ϴ�.	
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
	virtual void doDraw(ShapeColor color) const // �⺻ �Ű����� ���� �����ϴ�. �� ������.
	{
		std::cout << "Rectangle::draw / ShapeColor : " << color << std::endl;
	}
};


int main()
{ 
	Shape *ps; // ���� Ÿ�� = Shape*
	Shape *pc = new Circle; // ���� Ÿ�� = Shape*
	Shape *pr = new Rectangle; // ���� Ÿ�� = Shape*

	ps = pc; // ps�� ���� Ÿ���� ���� Circle*�� �˴ϴ�.
	ps = pr; // ps�� ���� Ÿ���� ���� Rectangle*�� �˴ϴ�.

	 /* ���� �Լ��� �������� ���ε� �� */
	pc->draw(Shape::Red); // Circle::draw(Shape::Red)�� ȣ���մϴ�.
	ps->draw(Shape::Red); // Rectangle::draw(Shape::Red)�� ȣ���մϴ�.

	/* �⺻ �Ű������� �������� ���ε� �� */
	pr->draw(); // (Rectangle::draw(Shape::Green)�� ȣ���ϱ⸦ �ٶ�����) Rectangle::draw(Shape::Red)�� ȣ���Ѵ� ���Դϴ�!

	/* �ذ�å ���� */
	Shape_NVI *pr_NVI = new Rectangle_NVI;
	pr_NVI->draw();

	return 0;
}