/*
�׸�9) ��ü ���� �� �Ҹ� ���� �߿��� ����� ���� �Լ��� ȣ������ ����
1. ������ Ȥ�� �Ҹ��� �ȿ��� ���� �Լ��� ȣ������ ������. ���� �Լ���� �ص�, ���� ���� ���� �����ڳ� �Ҹ��ڿ� �ش�Ǵ� Ŭ������
�Ļ� Ŭ���� �����δ� �������� �����ϱ��.
*/

/*
�⺻ Ŭ���� �κ��� ������ ���� ���� �Լ��� ȣ���Ѵ� �ص� �⺻ Ŭ������ ��Ÿ���� �Ѿ� ������ �� ���� ������,
�ʿ��� �ʱ�ȭ ������ �Ļ� Ŭ���� �ʿ��� �⺻ Ŭ���� �����ڷ� '�÷�'�ֵ��� �������ν� ������ �κ��� ������
ä��� �ִٴ� ���Դϴ�.
*/

#include<iostream>
#include<string>

class Transaction {
public:
	explicit Transaction(const std::string& logInfo);
	
	void logTransaction(const std::string& logInfo) const;
};

Transaction::Transaction(const std::string& logInfo)
{
	logTransaction(logInfo);
}

void Transaction::logTransaction(const std::string& logInfo) const
{
	std::cout << logInfo << std::endl;
}

class BuyTransaction : public Transaction {
public:
	BuyTransaction(const int& value)
		: Transaction(createLogString(value)){}
private:
	static std::string createLogString(const int& value);
};

std::string BuyTransaction::createLogString(const int& value)
{
	return "value : " + std::to_string(value);
}

int main()
{
	BuyTransaction buyt(48);
}