#pragma once

#include <sstream>

class Mutex {

};

void lock(Mutex *pm) {}

void unlock(Mutex *pm) {}

class Image {
public:
	Image(std::istream& img) : i(img) {}
private:
	std::istream& i;
};

class PrettyMenu
{
public:
	void ChangeBackground(std::istream& imgSrd); // 배경그림을 바꾸는 멤버함수

private:
	Mutex mutex; // 이 객체 하나를 위한 뮤텍스

	Image *bgImage; // 현재의 배경그림
	int imageChanges; // 배경그림이 바뀐 횟수
};

/*
잘못된 구현
new Image(imgSrc)에서 예외를 던지면
1. unlock함수가 실행되지 않아 뮤텍스가 계속 잡힌 상태로 남는다.(자원이 샌다.)
2. imgChange변수는 증가되는데 이미지가 변경되지 않는다.(자료구조가 더럽혀진다.)
*/

void PrettyMenu::ChangeBackground(std::istream& imgSrc)
{
	lock(&mutex); // 뮤텍스를 획득합니다.

	delete bgImage; // 이전의 배경그림을 없앱니다.
	++imageChanges; // 그림 변경 횟수를 갱신합니다.
	bgImage = new Image(imgSrc); // 새 배경그림을 깔아 놓습니다.

	unlock(&mutex); // 뮤텍스를 해제합니다.
}

