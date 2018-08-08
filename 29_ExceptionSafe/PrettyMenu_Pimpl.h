#pragma once

#include <memory>
#include <iostream>
#include "Lock.h"
/*
������ �ٲ�ֱ�(copy-and-swap) : � ��ü�� �����ϰ� ������ �� ��ü�� �纻�� �ϳ� ����� ���� �� �纻�� �����ϴ� ���Դϴ�.
�̷��� �ϸ� ���� ���� �߿� ����Ǵ� ���꿡�� ���ܰ� ���������� ���� ��ü�� �ٲ��� ���� ä�� ���� ����. �ʿ��� ������ ���� ����������
�Ϸ�ǰ� ���� ������ ��ü�� ���� ��ü�� �¹ٲٴµ�, �� �۾��� '���ܸ� ������ �ʴ�' ���� ���ο��� �����մϴ�.
*/

class Image {
public:
	Image(std::istream& img) : i(img) {}
private:
	std::istream& i;
};


struct PMImpl { // '��¥' ��ü�� ��� �����͸� ������ ���� ��ü�� �־��
	std::shared_ptr<Image> bgImage;
	int imageChanges;
};

class PrettyMenu {
public:
	void ChangeBackground(std::istream& imgSrc);
private:
	Mutex mutex;
	std::shared_ptr<PMImpl> pImpl; // �� ���� ��ü�� ����Ű�� ������
};

void PrettyMenu::ChangeBackground(std::istream& imgSrc)
{
	using std::swap;
	Lock m1(&mutex);

	std::shared_ptr<PMImpl>pNew(new PMImpl(*pImpl)); // ��ü�� ������ �κ��� �����մϴ�.

	pNew->bgImage.reset(new Image(imgSrc)); //�纻�� �����մϴ�.
	++pNew->imageChanges;
	swap(pImpl, pNew); // �� �����ͷ� �ٲ� �־� ��¥�� ���׸��� �ٲߴϴ�.
	std::cout << "Image Changed" << std::endl;
}