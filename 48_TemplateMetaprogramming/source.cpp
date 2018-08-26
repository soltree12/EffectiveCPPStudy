/* 
항목48) 템플릿 메타프로그래밍, 하지 않겠는가? 
1. 템플릿 메타프로그래밍은 기존 작업을 런타임에서 컴파일 타임으로 전환하는 효과를 냅니다. 따라서 TMP를 쓰면 선행 에러 탐지와 높은 런타임 효율을 손에 거머쥘 수 있습니다.
2. TMP는 정책 선택의 조합에 기반하여 사용자 정의 코드를 생성하는 데 쓸 수 있으며, 또한 특정 타입에 대해 부적절한 코드가 만들어지는 것을 막는데도 쓸 수 있습니다.
*/

#include<iostream>

template<unsigned n> // 일반적인 경우: Factorial<n>의 값은 Factorial<n-1>의 값에 n을 곱해서 만듭니다.
struct Factorial {
	enum{value =n *Factorial<n-1>::value};
};

template<>
struct Factorial<0> {
	enum { value = 1 };
};

int main()
{
	std::cout << Factorial<5>::value<<std::endl;
	std::cout << Factorial<10>::value<<std::endl;
}