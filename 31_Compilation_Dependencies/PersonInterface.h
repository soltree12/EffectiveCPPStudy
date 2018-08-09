/*
(�ذ�å)
2. �������̽� Ŭ���� : � ����� ��Ÿ���� �������̽��� �߻� �⺻ Ŭ������ ���� ������ ����, �� Ŭ�����κ��� �Ļ� Ŭ������
���� �� �ְ� ����.
�������̽� Ŭ������ ����ϱ� ���ؼ��� ��ü ���� ������ �ּ��� �ϳ��� �־�� �Ѵ�. �� ������ �Ļ� Ŭ������ ������ ������ ����ϴ�
� �Լ��� ����� ���� �̰��� ȣ�������ν� �ذ��Ѵ�.(���丮�Լ� Ȥ�� ���� ������ �̿�)

*/

#pragma once
#include <iostream>
#include "Date.h"
#include "Address.h"

class PersonInterface {
public:
	/* �־��� �������̽� Ŭ������ �������̽��� �����ϴ� ��ü�� �������� �Ҵ��� ��, �� ��ü�� �����͸� ��ȯ(���� ����� ����Ǵ� ��찡 ����)*/
	static std::shared_ptr<PersonInterface> create(const std::string& name, const Date& birthday, const Address& addr);

	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;
	virtual std::string address() const = 0;
};

