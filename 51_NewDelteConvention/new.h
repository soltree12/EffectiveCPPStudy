#pragma once

/* 0바이트가 요구되었을 때, 1바이트 요구인 것으로 간주하고 처리하기 */
/*
#include <new>

void* operator new(std::size_t size) throw(std::bad_alloc)
{
	using namespace std;

	if (size == 0) { size = 1; } // 0바이트 요청이 들어오면, 이것을 1바이트 요구로 간주하고 처리합니다.

	while (true)
	{
		size 바이트 할당하기
		if (할당이 성공했음)
			return (할당된 메모리에 대한 포인터);
		//할당이 실패했을 경우, 현재의 new 처리자 함수가 어느 것으로 설정되어 있는지 찾아냅니다.
		new_handler globalHandler = set_new_handler(0);
		set_new_handler(globalHandler);

		if(globalHandler) (*globalHandler)();
		else throw std::bad_alloc();

	}
}

*/