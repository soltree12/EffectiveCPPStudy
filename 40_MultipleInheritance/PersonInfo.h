#pragma once
#include "DatabaseID.h"

static const int Max_Formatted_Field_Value_Length = 100;

/* �� Ŭ�������� IPerson �������̽��� �����ϴ� �� ������ �Լ��� ��� �ֽ��ϴ�. (������ ������ Ŭ������� ����) */
class PersonInfo {
public:
	explicit PersonInfo(DatabaseID pid, std::string name) : myPid(pid), myName(name){}

	virtual const char* theName() const;
	virtual const char* theBirthDate() const { return "101010"; }

private:
	/* �����ڸ� �ٿ��ִ� �Լ� exe => [exe] */
	virtual const char * valueDelimOpen() const;
	virtual const char * valueDelimClose() const;

	std::string myName;
	DatabaseID myPid;
};

const char * PersonInfo::valueDelimOpen() const
{
	return "[";
}
const char * PersonInfo::valueDelimClose() const
{
	return "]";
}

const char* PersonInfo::theName() const
{
	/* ��ȯ ���� ���� ���۸� ������ �Ӵϴ�. �� ���۴� ���� �޸��̱� ������, �ڵ����� 0���� �ʱ�ȭ�˴ϴ�. */
	static char value[Max_Formatted_Field_Value_Length];

	/* ���� �����ڸ� value�� ���ϴ�. */
	std::strcpy(value, valueDelimOpen());
	
	/* value�� ��� �ִ� ���ڿ��� �� ��ü�� name �ʵ带 �����Դϴ�. (���� �������� �Ͼ�� �ʵ��� �����ؾ� �մϴ�!) */
	std::strcat(value, myName.c_str());

	/* �� �����ڸ� value�� �߰��մϴ�. */
	std::strcat(value, valueDelimClose());

	return value;
}