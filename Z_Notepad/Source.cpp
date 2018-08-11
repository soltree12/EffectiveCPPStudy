/*#include <iostream>

int arr[5][8];
int weight[8];
int value[8];

int getMaxValue(int index, int capacity)
{
	int selected=0, unselected=0, maxValue=0;
	
	int unselected = arr[index][capacity - 1];
	if (capacity >= weight[index])
	{
		selected = getMaxValue(index - 1, capacity-weight[index]) + value[index];
	}
	maxValue = max(selected, unselected);
	arr[index][capacity] = maxValue;

	return 1;
}*/