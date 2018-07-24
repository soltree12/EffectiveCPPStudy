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
2. �����ڿ�����, ������ ����� ���� ���Թ��� ������ ���� ���ο� �ִ� ������� ����� �ʱ�ȭ���� ����, ��� �ʱ�ȭ ����Ʈ�� ��� ����սô�.
�׸��� ������ ����� ������ ���� Ŭ������ �� ������ ����� ����� ������ �Ȱ��� �����սô�.
*/
ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
	: theName(name),
	theAddress(address),
	thePhones(phones),
	numTimesConsulted(0)
{}
