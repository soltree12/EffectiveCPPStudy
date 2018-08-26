#pragma once

class Top {};
class Middle :public Top {};
class Bottom : public Middle {};

template<typename T>
class SmartPtr {
public:
	//template<typename U>
	//SmartPtr(const smartPtr<U>& other); // 일반화된 복사 생성자를 만들기 위해 마련한 멤버 템플릿
	//모든 T 타입 및 모든 U 타입에 대해서, SmartPtr<T> 객체가 SmartPtr<U>로부터 생성될 수 있다.
	//(문제점 : 모든 변환이 가능하기 때문에 Top->Bottom변환(public 상속에 위배),int->double과 같은 변환과 같은 적절하지 않은 변환도 통과시킬 수 있다.
	
	/* 해결책 : T를 반환하는 get함수를 만들어 U가 들어올때 T가 암시적 변환이 가능할 때만 나가도록 한다.  */
	template<typename U>
	SmartPtr(const SmartPtr<U>& other) : heldPtr(other.get()){}
	SmartPtr(T* p) : heldPtr(p){}
	T* get() const { return heldPtr; } // T로 암시적 변환이 가능한 형태일때만 반환된다.
	
private:
	T * heldPtr;
};