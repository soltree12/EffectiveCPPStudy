/* 
�׸� 31) ���� ������ ������ �������� �ִ�� ������
1. ������ �������� �ּ�ȭ�ϴ� �۾��� ����� �Ǵ� ���� �⺻���� ���̵��� '����' ��ſ� '����'�� �����ϰ� �����ڴ� ���Դϴ�. �� ���̵� �����
�� ���� ���� ����� �ڵ� Ŭ������ �������̽� Ŭ�����Դϴ�.
2. ���̺귯�� ����� �� ��ü�� ��� ���� ���߾�� �ϸ� ����θ� ���� �ִ� ���¿��� �մϴ�. �� ��Ģ�� ���ø��� ���̰ų� ������ �ʰų�
�����ϰ� �����սô�.

*/

#include "PersonInterface.h" // �������̽��� include�ص� �������� �Լ��� �� �� �ִ�.
#include "GoodPerson.h"

int main()
{

	std::string name = "Min";
	Date dateOfBirth("1000");
	Address address("Seoul");

	/* pimpl(�ڵ� Ŭ����)�� �̿��� ��ü ���� */
	Person p(name, dateOfBirth, address);
	std::cout << "My name is "<<p.name() << std::endl;
	
	/* �������̽� Ŭ������ �̿��� ��ü ���� */
	std::shared_ptr<PersonInterface> pp(PersonInterface::create(name, dateOfBirth, address));
	std::cout << pp->name()
		<< " was born on "
		<< pp->birthDate()
		<< " and now lives at "
		<< pp->address()
		<< std::endl;


	return 0;
}