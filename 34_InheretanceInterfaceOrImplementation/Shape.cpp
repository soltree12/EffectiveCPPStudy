/*
�׸� 34) �������̽� ��Ӱ� ���� ����� ���̸� ����� �ľ��ϰ� ��������.
1. �������̽� ����� ���� ��Ӱ� �ٸ��ϴ�. public ��ӿ���, �Ļ� ũ������ �׻� �⺻ Ŭ������ �������̽��� ��� �����޽��ϴ�.
2. ���� ���� �Լ��� �������̽� ��Ӹ��� ����մϴ�.
3. �ܼ�(�����) ���� �Լ��� �������̽� ��Ӱ� ���Ҿ� �⺻ ������ ��ӵ� �����ϵ��� �����˴ϴ�.
4. �񰡻� �Լ��� �������̽� ��Ӱ� ���Ҿ� �ʼ� ������ ��ӵ� ���ϵ��� �����մϴ�.
*/

#include<iostream>
#include <string>
class Shape {
public:

	/*
	1. ���� ���� �Լ��� �����ϴ� ������ �Ļ�Ŭ�������� �Լ��� �������̽����� �����ַ��� ���Դϴ�.
	" draw �Լ��� �������� ���� �����ϵ��� �Ͻÿ�. ������ ����� ��� ���������� ���ؼ� �� �ƹ� ���� ����. "
	*/
	virtual void draw() const = 0;

	/*
	2. �ܼ� ���� �Լ��� �����ϴ� ������ �Ļ� Ŭ������ �Ͽ��� �Լ��� �������̽��Ӹ� �ƴ϶� �� �Լ��� �⺻ ������ �����ް� ���ڴ� ���Դϴ�.
	"error �Լ��� �������� �����ؾ� �Ѵٿ�. �׷��� ���� ���� ���� ������ ���ٸ� Shape Ŭ������ �ִ� �⺻ ������ �׳� ���ñ���."
	*/
	virtual void error(const std::string& msg) { std::cout << "Shape::error" << std::endl; }

	/*
	3. �񰡻� �Լ��� �����ϴ� ������ �Ļ� Ŭ������ �Լ� �������̽��� ���Ҿ� �� �Լ��� �ʼ����� ������ �����ް� �ϴ� ���Դϴ�.
	"Shape �� �̰Ϳ��� �Ļ��� ��� ��ü�� ��ü�� �ĺ��ڸ� ���� �ִ� �Լ��� ���� �ǰ���. ��ü �ĺ��ڸ� ����ϴ� ����� �׻� �Ȱ��ڱ�.
	���� ��� ����� Shape::objectID�� ���ǿ��� �����ǰ�, �Ļ� Ŭ������ �̰��� �ٲ� �� ���ڴ°�."
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
	//Shape *ps = new Shape; //����! Shape�� �߻� Ŭ�����Դϴ�.

	Shape *ps1 = new Rectangle;
	ps1->draw();

	Shape *ps2 = new Ellipse;
	ps2->draw();

	ps1->Shape::draw(); // Shape::draw�� ȣ���մϴ�.(������ ���� ���� �����Լ� ȣ���ϱ�)
	ps2->Shape::draw(); 
}