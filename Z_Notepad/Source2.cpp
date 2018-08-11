#include <functional>

using namespace std;
// bind�� _1, _2�� ����ϱ� ���� �ݵ�� �ʿ��� ���
using namespace std::placeholders;

// ���漱��
class GameObject;

// ü���� ����ϴ� �⺻ �Լ�
int DefaultHealthCalc(const GameObject&) { return 10; }

// int�� �ƴ� short Ÿ���� ��ȯ�ϴ� �Լ�
short ShortHealthCalc(const GameObject&) { return 20; }

// �Լ� ��ü
struct HealthCalcFunctor
{
public:
	int operator () (const GameObject&) const { return 30; }
};

// ��� �Լ��� Ŭ����
class Health
{
public:
	int HealthClassFunc(const GameObject&) const { return 40; }
};

class GameObject
{
public:
	// function�� ���ø� ���ڴ� ������ ����.
	// <RET (N1, N2, ...)>
	// RET              : ��ȯ Ÿ��
	// N1, N2, ...      : ���� Ÿ�Ե�
	typedef tr1::function<int(const GameObject&)> HealthCalcFunc;

	explicit GameObject(int newHealth, HealthCalcFunc hcf = DefaultHealthCalc)
		: theHealth(newHealth), m_healthCalcFunc(hcf)
	{}

	int GetHealth() const { return m_healthCalcFunc(*this); }

private:
	HealthCalcFunc m_healthCalcFunc;
	int theHealth;
};

int main()
{
	// ��ȯ���� short�� �Ϲ� �Լ�
	GameObject ga(10, ShortHealthCalc);

	// �Լ� ��ü : �̿� ���� ������ü�� ���� �� �纻�� �Ѱܾ� �Ѵ�.
	// GameObject gb(HealthCalcFunctor())ó�� ���� ����� �Ұ����ϴ�.
	HealthCalcFunctor h;
	GameObject gb(10, h);

	// bind - ��� �Լ�
	Health health;
	GameObject gc(10, bind(&Health::HealthClassFunc, health, _1));


	return 0;
}