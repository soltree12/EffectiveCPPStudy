#include <iostream>
/* 
(Non-Executable 
�׸� 42) typename�� �� ���� �ǹ̸� ����� �ľ�����
1. ���ø� �Ű������� ������ ��, class �� typename�� ���� �ٲپ� �ᵵ �����մϴ�.
2. ��ø ���� �̸��� �ĺ��ϴ� �뵵���� �ݵ�� typename�� ����մϴ�. ��, ��ø ���� �̸��� �⺻ Ŭ���� ����Ʈ�� �ְų� ��� �ʱ�ȭ ����Ʈ ���� �⺻ Ŭ���� �ĺ��ڷ� �ִ� ��쿡�� �����Դϴ�.
*/

/* 1. typename�� ���ӻ� : ��ø ���� �̸��� type���� �˸���. */
/* ���ø� �Ű������� �����ϴ� ����� class �� typename�� ������ ���� �ǹ̸� ���Ѵ�. */
template <typename C>
void print2nd(const C& container) // �����̳ʿ� ����ִ� �� ��° ���Ҹ� ����մϴ�. ������ �� �������� § �ڵ尡 �ƴմϴ�!
{
	if (container.size() >= 2)
	{
		typename C::const_iterator iter(container.begin()); // ù° ���ҿ� ���� �ݺ��ڸ� ����ϴ�.
		++iter; // iter�� �� ��° ���ҷ� �ű�ϴ�.
		int value = *iter; // �� ���Ҹ� �ٸ� int�� �����մϴ�.
		std::cout << value; // �� int�� ����մϴ�.
	}

	/* C::const_iteratoró�� ���ø��Ű�����(C)�� ���ӵ� ���� ������ ���� �̸��̶�� �Ѵ�.(Ŭ���� �ȿ� ��ø�Ǿ� ������ ��ø ���� �̸�) */
	//C::const_iterator * x; // ��ø ���� �̸��� �⺻������ Ÿ���� �ƴ� ������ �ؼ� -> C::const_iterator��� ���������� x�� ������ �ؼ��� �� ����
	typename C::const_iterator *x //�տ� typename�� �ٿ��� Ÿ������ �˸���.
}

template<typename C> //typename �� �� ����(class�� ���� �ǹ�)
void f(const C& container, // typename ���� �ȵ�
	typename C::iterator iter); // typename �� ��� ��

template <typename T>
class Derived:public Base<T>::Nested { // ��ӵǴ� �⺻ Ŭ���� ����Ʈ, typename ���� �� ��
public:
	explicit Derived(int x) : Base<T>::Nested(x) // ��� �ʱ�ȭ ����Ʈ�� �ִ� �⺻ Ŭ���� �ĺ���: typename ���� �� ��
	{
		typename Base<T>::Nested temp; // ��ø ���� Ÿ�� �̸��̸� �⺻ Ŭ���� ����Ʈ���� ���� ��� �ʱ�ȭ ����Ʈ�� �⺻ Ŭ���� �ĺ��ڵ� �ƴ� : typename �ʿ�
	}
};

/* 2. typename�� ���� ���� */
template <typename IterT>
void workWithIterator(IterT iter)
{
	/* ��ø ���� Ÿ�� �̸��̹Ƿ� typename�� �տ� ���δ�. */
	typename std::iterator_traits<IterT>::value_type temp(*iter); // IterT ��ü�� ����Ű�� �Ͱ� �Ȱ��� Ÿ���� ���������� ������ ��, iter�� ����Ű�� ��ü�� �� temp�� �ʱ�ȭ�ϴ� ����
	
	/* �Ʒ�ó�� �����ǵ� ���� */
	typedef typename std::iterator_traits<IterT>::value_type value_type;
	value_type temp(*iter);
}