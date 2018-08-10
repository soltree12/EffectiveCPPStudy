/*
�׸�32) public ��� ������ �ݵ�� "is-a(...�� ...�� �����̴�)"�� �������� ������.
1. public ����� �ǹ̴� "is-a(...�� ...�� ����)"�Դϴ�. �⺻ Ŭ������ ����Ǵ� ��� �͵��� �Ļ� Ŭ������ �״�� ����Ǿ�� �մϴ�. 
�ֳ��ϸ� ��� �Ļ� Ŭ���� ��ü�� �⺻ Ŭ���� ��ü�� �����̱� �����Դϴ�.
*/

#include <assert.h>

/* 1. public ����� is-a(~�� ~�� �����̴�)�� �ǹ��Ѵ�. */
class Person{};

class Student : public Person{};

void eat(const Person& p){} // �Դ� ���� ������ �մϴ�.
void study(const Student& s){} // �а� ���δ� �л��� �մϴ�.

/* 2. is-a ����� �⺻ Ŭ���� ��ü�� ���� '���' �͵��� �Ļ� Ŭ���� ��ü���� �״�� ����Ǵ� ���� �����Ѵ�. */
class Rectangle {
public:
	Rectangle(int newHeight, int newWidth) : theHeight(newHeight), theWidth(newWidth){}
	virtual void setHeight(int newHeight) { theHeight = newHeight; }
	virtual void setWidth(int newWidth) { theWidth = newWidth; }

	virtual int height() const {return theHeight;} // ������ ���� ��ȯ�մϴ�.
	virtual int width() const { return theWidth; }

private:
	int theHeight;
	int theWidth;
};

void makeBigger(Rectangle& r) // r�� ���̸� �ø��� �Լ�
{
	int oldHeight = r.height();
	r.setWidth(r.width() + 10);
	assert(r.height() == oldHeight); //������ ���̸� �Ѿ, �����̸� ���� ����� ����.(r�� ���� ���̰� ������ �ʴ´ٴ� ���ǿ� �������� �ɾ�Ӵϴ�.)
}

class Square : public Rectangle {
public:
	Square(int newLength) : Rectangle(newLength,newLength){}
};

int main()
{
	/*1*/
	Person p; // p�� Person�� �����Դϴ�.(����� ����̴ϱ�)
	Student s; // s�� Student�� �����Դϴ�.(�л��� �л��̴ϱ�)

	eat(p); // ���������ϴ�. p�� Person�̴ϱ��.
	eat(s); // ���������ϴ�. s�� Student�̰�, Student�� Person�� �����̴ϱ��.

	study(s); // �����ϴ�.
	//study(p); // �����Դϴ�! p�� Student�� �ƴմϴ�.

	/*2*/
	Square sq(10);
	assert(sq.width() == sq.height());// �� �������� ��� ���簢���� ���� ���̾�� �մϴ�.
	makeBigger(sq); // ��ӵ� ���̹Ƿ�, s�� Rectangle�� �����Դϴ�. ��, s�� ���̸� �ø� �� �ֽ��ϴ�.
	//assert(sq.width() == sq.height()); // �̹����� �� �������� ��� ���簢���� ���� ���̾�� �մϴ�.(������ ����!) 
	/* ���簢���� ����(���� ���̰� ���� ���̿� ��� ���� �ٲ� �� �ֽ��ϴ�.)�� ���簢��(���ο� ���� ���̰� ���ƾ� �մϴ�.)�� ������ �� �����ϴ�.*/

}