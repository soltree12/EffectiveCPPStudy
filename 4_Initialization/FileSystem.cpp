#include "FileSystem.h"

std::size_t FileSystem::numDisks() const
{
	return 10;
}

// 3. ���� ���� ������ �ִ� ������ ���� ��ü���� �ʱ�ȭ ���� ������ ���ؼ� �����ؾ� �մϴ�. ������ ���� ��ü�� ���� ���� ��ü�� �ٲٸ� �˴ϴ�. (�Լ�ȭ)
FileSystem& FileSystem::tfs()
{
	static FileSystem fs;
	std::cout << "Referencing FileSystem..." <<std::endl;
	return fs;
}

