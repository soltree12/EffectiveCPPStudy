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
	void ChangeBackground(std::istream& imgSrd); // ���׸��� �ٲٴ� ����Լ�

private:
	Mutex mutex; // �� ��ü �ϳ��� ���� ���ؽ�

	Image *bgImage; // ������ ���׸�
	int imageChanges; // ���׸��� �ٲ� Ƚ��
};

/*
�߸��� ����
new Image(imgSrc)���� ���ܸ� ������
1. unlock�Լ��� ������� �ʾ� ���ؽ��� ��� ���� ���·� ���´�.(�ڿ��� ����.)
2. imgChange������ �����Ǵµ� �̹����� ������� �ʴ´�.(�ڷᱸ���� ����������.)
*/

void PrettyMenu::ChangeBackground(std::istream& imgSrc)
{
	lock(&mutex); // ���ؽ��� ȹ���մϴ�.

	delete bgImage; // ������ ���׸��� ���۴ϴ�.
	++imageChanges; // �׸� ���� Ƚ���� �����մϴ�.
	bgImage = new Image(imgSrc); // �� ���׸��� ��� �����ϴ�.

	unlock(&mutex); // ���ؽ��� �����մϴ�.
}

