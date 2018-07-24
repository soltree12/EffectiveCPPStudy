#include "Directory.h"
#include "FileSystem.cpp"

Directory::Directory()
{
	std::size_t disks = FileSystem::tfs().numDisks();
}

// 3. 여러 번역 단위에 있는 비지역 정적 객체들의 초기화 순서 문제는 피해서 설계해야 합니다.비지역 정적 객체를 지역 정적 객체로 바꾸면 됩니다.
Directory& Directory::tempDir()
{
	static Directory temp;
	std::cout << "Referencing Directory..." << std::endl;
	return temp;
}