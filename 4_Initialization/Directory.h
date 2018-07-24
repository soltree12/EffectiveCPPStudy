#pragma once
#include <cstddef>
#include <iostream>
#include "FileSystem.h"

class Directory
{
public:
	Directory();
	static Directory& tempDir();
};
