/*
�׸� 47) Ÿ�Կ� ���� ������ �ʿ��ϴٸ� Ư������ Ŭ������ �������.
1. Ư������ Ŭ������ ������ ���߿� ����� �� �ִ� Ÿ�� ���� ������ �������ϴ�. ���� Ư������ Ŭ������ ���ø� �� ���ø� Ư�� ������ ����Ͽ� �����մϴ�.
2. �Լ� �����ε� ����� �����Ͽ� Ư������ Ŭ������ ����ϸ�, ������ Ÿ�ӿ� �����Ǵ� Ÿ�Ժ� if...else ���˹��� ������ �� �ֽ��ϴ�.
*/

#include <iterator>
#include <vector>
#include <forward_list>
#include <iostream>
/* advance �����ϱ� : ������ �ݺ��ڸ� ������ �Ÿ���ŭ �̵���Ű�� */

/*
input iterator : ������ ����, �� ���� �� ĭ�� �̵�, �� �� �ִ� Ƚ��(�Է� or ���) �� �� - iostream
forward iterator : + ������ �б� or ���� ���� - slist(���� ���� ����Ʈ)
bidirectional iterator : + �ڷ� �̵� ���� - set, multiset, map, multimap 
random access iterator : + ������ �Ÿ���ŭ �յڷ� �̵���Ű�� ���� ��� �ð� �ȿ� �� �� ���� - vector, deque, string, ������
*/

/*
Ư������ Ŭ������ ���� �� ���� ���
1. �ٸ� ����� ����ϵ��� ���� �ְ� ���� Ÿ�� ���� ������ Ȯ���ճ���.(���� ���, �ݺ��ڶ�� �ݺ��� ���� ���� ���⿡ �ش�˴ϴ�.)
2. �� ������ �ĺ��ϱ� ���� �̸��� �����մϴ�.(��: iterator_category)
3. �����ϰ��� �ϴ� Ÿ�� ���� ������ ���� ���ø� �� �� ���ø��� Ư��ȭ ����(��: iterator_traits)�� �����մϴ�.
*/

/* if���� ����ð��� ���������� �����ε��� ������ �ð��� �����ȴ�. */
template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::random_access_iterator_tag)
{
	iter += d; // �ݺ��ڿ� ���ؼ��� �� ������ ���ϴ�.
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::bidirectional_iterator_tag)
{
	if (d > 0)
	{
		while (d--)
		{
			iter++;
		}
	}
	else
	{
		while (d++)
		{
			iter--;
		}
	}


	iter += d; // ����� �ݺ��ڿ� ���ؼ��� �� ������ ���ϴ�.
}

/* forward_iterator�� input_iterator_tag�κ��� ����� �ް� ������ ���� ������, ���� ������ �ʴ´�.*/
template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag)
{
	if (d < 0)
	{
		throw std::out_of_range("Negative distance");
	}
	while (d--) ++iter;
}


/* 
Ư������ Ŭ������ ����ϴ� ���
1. �۾��� ������ ���� �Լ� Ȥ�� �Լ� ���ø��� Ư������ �Ű������� �ٸ��� �Ͽ� �����ε��մϴ�. �׸��� ���޵Ǵ� �ش� Ư�������� ���߾� �� �����ε� ������ �����մϴ�.
2. �۾��ڸ� ȣ���ϴ� ���۾��� ������ ���� �Լ� Ȥ�� �Լ� ���ø��� ����ϴ�. �̶� Ư������ Ŭ�������� �����Ǵ� ������ �Ѱܼ� �۾��ڸ� ȣ���ϵ��� �����մϴ�.
*/
template<typename IterT, typename DistT>
void myAdvance(IterT& iter, DistT d)
{
	doAdvance(iter, d, typename std::iterator_traits<IterT>::iterator_category()); // iter�� �ݺ��� ���ֿ� ������ doAdvance�� �����ε� ������ ȣ���մϴ�.
}

int main()
{
	std::vector<int> vec;
	std::forward_list<int> fwd;
	for (int i = 0;i < 10;i++)
	{
		vec.push_back(i);
		fwd.push_front(9-i);
	}

	std::vector<int>::iterator iterVec = vec.begin();
	std::forward_list<int>::iterator iterFwd = fwd.begin();

	myAdvance(iterVec, 4);
	myAdvance(iterFwd, 4);

	std::cout << *iterVec << " "<< *iterFwd << std::endl;
}
