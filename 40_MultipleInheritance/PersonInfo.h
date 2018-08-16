#pragma once
#include "DatabaseID.h"

static const int Max_Formatted_Field_Value_Length = 100;

/* 이 클래스에는 IPerson 인터페이스를 구현하는 데 유용한 함수가 들어 있습니다. (기존에 만들어둔 클래스라고 가정) */
class PersonInfo {
public:
	explicit PersonInfo(DatabaseID pid, std::string name) : myPid(pid), myName(name){}

	virtual const char* theName() const;
	virtual const char* theBirthDate() const { return "101010"; }

private:
	/* 구분자를 붙여주는 함수 exe => [exe] */
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
	/* 반환 값을 위한 버퍼를 예약해 둡니다. 이 버퍼는 정적 메모리이기 때문에, 자동으로 0으로 초기화됩니다. */
	static char value[Max_Formatted_Field_Value_Length];

	/* 시작 구분자를 value에 씁니다. */
	std::strcpy(value, valueDelimOpen());
	
	/* value에 들어 있는 문자열에 이 객체의 name 필드를 덧붙입니다. (버퍼 오버런이 일어나지 않도록 주의해야 합니다!) */
	std::strcat(value, myName.c_str());

	/* 끝 구분자를 value에 추가합니다. */
	std::strcat(value, valueDelimClose());

	return value;
}