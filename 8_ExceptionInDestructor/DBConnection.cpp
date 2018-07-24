/*
(Non-Excutable)
항목8) 예외가 소멸자를 떠나지 못하도록 붙들어 놓자
1. 소멸자에서는 예외가 빠져나가면 안 됩니다. 만약 소멸자 안에서 호출된 함수가 예외를 던질 가능성이 있다면, 어떤 예외이든지 소멸자에서 모두 받아낸 후에
삼켜 버리든지 프로그램을 끝내든지 해야 합니다.
2. 어떤 클래스의 연산이 진행되다가 던진 예외에 대해 사용자가 반응해야 할 필요가 있다면, 해당 연산을 제공하는 함수는 반드시 보통의 함수
(즉, 소멸자가 아닌 함수)이어야 합니다.

* 예외가 발생하면 프로그램을 바로 끝내기
DBConn::~DBConn()
{
try { db.close(); }
catch()
{
close 호출이 실패했다는 로그를 작성합니다;
std::abort();
}
}
ㅋ

* 예외가 발생하면 삼켜버리기
DBConn::~DBConn()
{
try { db.close(); }
catch()
{
close 호출이 실패했다는 로그를 작성합니다;
}
}
*/

class DBConnection 
{
public:
	static DBConnection create();
	void close();
};

class DBConn // DBConnection 객체를 관리하는 클래스
{
public:
	void close()
	{
		db.close();
		closed = true;
	}
	~DBConn()
	{
		if (!closed)
		{
			try
			{
				db.close();
			}
			catch (...)
			{
				//close 호출이 실패했다는 로그를 작성합니다.
			}
		}
	}

private:
	DBConnection db;
	bool closed;
};