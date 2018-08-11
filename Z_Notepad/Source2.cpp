#include <functional>

using namespace std;
// bind의 _1, _2를 사용하기 위해 반드시 필요한 헤더
using namespace std::placeholders;

// 전방선언
class GameObject;

// 체력을 계산하는 기본 함수
int DefaultHealthCalc(const GameObject&) { return 10; }

// int가 아닌 short 타입을 반환하는 함수
short ShortHealthCalc(const GameObject&) { return 20; }

// 함수 객체
struct HealthCalcFunctor
{
public:
	int operator () (const GameObject&) const { return 30; }
};

// 멤버 함수용 클래스
class Health
{
public:
	int HealthClassFunc(const GameObject&) const { return 40; }
};

class GameObject
{
public:
	// function의 템플릿 인자는 다음과 같다.
	// <RET (N1, N2, ...)>
	// RET              : 반환 타입
	// N1, N2, ...      : 인자 타입들
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
	// 반환형이 short인 일반 함수
	GameObject ga(10, ShortHealthCalc);

	// 함수 객체 : 이와 같이 지역객체를 만든 후 사본을 넘겨야 한다.
	// GameObject gb(HealthCalcFunctor())처럼 직접 사용은 불가능하다.
	HealthCalcFunctor h;
	GameObject gb(10, h);

	// bind - 멤버 함수
	Health health;
	GameObject gc(10, bind(&Health::HealthClassFunc, health, _1));


	return 0;
}