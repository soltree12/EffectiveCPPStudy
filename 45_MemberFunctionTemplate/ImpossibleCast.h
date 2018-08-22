#pragma once

class Top{};
class Middle :public Top {};
class Bottom : public Middle{};

template<typename T>
class SmartPtr {
public:
	explicit SmartPtr(T *realPtr) {} // 스마트 포인터는 대개 기본제공 포인터로 초기화됩니다.
};

void func()
{
	//스마트포인터는 암시적 변환이 불가능합니다.
	/*
	SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle); // SmartPtr<Middle>=>SmartPtr<Top>의 변환
	SmartPtr<Top> pt2 = SmartPtr<Bottom>(new Bottom);
	SmartPtr<const Top> pct2 = pt1;
	*/ 
}