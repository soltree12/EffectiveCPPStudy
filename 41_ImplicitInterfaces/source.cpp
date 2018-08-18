#include "Widget.h"

int main()
{
	Widget w1(3);
	Widget w2(4);

	doProcessing(w1);
	doProcessingTemplate<Widget>(w2);
}