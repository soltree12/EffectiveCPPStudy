/*
항목33) 상속된 이름을 숨기는 일은 피하자.
1. 파생 클래스의 이름은 기본 클래스의 이름을 가립니다. public 상속에서는 이런 이름 가림 현상은 바람직하지 않습니다.
2. 가려진 이름을 다시 볼 수 있게 하는 방법으로, using 선언 혹은 전달 함수를 쓸 수 있습니다.
*/

/* 1. 파생클래스의 함수 이름이 기본 클래스의 함수와 이름이 같으면
매개변수 타입이 다르든, 가상함수인지 비가상 함수인지의 여부에도 상관없이 전부 이름이 가려진다. */

class Base {
private:
	int x;
public:
	virtual void mf1() {};
	virtual void mf1(int) {} // 오버로드

	virtual void mf2() {}

	void mf3() {}
	void mf3(double) {} // 오버로드
};

class Derived : public Base {
public:
	/* 해결책1 : using 사용 */
	//using Base::mf1; // Base에 있는 것들 중 mf1과 mf3을 이름으로 가진 것들을 Derived의 유효범위에서 볼 수 있도록(또 public 멤버로) 만듭니다.
	//using Base::mf3;
	
	/* 해결책2 : 전달 함수 사용*/
	virtual void mf1() { Base::mf1(); } // 원하는 버전의 함수를 불러올 수 있음
	void mf3() {}
	void mf4() {}
};

int main()
{
	Derived d;
	int x=1;
	
	d.mf1(); // 좋습니다. Derived::mf1을 호출합니다.
	//d.mf1(x); // 에러입니다! Derived::mf1이 Base::mf1을 가립니다.

	d.mf2(); // 좋아요. Base::mf2를 호출합니다.

	d.mf3(); // 문제없습니다. Derived::mf3을 호출합니다.
	//d.mf3(x); // 에러입니다! Derived::mf3이 Base::mf3을 가립니다.
}