/*
�׸�17) new�� ������ ��ü�� ����Ʈ �����Ϳ� �����ϴ� �ڵ�� ������ �� �������� ������
1. new�� ������ ��ü�� ����Ʈ �����ͷ� �ִ� �ڵ�� ������ �� �������� ����ô�. �̰��� �� �Ǿ� ������, ���ܰ� �߻��� �� ������ϱ� ���� �ڿ� ������ �ʷ��� �� �ֽ��ϴ�.
*/                                                                                                                                                                                                                                                                                                                                                                                            

#include <iostream>
#include <memory>

class Widget {

};

int priority()
{
	return 1;
}
void processWidget(std::shared_ptr<Widget> pw, int priority)
{

}

int main()
{
	// processWidget(new Widget, priority()); // shared_ptr�� �����ڴ� explicit�� ����Ǿ� �ֱ� ������, �Ͻ����� ��ȯ�� �Ұ����ϴ�.
	
	/*
	C++�� �����Ϸ��� ���� �Ű������� ������ ����Ǵ� ������ �ٸ��� ������,
	1. "new Widget"�� �����մϴ�.
	2. priority�� ȣ���մϴ�.
	3. tr1::shared_ptr �����ڸ� ȣ���մϴ�.
	�� ���� �������� priority ȣ�� �κп��� ���ܰ� �߻��Ǹ� "new Widget"���� ��������� �����Ͱ� ���ǵ� �� �ִ�.
	*/
	processWidget(std::shared_ptr<Widget>(new Widget), priority());

	/* ������ ��� */
	std::shared_ptr<Widget> pw(new Widget);
	processWidget(pw, priority());

}