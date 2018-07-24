/*
항목9) 객체 생성 및 소멸 과정 중에는 절대로 가상 함수를 호출하지 말자
1. 생성자 혹은 소멸자 안에서 가상 함수를 호출하지 마세요. 가상 함수라고 해도, 지금 실행 중인 생성자나 소멸자에 해당되는 클래스의
파생 클래스 쪽으로는 내려가지 않으니까요.
*/

/*
기본 클래스 부분이 생성될 때는 가상 함수를 호출한다 해도 기본 클래스의 울타리를 넘어 내려갈 수 없기 때문에,
필요한 초기화 정보를 파생 클래스 쪽에서 기본 클래스 생성자로 '올려'주도록 만듦으로써 부족한 부분을 역으로
채울수 있다는 것입니다.
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