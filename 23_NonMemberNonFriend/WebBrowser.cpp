/*
(Non-Excutable)
�׸�23) ��� �Լ����ٴ� ���� �������� �Լ��� �� ���������
1. ��� �Լ����ٴ� ���� �������� �Լ��� ���� ������ �սô�. ĸ��ȭ ������ ��������, ��Ű¡ �������� Ŀ����, ������� Ȯ�强�� �þ�ϴ�.
*/

class WebBrowser {
public:
	void clearCache();
	void clearHistory();
	void removeCookies();

	/* 
	ĸ��ȭ�� �������� ������ ��, �� ���� �ڵ� (� �����͸� �����ϴ� �Լ��� ������ �� �������� ĸ��ȭ ������ ����.) 
	void clearBrowser(){
		clearCache();
		clearHistory();
		removeCookies();
	}
	*/
};

/* ĸ��ȭ�� �������� ������ ��, �� ���� �ڵ�(���� �������� �Լ�) */
void clearBrowser(WebBrowser& wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}

/* 
* ���� �Լ��� �ۼ� �� ����, �з��� ���� ����� ������ �����ϸ� ���ϴ�.(namespace�� �����ϰ�)
( Webbrowser�� ���õ� ��� -> Webbrowser.h ��� ��) 
*/