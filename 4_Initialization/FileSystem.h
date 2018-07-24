#pragma once
#include <cstddef>
#include <iostream>

class FileSystem
{
public:
	std::size_t numDisks() const;
	static FileSystem& tfs();
};
