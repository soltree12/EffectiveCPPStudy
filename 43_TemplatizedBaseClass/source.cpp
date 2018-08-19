/*
항목 43) 템플릿으로 만들어진 기본 클래스 안의 이름에 접근하는 방법을 알아 두자
1. 파생 클래스 템플릿에서 기본 클래스 템플릿의 이름을 참조할 때는, "this->"를 접두사로 붙이거나 기본 클래스 한정문을 명시적으로 써 주는 것으로 해결합시다.
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


 
class MsgInfo { // 메시지 생성에 사용되는 정보를 담기 위한 클래스
public:
	MsgInfo(std::string newMsg) : _msg(newMsg) {}
	std::string msg() const { return _msg; }

private:
	std::string _msg;
};

class CompanyA { // 다른 회사들을 나타내는 각각의 클래스
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

	void sendSecret(const MsgInfo& info) // sendClear 함수와 비슷합니다. 단, c.sendEncrypted 함수를 호출하는 점이 차이.
	{
		std::string msg;
		msg = info.msg();

		Company c;
		c.sendEncrypted(msg);
	}
};

/* 템플릿 기본 클래스의 함수 호출문제 */
template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
	using MsgSender<Company>::sendClear; // 컴파일러에게 sendClear함수가 기본클래스에 있다고 가정하라고 알려준다.
	void sendClearMsg(const MsgInfo& info)
	{
		printLine("LoggingMsgSender::sendClearMsg");

		/* 
		1. MsgSender<Company>가 무엇이 될지 이 클래스가 인스턴스로 만들어질 때까지 알 수 없다(Company가 템플릿 매개변수이기 때문에) => sendClear함수의 존재 여부를 알 수 없다.
		2. 만약 Company가 CompanyZ(템플릿 완전 특수화버전)라면 sendClear함수를 호출할수조차 없다!
		*/
		
		//sendClear(info); // 기본 클래스의 함수를 호출하는데, 이 코드는 컴파일 되지 않습니다.
		this->sendClear(info); // 해결책1 - this를 붙여 sendClear가 상속되는 것으로 가정한다.
		MsgSender<Company>::sendClear(info); //해결책2 -  호출할 함수가 기본 클래스의 함수라는 점을 명시적으로 지정한다.(가상함수 바인딩이 무시되기 때문에 추천하지 않음)
	}
};

class CompanyZ { // sendEncrypted만 있는 클래스
public:
	void sendEncrypted(const std::string& msg)
	{
		printLine("companyZ::sendEncrypted");
	}
};

template<>//템플릿 완전 특수화 버전이라는 뜻
class MsgSender<CompanyZ> {// CompanyZ에 대한
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