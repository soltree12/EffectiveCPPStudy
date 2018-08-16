#pragma once
#include "IPerson.h"
#include "PersonInfo.h"

class CPerson : public IPerson, private PersonInfo { // ������. MI�� �������ϴ�.(PersonInfo�� �Լ��� �̿��� ����)
public:
	explicit CPerson(DatabaseID pid, std::string name) : PersonInfo(pid, name){}

	virtual std::string name() const
	{
		return PersonInfo::theName();
	}

	virtual std::string birthDate() const
	{
		return PersonInfo::theBirthDate();
	}

private:
	const char* valueDelimOpen() const { return ""; }
	const char* valueDelimClose() const { return ""; }

};