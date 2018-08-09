/* ���� ������(���丮 �Լ�)�� ���� cpp���� ���� ����(�Ļ� Ŭ������ Include�ؾ��ϱ� �����ε�) */

#include "PersonInterface.h"
#include "RealPerson.h"

std::shared_ptr<PersonInterface> PersonInterface::create(const std::string& name, const Date& birthday, const Address& addr)
{
	return std::shared_ptr<PersonInterface>(new RealPerson(name, birthday, addr));
}