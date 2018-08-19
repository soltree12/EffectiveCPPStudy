#pragma once
#include <iostream>
class Widget {
public:
	Widget(std::size_t newSize):_size(newSize){}
	virtual ~Widget(){}
	virtual std::size_t size() const
	{
		return _size;
	}
	virtual void normalize(){}
	void swap(Widget& other) {
		std::swap(other._size, _size);
	}

private:
	std::size_t _size;
};


/*
��ü���� ���α׷����� ���� :
����� �������̽� - w�� Widget �������̽��� �����ؾ���, �� �������̽��� �ҽ��ڵ�(.h���� ��)���� ã���� � ���������� Ȯ���� �� ����(�����)
��Ÿ�� ������ - ���� �Լ� ������ ����, ȣ���� ��Ÿ�� �� ������.
*/
void doProcessing(Widget& w)
{
	if (w.size() > 1) {
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
		std::cout << "temp::_size : " << temp.size()<<std::endl;
	}
};


/* 
���ø��� �Ϲ�ȭ ���α׷����� ���� :
�Ͻ��� �������̽� - ��ȿ ǥ������ ����(size,normalize,swap ��� �Լ��� ����(T Ÿ���� ��ü�� ���� '��ȿ'�ؾ���), ��������� ����, �ε� �񱳸� ���� ���굵 ����)
������ Ÿ�� ������ - w�� ���ݵǴ� �Լ� ȣ���� �Ͼ��(> ��) ȣ���� ������Ű�� ���� ���ø��� �ν��Ͻ�ȭ�� �Ͼ��.(������Ÿ�ӿ�)
*/
template<typename T>
void doProcessingTemplate(T& w)
{
	if (w.size() > 1)
	{
		T temp(w);
		temp.normalize();
		temp.swap(w);
		std::cout << "temp::_size : " << temp.size() << std::endl;
	}
}