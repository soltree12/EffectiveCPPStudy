#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
int maxPrice;
int isSorted_bool = false;

/* �迭�� ����(�ݾ�)���� ��ȯ */
int getPrice(std::vector<int>& arr)
{
	int price = 0;
	int unit = 1;
	std::vector<int>::reverse_iterator iter = arr.rbegin();
	for (;iter != arr.rend();iter++)
	{
		price += (*iter)*unit;
		unit *= 10;
	}
	return price;
}

/* ���� */
void swap(int &a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/* �迭�� ������������ �����Ǿ����� Ȯ�� */
bool isSorted(std::vector<int>& arr)
{
	for (int i = 0;i < arr.size() - 1;i++)
	{
		if (arr[i] < arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

/* �迭�� �ߺ��� ���Ұ� �ִ��� Ȯ�� */
bool isDuplicated(std::vector<int>& arr)
{
	std::vector<int> tempArr;
	for (int i = 0;i < arr.size();i++)
	{
		for (int j = 0; j < tempArr.size();j++)
		{
			if (arr[i] == tempArr[j]) return true;
		}
		tempArr.push_back(arr[i]);
	}
	return false;
}

/* ���� �˰��� */
void search(std::vector<int> arr, int chance)
{

	/* ��ȯ ��ȸ�� �������� ���� �ݾ��� �ִ밪�� �� �� ���� */
	if (chance == 0)
	{
		if (maxPrice < getPrice(arr)) maxPrice = getPrice(arr);
	}
	/* ��ȯ ��ȸ�� ���Ҵµ� �ְ� �ݾ��� ��� */
	else if (isSorted(arr))
	{
		isSorted_bool = true;
		/* �ߺ��� ���Ұ� ���� ���� ���� �¹ٲٱ��ϸ� �ǹǷ� �ִ밪 ���� */
		if (isDuplicated(arr))
		{
			maxPrice = getPrice(arr);
		}
		else
		{
			/* ��ȸ�� ¦���� ������ ���� �ִ밪 ����(��ȯ �� ���� ��ġ�� �ѹ� �� ��ȯ�ϸ� ���� ���� �ǹǷ�)*/
			if (chance % 2 == 0)
			{
				maxPrice = getPrice(arr);
			}
			/* ��ȸ�� Ȧ���� ������ ���� �սǾ��� �ּҷ� �ϱ� ���� ���� �ڸ��� ���� �ڸ� �ٲ�*/
			else
			{
				swap(*(arr.end() - 2), *(arr.end() - 1));
				maxPrice = getPrice(arr);
			}
		}
	}
	/* ��ȯ ��ȸ�� �ְ� ���� ���� �ִ밪�� �ƴҰ�� : ��ȯ ������ ��� ���ҵ��� ��ȯ�غ���. */
	else if (chance> 0 && !isSorted_bool)
	{
		std::vector<int>::iterator iter1 = arr.begin();
		std::vector<int>::iterator iter2 = arr.begin() + 1;
		for (;iter1 != arr.end();iter1++)
		{
			for (iter2 = iter1 + 1;iter2 != arr.end();iter2++)
			{
				if (*iter1 < *iter2)
				{
					swap(*iter1, *iter2);
					search(arr, chance - 1);
					swap(*iter1, *iter2);
				}
			}
		}
	}

}

int main()
{
	int testSize;
	std::cin >> testSize;
	for (int i = 0;i < testSize;i++)
	{
		int number, chance;
		std::cin >> number >> chance;
		std::vector<int> arr;
		while (number != 0)
		{
			arr.push_back(number % 10);
			number /= 10;
		}
		std::reverse(arr.begin(), arr.end());
		maxPrice = getPrice(arr);
		isSorted_bool = false;
		search(arr, chance);
		std::cout << "#" << i + 1 << " " << maxPrice;
		std::cout << std::endl;
	}
}

