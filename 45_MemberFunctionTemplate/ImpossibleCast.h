#pragma once

class Top{};
class Middle :public Top {};
class Bottom : public Middle{};

template<typename T>
class SmartPtr {
public:
	explicit SmartPtr(T *realPtr) {} // ����Ʈ �����ʹ� �밳 �⺻���� �����ͷ� �ʱ�ȭ�˴ϴ�.
};

void func()
{
	//����Ʈ�����ʹ� �Ͻ��� ��ȯ�� �Ұ����մϴ�.
	/*
	SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle); // SmartPtr<Middle>=>SmartPtr<Top>�� ��ȯ
	SmartPtr<Top> pt2 = SmartPtr<Bottom>(new Bottom);
	SmartPtr<const Top> pct2 = pt1;
	*/ 
}