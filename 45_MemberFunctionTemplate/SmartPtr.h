#pragma once

class Top {};
class Middle :public Top {};
class Bottom : public Middle {};

template<typename T>
class SmartPtr {
public:
	//template<typename U>
	//SmartPtr(const smartPtr<U>& other); // �Ϲ�ȭ�� ���� �����ڸ� ����� ���� ������ ��� ���ø�
	//��� T Ÿ�� �� ��� U Ÿ�Կ� ���ؼ�, SmartPtr<T> ��ü�� SmartPtr<U>�κ��� ������ �� �ִ�.
	//(������ : ��� ��ȯ�� �����ϱ� ������ Top->Bottom��ȯ(public ��ӿ� ����),int->double�� ���� ��ȯ�� ���� �������� ���� ��ȯ�� �����ų �� �ִ�.
	
	/* �ذ�å : T�� ��ȯ�ϴ� get�Լ��� ����� U�� ���ö� T�� �Ͻ��� ��ȯ�� ������ ���� �������� �Ѵ�.  */
	template<typename U>
	SmartPtr(const SmartPtr<U>& other) : heldPtr(other.get()){}
	SmartPtr(T* p) : heldPtr(p){}
	T* get() const { return heldPtr; } // T�� �Ͻ��� ��ȯ�� ������ �����϶��� ��ȯ�ȴ�.
	
private:
	T * heldPtr;
};