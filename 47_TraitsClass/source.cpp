/*
항목 47) 타입에 대한 정보가 필요하다면 특성정보 클래스를 사용하자.
1. 특성정보 클래스는 컴파일 도중에 사용할 수 있는 타입 관련 정보를 만들어냅니다. 또한 특성정보 클래스는 템플릿 및 템플릿 특수 버전을 사용하여 구현합니다.
2. 함수 오버로딩 기법과 결합하여 특성정보 클래스를 사용하면, 컴파일 타임에 결정되는 타입별 if...else 점검문을 구사할 수 있습니다.
*/

#include <iterator>
#include <vector>
#include <forward_list>
#include <iostream>
/* advance 구현하기 : 지정된 반복자를 지정된 거리만큼 이동시키기 */

/*
input iterator : 전진만 가능, 한 번에 한 칸씩 이동, 쓸 수 있는 횟수(입력 or 출력) 한 번 - iostream
forward iterator : + 여러번 읽기 or 쓰기 가능 - slist(단일 연결 리스트)
bidirectional iterator : + 뒤로 이동 가능 - set, multiset, map, multimap 
random access iterator : + 임의의 거리만큼 앞뒤로 이동시키는 일을 상수 시간 안에 할 수 있음 - vector, deque, string, 포인터
*/

/*
특성정보 클래스의 설계 및 구현 방법
1. 다른 사람이 사용하도록 열어 주고 싶은 타입 관련 정보를 확인합나다.(예를 들어, 반복자라면 반복자 범주 등이 여기에 해당됩니다.)
2. 그 정보를 식별하기 위한 이름을 선택합니다.(예: iterator_category)
3. 지원하고자 하는 타입 관련 정보를 담은 템플릿 및 그 템플릿의 특수화 버전(예: iterator_traits)을 제공합니다.
*/

/* if문은 실행시간에 결정되지만 오버로딩은 컴파일 시간에 결정된다. */
template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::random_access_iterator_tag)
{
	iter += d; // 반복자에 대해서는 이 구현을 씁니다.
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


	iter += d; // 양방향 반복자에 대해서는 이 구현을 씁니다.
}

/* forward_iterator는 input_iterator_tag로부터 상속을 받고 구현이 같기 때문에, 따로 만들지 않는다.*/
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
특성정보 클래스를 사용하는 방법
1. 작업자 역할을 맡을 함수 혹은 함수 템플릿을 특성정보 매개변수를 다르게 하여 오버로딩합니다. 그리고 전달되는 해당 특성정보에 맞추어 각 오버로드 버전을 구현합니다.
2. 작업자를 호출하는 주작업자 역할을 맡을 함수 혹은 함수 템플릿을 만듭니다. 이때 특성정보 클래스에서 제공되는 정보를 넘겨서 작업자를 호출하도록 구현합니다.
*/
template<typename IterT, typename DistT>
void myAdvance(IterT& iter, DistT d)
{
	doAdvance(iter, d, typename std::iterator_traits<IterT>::iterator_category()); // iter의 반복자 범주에 적합한 doAdvance의 오버로드 버전을 호출합니다.
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
