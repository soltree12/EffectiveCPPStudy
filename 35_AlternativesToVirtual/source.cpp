/*
�׸� 35) ���� �Լ� ��� �� �͵鵵 ������ �δ� �ڼ��� �ýö����� �淯 ����.
1. ���� �Լ� ��ſ� �� �� �ִ� �ٸ� ������� NVI ���뱸 �� ���� ������ �� �� �ֽ��ϴ�. �� �� NVI ���뱸�� �� ��ü�� ���ø� �޼��� ������ �� ���Դϴ�.
2. ��ü�� �ʿ��� ����� ��� �Լ��κ��� Ŭ���� �ܺ��� ���� �Լ��� �ű��, �� ���� �Լ��� �� Ŭ������ public ����� �ƴ� �͵��� ������ �� ���ٴ� ������ ����ϴ�.
3. tr1::function ��ü�� �Ϲ�ȭ�� �Լ� ������ó�� �����մϴ�. �� ��ü�� �־��� ���� �ñ״�ó�� ȣȯ�Ǵ� ��� �Լ�ȣ�⼺ ��ü�� �����մϴ�.
*/

/*
� ������ �ذ��ϱ� ���� ���踦 ã�� �� ���� �Լ��� ����ϴ� ����鵵 ����� ����.
1. �񰡻� �������̽� ���뱸(NVI ���뱸)�� ����մϴ� : �������� ���� ���� �Լ��� �񰡻� public ��� �Լ��� ���缭 ȣ���ϴ�, ���ø� �޼��� ������ �� �����Դϴ�.
2. ���� �Լ��� �Լ� ������ ������ ����� ��ü�մϴ�. : �������� ���� ���� ������ �ٽɸ��� �����ִ� �����Դϴ�.
3. ���� �Լ��� tr1::function ������ ����� ��ü�Ͽ�, ȣȯ�Ǵ� �ñ״�ó�� ���� �Լ�ȣ�⼺ ��ü�� ����� �� �ֵ��� ����ϴ� : ���� ���� ������ �� �����Դϴ�.
4. ���� Ŭ���� ���뿡 ���� �ִ� ���� �Լ��� �ٸ� �� ���뿡 ���� �ִ� ���� �Լ��� ��ü�մϴ�. : ���� ������ �������� ���� �����Դϴ�.
*/

#include <iostream>
#include <functional>
//#include "GameCharacter_FuncPointer.h"
//#include "GameCharacter_NVI.h"
//#include "GameCharacter_TR1Func.h"
#include "GameCharacter_Pattern.h"
using namespace std::placeholders;

int main()
{
	/* GameCharacter_FuncPointer */
	/*
	EvilBadGuy ebg1(125);
	std::cout<<ebg1.healthFunction()<<std::endl;
	return 0;
	*/


	/* GameCharacter_TR1Func */
	/*
	EvilBadGuy ebg1(120, calcHealth);
	std::cout << ebg1.healthFunction() << std::endl;

	EvilBadGuy ebg2(130, HealthCalculator());
	std::cout << ebg2.healthFunction() << std::endl;
	
	GameLevel currentLevel;
	
	//GameLevel::health �Լ��� �Ű����� �ϳ��� �޴� ������ ����Ǿ� ������, �����δ� �� ���� �޽��ϴ�. GameLevel ��ü �ϳ��� �Ͻ������� �޾Ƶ��̴ϱ� ������. 
	//currentLevel : ����� ��ü , _1 : ���� �Ű�����(&GameLevel::health�� �Ű������� &GameCharacter�̹Ƿ� �� Ÿ���� ���������
	EvilBadGuy ebg3(10, bind(&GameLevel::health, currentLevel, _1)); 
	std::cout << ebg3.healthFunction() << std::endl;
	*/


	/* GameCharacter_Pattern */
	HealthCalcFunc myHealthCalc;
	GameCharacter gc(10, &myHealthCalc);
	std::cout << gc.healthValue() << std::endl;
}