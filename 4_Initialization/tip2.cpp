#include <string>
#include <list>
class PhoneNumber
{
private:
	std::string number;
};

class ABEntry
{
public:
	ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones);

private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

/*
2. 생성자에서는, 데이터 멤버에 대한 대입문을 생성자 본문 내부에 넣는 방법으로 멤버를 초기화하지 말고, 멤버 초기화 리스트를 즐겨 사용합시다.
그리고 데이터 멤버를 나열할 때는 클래스에 각 데이터 멤버가 선언된 순서와 똑같이 나열합시다.
*/
ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
	: theName(name),
	theAddress(address),
	thePhones(phones),
	numTimesConsulted(0)
{}
