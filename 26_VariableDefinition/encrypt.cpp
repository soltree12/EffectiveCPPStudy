/*
�׸�26) ���� ���Ǵ� ���� �� �ִ� ������ ���ߴ� �ټ��� ��������
1. ���� ���Ǵ� ���� �� ���� ������ ����ô�. ���α׷��� �� ��������� ȿ���� �������ϴ�.
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
	string encrypted(password); //������ �����԰� ���ÿ� �ʱ�ȭ, �̶� ���� �����ڰ� ����.
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
A. ���� �ٱ��ʿ� ���� (������ 1�� + �Ҹ��� 1�� + ���� n��) , B���� ��ȿ������ �о���(���� �ٱ��� ���������Ƿ�)
Widget w;
for(int i=0;i<n;++i){
w = i�� ���� �޶����� ��
}

B. ���� ���ʿ� ���� (������ n�� + �Ҹ��� n��)
for(int i=0;i<n;++i){
Widget w(i�� ���� �޶����� ��);
}

* ������ ������-�Ҹ��� �ֺ��� ����� �� ���, ��ü �ڵ忡�� ���� ���ɿ� �ΰ��� �κ��� �ǵ帮�� ���̶�� �������� �ʴ´ٸ�,
�յ� �� �� ���� B ������� ���� ���� �����ϴ�.

*/
