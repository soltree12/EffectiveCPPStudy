#pragma once
#include <new>
class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh):handler(nh){} // 현재의 new 처리자를 획득합니다.
	~NewHandlerHolder()
	{
		std::set_new_handler(handler); // 이것을 해제합니다.
	}

private:
	std::new_handler handler; // 이것을 기억해 둡니다.
	
	NewHandlerHolder(const NewHandlerHolder&); // 복사를 막기 위한 부분
	NewHandlerHolder& operator= (const NewHandlerHolder&); // 복사를 막기 위한 부분
};