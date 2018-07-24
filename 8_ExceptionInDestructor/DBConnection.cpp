/*
(Non-Excutable)
�׸�8) ���ܰ� �Ҹ��ڸ� ������ ���ϵ��� �ٵ�� ����
1. �Ҹ��ڿ����� ���ܰ� ���������� �� �˴ϴ�. ���� �Ҹ��� �ȿ��� ȣ��� �Լ��� ���ܸ� ���� ���ɼ��� �ִٸ�, � �����̵��� �Ҹ��ڿ��� ��� �޾Ƴ� �Ŀ�
���� �������� ���α׷��� �������� �ؾ� �մϴ�.
2. � Ŭ������ ������ ����Ǵٰ� ���� ���ܿ� ���� ����ڰ� �����ؾ� �� �ʿ䰡 �ִٸ�, �ش� ������ �����ϴ� �Լ��� �ݵ�� ������ �Լ�
(��, �Ҹ��ڰ� �ƴ� �Լ�)�̾�� �մϴ�.

* ���ܰ� �߻��ϸ� ���α׷��� �ٷ� ������
DBConn::~DBConn()
{
try { db.close(); }
catch()
{
close ȣ���� �����ߴٴ� �α׸� �ۼ��մϴ�;
std::abort();
}
}
��

* ���ܰ� �߻��ϸ� ���ѹ�����
DBConn::~DBConn()
{
try { db.close(); }
catch()
{
close ȣ���� �����ߴٴ� �α׸� �ۼ��մϴ�;
}
}
*/

class DBConnection 
{
public:
	static DBConnection create();
	void close();
};

class DBConn // DBConnection ��ü�� �����ϴ� Ŭ����
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
				//close ȣ���� �����ߴٴ� �α׸� �ۼ��մϴ�.
			}
		}
	}

private:
	DBConnection db;
	bool closed;
};