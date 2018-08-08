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
�ùٸ� ���� : ����Ʈ�����͸� �̿��� LockŬ������ ������ lock�� unlock�� ��� ���ֵ��� ����,
Image��ü�� ����Ʈ�����ͷ� ������ reset�Լ��� �̿�
*/
void PrettyMenu::ChangeBackground(std::istream& imgSrc)
{
	Lock m1(&mutex); //���ؽ��� ��� ȹ���ϰ� �̰��� �ʿ� ������ ������ �ٷ� ������ �ִ� ��ü

	bgImage.reset(new Image(imgSrc)); //bgImage�� ���� �����͸� "new Image" ǥ������ ���� ����� �ٲ�ġ���մϴ�.

	++imageChanges;
}