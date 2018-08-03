/*
(Non-Excutable)
�׸� 27) ĳ������ ����, �� ����! ���� ����
1. �ٸ� ����� �����ϴٸ� ĳ������ ���Ͻʽÿ�. Ư�� ���� ���ɿ� �ΰ��� �ڵ忡�� dynamic_cast�� �� ���̰� �ٽ� �����Ͻʽÿ�. ���� �߿�
ĳ������ �ʿ������ٸ�, ĳ������ ���� �ʴ� �ٸ� ����� �õ��� ���ʽÿ�.
2. ĳ������ ��¿ �� ���� �ʿ��ϴٸ�, �Լ� �ȿ� ���� �� �ֵ��� �� ���ʽÿ�. �̷��� �ϸ� �ּ��� ����ڴ� �ڽ��� �ڵ忡 ĳ������ ���� �ʰ�
�� �Լ��� ȣ���� �� �ְ� �˴ϴ�.
3. ���� ��Ÿ���� ĳ��Ʈ�� �����ŵ� C++ ��Ÿ���� ĳ��Ʈ�� ��ȣ�Ͻʽÿ�. �߰��ϱ⵵ ����, �����ڰ� � ������ �ǵ��ߴ����� �� �ڼ��ϰ� �巯���ϴ�.
*/

#include <iostream>
#include <vector>
class Window {
public:
	virtual void onResize(){...} // �⺻ Ŭ������ onResize ���� ���
};

/*
Case 1) ���� �Լ��� �Ļ� Ŭ�������� �������ؼ� ������ �� �⺻ Ŭ������ ������ ȣ���ϴ� ������ ���� ���� �ִ� ���
*/

/* �߸��� ��� */
class SpecialWindow : public Window { // �Ļ� Ŭ����
public:
	virtual void onResize() {
		//�Ļ� Ŭ������ onResize ���� ��� *this�� Window�� ĳ�����ϰ� �װͿ� ���� onResize�� ȣ���մϴ�. ������ �� �Ǿ ������.
		//(static_cast�� �Ͼ�鼭 *this�� �⺻ Ŭ���� �κп� ���� �纻�� �ӽ������� ��������µ�, �� �ӽ� ��ü���� onResize�Լ��� ȣ��(�纻�� �����)
		static_cast<Window>(*this).onResize();
	}
};


/* ���� ��� : ���� ��ü�� ��� onResize�� �⺻ Ŭ���� ������ ȣ���ϵ��� �����. */
class SpecialWindow : public Window {
public:
	virtual void onResize() {
		Window::onResize();
	}
};


/*
Case 2) �Ļ� Ŭ���� ��ü���� �и��� �༮�� �־ �̿� ���� �Ļ� Ŭ������ �Լ��� ȣ���ϰ� ������, �� ��ü�� ������ �� �ִ� �������� 
�⺻ Ŭ������ �����͹ۿ� ���� ���
*/

class BlinkWindow : public Window { // �Ļ� ��ü���� �ִ� blink �Լ�
public:
	void blink();
};

/* �ٶ������� ���� ��� : dynamic_cast ���(���� ����) */
void func()
{
	typedef std::vector<std::shared_ptr<Window> > VPW; // Window�� ����Ű�� ����Ʈ �����͵��� ����
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		if (BlinkWindow *psw = dynamic_cast<BlinkWindow*>(iter->get()))
			psw->blink();
	}
}

/* 
���� ��� 1: �Ļ� Ŭ���� ��ü�� ���� �����͸� �����̳ʿ� ��� 
���� - �Ļ� Ŭ������ �������� ���� ���� �Ұ�
*/
void func()
{
	typedef std::vector<std::shared_ptr<BlinkWindow> > VPW; // Window�� ����Ű�� ����Ʈ �����͵��� ����
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		(*iter)->blink();
	}
}

/* 
���� ��� 2 : �⺻ blink�� �����ؼ� ���� �Լ��� ����
*/
class Window {
public:
	virtual void blink() {} // �⺻ ������ '�ƹ� ���� ���ϱ�'
};

class BlinkWindow : public Window {
public:
	virtual void blink() {...} // �� Ŭ���������� blink �Լ��� Ư���� ������ �����մϴ�.
};

void func()
{
	typedef std::vector<std::shared_ptr<Window> > VPW;
	VPW winPtrs; // �� �����̳ʿ����� Window���� �Ļ��� ��� Ÿ���� ��ü���� ����ϴ�.
	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		(*iter)->blink();
	}
}

/* 
���� �� ���� ��� : ������ dynamic_cast (�Ļ� Ŭ������ �߰��ɶ����� ���ǹ��� �߰��ؾ���)
*/

void func()
{
	typedef std::vector<std::shared_ptr<Window> > VPW;
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();++iter)
	{
		if (BlinkWindow1 *psw = dynamic_cast<BlinkWindow1*>(iter->get())){ ... }
		else if (BlinkWindow2 *psw = dynamic_cast<BlinkWindow2*>(iter->get())) { ... }
		else if (BlinkWindow3 *psw = dynamic_cast<BlinkWindow3*>(iter->get())) { ... }
	}
}