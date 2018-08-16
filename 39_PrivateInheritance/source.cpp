/*
항목 39) private 상속은 심사숙고해서 구사하자
1. private 상속의 의미는 is-implemented-in-terms-of(~는 ~를 써서 구현됨)입니다. 대개 객체 합성과 비교해서 쓰이는 분야가 많지는 않지만, 파생 클래스 쪽에서
기본 클래스의 protected 멤버에 접근해야 할 경우 혹은 상속받은 가상 함수를 재정의해야 할 경우에는 private 상속이 나름대로 의미가 있습니다.
2. 객체 합성과 달리, private 상속은 공백 기본 클래스 최적화(EBO)를 활성화시킬 수 있습니다. 이 점은 객체 크기를 가지고 고민하는 라이브러리 개발자에게
꽤 매력적인 특징이 되기도 합니다.
*/
/*
private 상속 
1. 기본 클래스로부터 물려받은 것들이 전부 파생 클래스에서 private 멤버가 된다.
2. 구현만 물려받을 수 있다. 인터페이스는 국물도 없다. (기본클래스의 함수나 멤버를 파생클래스 내부에서 사용할 때 이용)
*/

#pragma once
class Person {};
class Student :private Person {}; // 이젠 private 상솓입니다.

void eat(const Person& p) {} // 누구라도 사람은 먹을 수 있습니다.

void study(const Student& s) {} // 공부는 학생만 할 수 있습니다.

int main()
{
	Person p; // p는 person의 일종입니다.
	Student s; // s는 student의 일종입니다.

	eat(p); // 좋습니다. p는 Person의 일종이니까요.
	eat(s); // 에러! Student는 Person의 일종이 아닙니다. (private 상속이기 때문)
}