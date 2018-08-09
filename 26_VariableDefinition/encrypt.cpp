/*
항목26) 변수 정의는 늦출 수 있는 데까지 늦추는 근성을 발휘하자
1. 변수 정의는 늦출 수 있을 때까지 늦춥시다. 프로그램이 더 깔끔해지며 효율도 좋아집니다.
*/

#include <iostream>
#include <string>
static const int MinimumPasswordLength = 3;


void encrypte(std::string& password)
{
	password = std::string("Encrypted : ").append(password);
}
void showString(const std::string& str)
{
	std::cout << str << std::endl;
}
std::string encryptPassword(const std::string& password)
{
	using namespace std;
	if (password.length() < MinimumPasswordLength) {
		throw logic_error("Password is too short");
	}
	string encrypted(password); //변수를 정의함과 동시에 초기화, 이때 복사 생성자가 쓰임.
	encrypte(encrypted);
	showString(encrypted);
	return encrypted;
}


int main()
{
	encryptPassword("12");

	return 0;
}

/*
A. 루프 바깥쪽에 정의 (생성자 1번 + 소멸자 1번 + 대입 n번) , B보다 유효범위가 넓어짐(루프 바깥에 정의했으므로)
Widget w;
for(int i=0;i<n;++i){
w = i에 따라 달라지는 값
}

B. 루프 안쪽에 정의 (생성자 n번 + 소멸자 n번)
for(int i=0;i<n;++i){
Widget w(i에 따라 달라지는 값);
}

* 대입이 생성자-소멸자 쌍보다 비용이 덜 들고, 전체 코드에서 수행 성능에 민감한 부분을 건드리는 중이라고 생각하지 않는다면,
앞뒤 볼 것 없이 B 방법으로 가는 것이 좋습니다.

*/
