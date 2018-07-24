#include "FileSystem.h"

std::size_t FileSystem::numDisks() const
{
	return 10;
}

// 3. 여러 번역 단위에 있는 비지역 정적 객체들의 초기화 순서 문제는 피해서 설계해야 합니다. 비지역 정적 객체를 지역 정적 객체로 바꾸면 됩니다. (함수화)
FileSystem& FileSystem::tfs()
{
	static FileSystem fs;
	std::cout << "Referencing FileSystem..." <<std::endl;
	return fs;
}

