/*
항목29) 예외 안전성이 확보되는 그날 위해 싸우고 또 싸우자!
1. 예외 안정성을 갖춘 함수는 실행 중 예외가 발생되더라도 자원을 누출시키지 않으며 자료구조를 더럽힌 
채로 내버려 두지 않습니다. 이런 함수들이 제공할 수 있는 예외 안전성 보장은 기본적인 보장, 강력한 보장,
예외 금지 보장이 있습니다.
2. 강력한 예외 안전성 보장은 '복사-후-맞바꾸기' 방법을 써서 구현할 수 있지만, 모든 함수에 대해 강력한
보장이 실용적인 것은 아닙니다.
3. 어떤 함수가 제공하는 예외 안전성 보장의 강도는, 그 함수가 내부적으로 호출하는 함수들이 제공하는
가장 약한 보장을 넘지 않습니다.
*/

#pragma once

#include "PrettyMenu_Pimpl.h"

int main()
{
	std::istream* img = NULL;
	PrettyMenu p;
	p.ChangeBackground(*img);

	return 0;
}