#pragma once
/* shared_ptr은 호환되는 모든 기본제공포인터, tr1::shared_ptr, auto_ptr, tr1::weak_ptr 객체들로부터 생성자 호출이 가능한데다가,
이들 중 tr1::weak_ptr을 제외한 나머지를 대입 연산에 쓸 수 있도록 만들어져 있다.*/
template<class T> class shared_ptr {
public:
	template<class Y>
	explicit shared_ptr(Y *p); // 호환되는 모든 기본제공 포인터, shared_ptr, weak_ptr 혹은 auto_ptr 객체로부터 생성자 호출이 가능합니다.

	shared_ptr(shared_ptr const& r); //"보통의" 복사 생성자
	shared_ptr& operator(shared_ptr const& r); //"보통의" 복사 대입 연산자

	template<class Y>
	explicit shared_ptr(shared_ptr<Y> const& r); //일반화 복사 생성자
	template<class Y>
	explicit shared_ptr(weak_ptr<Y> const& r);
	template<class Y>
	explicit shared_ptr(auto_ptr<Y>& r);
	template<class Y>
	explicit shared_ptr(shared_ptr<Y> const &r); // 호환되는 모든 shared_ptr 혹은 auto_ptr로부터 대입이 가능합니다.
	template<class Y>
	explicit shared_ptr(auto_ptr<Y>& r);
};