/*
�׸�21) �Լ����� ��ü�� ��ȯ�ؾ� �� ��쿡 �����ڸ� ��ȯ�Ϸ��� ���� ����.
1. ���� ���� ��ü�� ���� �����ͳ� �����ڸ� ��ȯ�ϴ� ��, Ȥ�� ���� �Ҵ�� ��ü�� ���� �����ڸ� ��ȯ�ϴ� ��, �Ǵ� ���� ���� ��ü�� ���� �����ͳ� �����ڸ� ��ȯ�ϴ� ����
�׷� ��ü�� �� �� �̻� �ʿ����� ���ɼ��� �ִٸ� ����� ���� ������.(�׸� 4�� ���ø� ���� ���� ��ü�� ���� �����ڸ� ��ȯ�ϵ��� ����� �ùٸ� �ڵ� ������ ã�� �� �ֽ��ϴ�.
�ּ��� ���� ������ ȯ�濡���� ���մϴ�.
*/

#include <iostream>

class Rational {
public:
	Rational(int numerator = 0, int dominator = 1) : n(numerator), d(dominator){}
	friend void showRational(const Rational& rat);
private:
	int n, d;

	friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};

/*
�����ڴ� '�����ϴ�' ��ü�� �ٴ� �ٸ� �̸�
=> �Լ� ���� ���ο� ��ü�� �������� ������ ������ ��ȯ �Ұ���
=> ����� 3��, ���ο� ��ü�� ���ÿ� ����ų�, ���� ����ų�, ���� ��ü�� �Լ� �ȿ� �����ϰų�
1) ����
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
	Rational result(lhs.n*rhs.n, lhs.d*rhs.d);
	return result;
}
=> �Լ��� ������ ��ü�� �Ҹ�ǹǷ� ���Ұ�

2) ��
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
Rational *result = new Rational(lhs.n*rhs.n, lhs.d*rhs.d);
return result;
}
=> delete�� ���� ���ٱ�? (�޸� ���� ����) 

3) ���� ��ü
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
static Rational result;
result = ....
return result;
}
=> static ��ü�� �ϳ��ۿ� �������� �����Ƿ� ���ο� ������ ������ ���� ����� ������. 
*/

/* �ùٸ� ��� */
inline const Rational operator* (const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}


int main()
{
	Rational a(1, 3);
	Rational b(2, 5);
	showRational(a*b);
}


void showRational(const Rational& rat)
{
	std::cout << rat.n << "/" << rat.d << std::endl;
}