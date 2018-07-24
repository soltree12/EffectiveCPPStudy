/*
항목6) 컴파일러가 만들어낸 함수가 필요 없으면 확실히 이들의 사용을 금해 버리자.
1. 컴파일러에서 자동으로 제공하는 기능(암시적 복사 생성자, 암시적 복사 대입 연산자 등)을 허용치 않으려면,
대응되는 멤버 함수를 private로 선언한 후에 구현은 하지 않은 채로 두십시오.
Uncopyable과 비슷한 기본 클래스를 쓰는 것도 한 방법입니다.
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
	//HomeForSale home3(home1); // 복사 생성자를 막았음
	//home2 = home1; //복사 대입 연산자를 막았음
	return 0;
}