#pragma once
/* shared_ptr�� ȣȯ�Ǵ� ��� �⺻����������, tr1::shared_ptr, auto_ptr, tr1::weak_ptr ��ü��κ��� ������ ȣ���� �����ѵ��ٰ�,
�̵� �� tr1::weak_ptr�� ������ �������� ���� ���꿡 �� �� �ֵ��� ������� �ִ�.*/
template<class T> class shared_ptr {
public:
	template<class Y>
	explicit shared_ptr(Y *p); // ȣȯ�Ǵ� ��� �⺻���� ������, shared_ptr, weak_ptr Ȥ�� auto_ptr ��ü�κ��� ������ ȣ���� �����մϴ�.

	shared_ptr(shared_ptr const& r); //"������" ���� ������
	shared_ptr& operator(shared_ptr const& r); //"������" ���� ���� ������

	template<class Y>
	explicit shared_ptr(shared_ptr<Y> const& r); //�Ϲ�ȭ ���� ������
	template<class Y>
	explicit shared_ptr(weak_ptr<Y> const& r);
	template<class Y>
	explicit shared_ptr(auto_ptr<Y>& r);
	template<class Y>
	explicit shared_ptr(shared_ptr<Y> const &r); // ȣȯ�Ǵ� ��� shared_ptr Ȥ�� auto_ptr�κ��� ������ �����մϴ�.
	template<class Y>
	explicit shared_ptr(auto_ptr<Y>& r);
};