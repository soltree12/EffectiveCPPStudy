#include <iostream>

class CData
{
public:
	CData()
	{
		memset(m_arrDataList, 0, sizeof(m_arrDataList));
	}
	CData(const CData& oldCData)
	{
		*this = oldCData;
		std::cout << "CData�� ���� ������ ȣ��" << std::endl;
	}

private:
	int m_arrDataList[10];
};

CData& FuncA(CData& _data)
{
	//CData temp(_data);
	return _data;
}

int main()
{
	CData oData;
	FuncA(oData);

	return 0;
}