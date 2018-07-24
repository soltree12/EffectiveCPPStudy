#include "Directory.h"
#include "FileSystem.cpp"

Directory::Directory()
{
	std::size_t disks = FileSystem::tfs().numDisks();
}

// 3. ���� ���� ������ �ִ� ������ ���� ��ü���� �ʱ�ȭ ���� ������ ���ؼ� �����ؾ� �մϴ�.������ ���� ��ü�� ���� ���� ��ü�� �ٲٸ� �˴ϴ�.
Directory& Directory::tempDir()
{
	static Directory temp;
	std::cout << "Referencing Directory..." << std::endl;
	return temp;
}