#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class CTextBlock {
public:
	std::size_t length() const;
	CTextBlock(const char *str)
	{
		text = str;
	}
	// const(반환 값 상수) char& oprator[] (const(매개변수 상수) std::size_t position) const(멤버 변수 상수)
	const char& operator[] (const std::size_t position) const
	{
		return text[position];
	}
	char& operator[] (std::size_t position) // 중복 코드 피하기 위해 비상수 멤버함수가 상수 멤버함수 호출
	{
		return const_cast<char&>(
			static_cast<const CTextBlock&>(*this)[position]
			);
	}


private:
	std::string text;
	mutable std::size_t textLength;
	mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const
{
	if (!lengthIsValid)
	{
		textLength = text.length();
		lengthIsValid = true;
	}

	return textLength;
}

int& getNumber(int& num) // test for reference
{
	num++;
	return num;
}

int main()
{
	// const test
	const char *pt = "hellrffsfo";
	CTextBlock ctb(pt);
	ctb[0] = 'c';
	std::cout << ctb[3] << endl;


	// test for reference
	int a = 3;
	int b = getNumber(a);
	b += 100;
	cout << a << endl;
	return 0;
}