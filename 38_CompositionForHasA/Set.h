#pragma once
#include <list>
#include <iostream>
/* set 템플릿을 List에서 파생된 형태로부터 만들기 : Set은 List의 (is implemented in terms of)의 관계임*/
template<class T>
class Set {
public:
	bool member(const T& item) const;
	void insert(const T& item);
	void remove(const T& item);
	std::size_t size() const;

private:
	std::list<T> rep; // Set 데이터의 내부 표현부
};


template<typename T>
bool Set<T>::member(const T& item) const
{
	return std::find(rep.begin(), rep.end(), item) != rep.end();
}

template<typename T>
void Set<T>::insert(const T& item)
{
	if (!member(item)) rep.push_back(item);
}

template<typename T>
void Set<T>::remove(const T& item)
{
	typename std::list<T>::iterator it = std::find(rep.begin(), rep.end(), item); // 항목 42에서 설명

	if (it != rep.end()) rep.erase(it);
}

template<typename T>
std::size_t Set<T>::size() const
{
	return rep.size();
}

