/*
�׸�6) �����Ϸ��� ���� �Լ��� �ʿ� ������ Ȯ���� �̵��� ����� ���� ������.
1. �����Ϸ����� �ڵ����� �����ϴ� ���(�Ͻ��� ���� ������, �Ͻ��� ���� ���� ������ ��)�� ���ġ ��������,
�����Ǵ� ��� �Լ��� private�� ������ �Ŀ� ������ ���� ���� ä�� �νʽÿ�.
Uncopyable�� ����� �⺻ Ŭ������ ���� �͵� �� ����Դϴ�.
*/

class Uncopyable {
protected:
	Uncopyable() {}
	~Uncopyable() {}

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator =(const Uncopyable&);
};

class HomeForSale : private Uncopyable
{
public:
private:
};

int main()
{
	HomeForSale home1;
	HomeForSale home2;
	//HomeForSale home3(home1); // ���� �����ڸ� ������
	//home2 = home1; //���� ���� �����ڸ� ������
	return 0;
}