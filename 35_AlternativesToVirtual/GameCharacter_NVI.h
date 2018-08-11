/* 
�񰡻� �������̽� ���뱸�� ���� ���ø� �޼��� ����(NVI(non-virtual interface))
=> healthValue�� public ��� �Լ��� �״�� �ε� �񰡻� �Լ��� �����ϰ�, ���������δ� ���� ������ ���� private ���� �Լ��� ȣ���Ѵ�.
*/


#pragma once
class GameCharacter {
public:

	GameCharacter(int newHealth) : theHealth(newHealth){}

	int healthValue() const // �Ļ� Ŭ������ ���� �� �Լ��� �������� �� �����ϴ�. �׸� 36 ����. (�����Լ��� Wrapper)
	{
		/* ���� ������ �����մϴ�.(���ؽ� ���, �α� ����, Ŭ���� �Һ��Ӽ� or �Լ��� �������� ����) */
		
		int retVal = doHealthValue(); // ���� ������ �����մϴ�.

		/* ���� ������ �����մϴ�.(���ؽ� ��� ����, �Լ��� �������� or Ŭ������ �Һ��Ӽ� �����) */

		return retVal;
	}
	
private:
	virtual int doHealthValue() const // �Ļ� Ŭ�������� ȣ���� �Ұ��������� �����Ǵ� �����ϴ�.
	{
		return theHealth; // ĳ������ ü��ġ ����� ���� �⺻ �˰��� ����
	}

	int theHealth;
};