#pragma once

#include <memory>
#include <iostream>
#include "Lock.h"
/*
복사후 바꿔넣기(copy-and-swap) : 어떤 객체를 수정하고 싶으면 그 객체의 사본을 하나 만들어 놓고 그 사본을 수정하는 것입니다.
이렇게 하면 수정 동작 중에 실행되는 연산에서 예외가 던져지더라도 원본 객체는 바뀌지 않은 채로 남는 거죠. 필요한 동작이 전부 성공적으로
완료되고 나면 수정된 객체를 원본 객체와 맞바꾸는데, 이 작업을 '예외를 던지지 않는' 연산 내부에서 수행합니다.
*/

class Image {
public:
	Image(std::istream& img) : i(img) {}
private:
	std::istream& i;
};


struct PMImpl { // '진짜' 객체의 모든 데이터를 별도의 구현 객체에 넣어둠
	std::shared_ptr<Image> bgImage;
	int imageChanges;
};

class PrettyMenu {
public:
	void ChangeBackground(std::istream& imgSrc);
private:
	Mutex mutex;
	std::shared_ptr<PMImpl> pImpl; // 그 구현 객체를 가리키는 포인터
};

void PrettyMenu::ChangeBackground(std::istream& imgSrc)
{
	using std::swap;
	Lock m1(&mutex);

	std::shared_ptr<PMImpl>pNew(new PMImpl(*pImpl)); // 객체의 데이터 부분을 복사합니다.

	pNew->bgImage.reset(new Image(imgSrc)); //사본을 수정합니다.
	++pNew->imageChanges;
	swap(pImpl, pNew); // 새 데이터로 바꿔 넣어 진짜로 배경그림을 바꿉니다.
	std::cout << "Image Changed" << std::endl;
}