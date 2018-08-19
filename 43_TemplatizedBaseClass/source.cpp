/*
�׸� 43) ���ø����� ������� �⺻ Ŭ���� ���� �̸��� �����ϴ� ����� �˾� ����
1. �Ļ� Ŭ���� ���ø����� �⺻ Ŭ���� ���ø��� �̸��� ������ ����, "this->"�� ���λ�� ���̰ų� �⺻ Ŭ���� �������� ��������� �� �ִ� ������ �ذ��սô�.
*/
#include <string>
#include <iostream>

void printLine(const std::string& str)
{
	std::cout << str << std::endl;
}

void printLine(const std::string& str1, const std::string& str2)
{
	std::cout << str1<< "//" << str2 << std::endl;
}


 
class MsgInfo { // �޽��� ������ ���Ǵ� ������ ��� ���� Ŭ����
public:
	MsgInfo(std::string newMsg) : _msg(newMsg) {}
	std::string msg() const { return _msg; }

private:
	std::string _msg;
};

class CompanyA { // �ٸ� ȸ����� ��Ÿ���� ������ Ŭ����
public:
	void sendCleartext(const std::string& msg)
	{
		printLine("companyA::sendCleartext",msg);
	}

	void sendEncrypted(const std::string& msg)
	{
		printLine("companyA::sendEncrypted",msg);
	}
};

class CompanyB {
public:
	void sendCleartext(const std::string& msg)
	{
		printLine("companyB::sendCleartext",msg);
	}

	void sendEncrypted(const std::string& msg)
	{
		printLine("companyB::sendEncrypted", msg);
	}
};

template<typename Company>
class MsgSender{
public:
	void sendClear(const MsgInfo& info)
	{
		std::string msg;
		msg = info.msg();

		Company c;
		c.sendCleartext(msg);
	}

	void sendSecret(const MsgInfo& info) // sendClear �Լ��� ����մϴ�. ��, c.sendEncrypted �Լ��� ȣ���ϴ� ���� ����.
	{
		std::string msg;
		msg = info.msg();

		Company c;
		c.sendEncrypted(msg);
	}
};

/* ���ø� �⺻ Ŭ������ �Լ� ȣ�⹮�� */
template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
	using MsgSender<Company>::sendClear; // �����Ϸ����� sendClear�Լ��� �⺻Ŭ������ �ִٰ� �����϶�� �˷��ش�.
	void sendClearMsg(const MsgInfo& info)
	{
		printLine("LoggingMsgSender::sendClearMsg");

		/* 
		1. MsgSender<Company>�� ������ ���� �� Ŭ������ �ν��Ͻ��� ������� ������ �� �� ����(Company�� ���ø� �Ű������̱� ������) => sendClear�Լ��� ���� ���θ� �� �� ����.
		2. ���� Company�� CompanyZ(���ø� ���� Ư��ȭ����)��� sendClear�Լ��� ȣ���Ҽ����� ����!
		*/
		
		//sendClear(info); // �⺻ Ŭ������ �Լ��� ȣ���ϴµ�, �� �ڵ�� ������ ���� �ʽ��ϴ�.
		this->sendClear(info); // �ذ�å1 - this�� �ٿ� sendClear�� ��ӵǴ� ������ �����Ѵ�.
		MsgSender<Company>::sendClear(info); //�ذ�å2 -  ȣ���� �Լ��� �⺻ Ŭ������ �Լ���� ���� ��������� �����Ѵ�.(�����Լ� ���ε��� ���õǱ� ������ ��õ���� ����)
	}
};

class CompanyZ { // sendEncrypted�� �ִ� Ŭ����
public:
	void sendEncrypted(const std::string& msg)
	{
		printLine("companyZ::sendEncrypted");
	}
};

template<>//���ø� ���� Ư��ȭ �����̶�� ��
class MsgSender<CompanyZ> {// CompanyZ�� ����
public:
	void sendSecret(const MsgInfo& info)
	{
		std::string msg;
		msg = info.msg();

		CompanyZ c;
		c.sendEncrypted(msg);
	}

};

int main()
{
	MsgInfo i("MEEE");
	LoggingMsgSender<CompanyA> lms;
	lms.sendClearMsg(i);
}