#include <iostream>

/* 오류가 발생할 수 있는 설계*/
/*
class Date {
public:
	Date(int month, int day, int year) 
};
*/

/* 사용자의 실수를 막는 설계*/
struct Day {
	explicit Day(int d) : val(d){}
	int val;
};

struct Month {
	explicit Month(int m) : val(m){}
	int val;
};

struct Year {
	explicit Year(int y) : val(y){}
	int val;
};

class Date {
public:
	Date(const Month& m, const Day& d, const Year& y)
		:month(m.val),day(d.val),year(y.val){}
	void showDate()
	{
		std::cout << year << "/" << month << "/" << day << std::endl;
	}

private:
	unsigned int month;
	unsigned int year;
	unsigned int day;
};

class Month_C {
public:
	static Month Jan() { return Month(1); }
	static Month Feb() { return Month(2); }
	static Month Mar() { return Month(3); }
private:
	explicit Month_C(int m); // Month 값이 새로 생성되지 않도록 명시호출 생성자가 private 멤버입니다.
};

int main2()
{
	//Date d(3,29,1995) // Error
	Date d(Month(3), Day(20), Year(2018));

	Date d2(Month_C::Feb(), Day(21), Year(2018));

	d.showDate();
	d2.showDate();

	return 0;
}