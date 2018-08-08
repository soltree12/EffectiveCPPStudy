#pragma once

#include <sstream>
#include "Lock.h"

class Image {
public:
	Image(std::istream& img) : i(img) {}
private:
	std::istream& i;
};

class PrettyMenu {
public:
	void ChangeBackground(std::istream& imgSrc);
private:
	Mutex mutex;
	std::shared_ptr<Image> bgImage;
	int imageChanges;
};


/*
올바른 구현 : 스마트포인터를 이용한 Lock클래스를 구현해 lock과 unlock을 대신 해주도록 만듬,
Image객체를 스마트포인터로 구현해 reset함수를 이용
*/
void PrettyMenu::ChangeBackground(std::istream& imgSrc)
{
	Lock m1(&mutex); //뮤텍스를 대신 획득하고 이것이 필요 없어질 시점에 바로 해제해 주는 객체

	bgImage.reset(new Image(imgSrc)); //bgImage의 내부 포인터를 "new Image" 표현식의 실행 결과로 바꿔치기합니다.

	++imageChanges;
}