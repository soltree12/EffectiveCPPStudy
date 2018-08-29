#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
int maxPrice;
int isSorted_bool = false;

/* 배열을 숫자(금액)으로 반환 */
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

/* 스왑 */
void swap(int &a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/* 배열이 내림차순으로 정리되었는지 확인 */
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

/* 배열에 중복된 원소가 있는지 확인 */
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

/* 메인 알고리즘 */
void search(std::vector<int> arr, int chance)
{

	/* 교환 기회가 없을때는 현재 금액을 최대값과 비교 후 갱신 */
	if (chance == 0)
	{
		if (maxPrice < getPrice(arr)) maxPrice = getPrice(arr);
	}
	/* 교환 기회가 남았는데 최고 금액일 경우 */
	else if (isSorted(arr))
	{
		isSorted_bool = true;
		/* 중복된 원소가 있을 때는 서로 맞바꾸기하면 되므로 최대값 유지 */
		if (isDuplicated(arr))
		{
			maxPrice = getPrice(arr);
		}
		else
		{
			/* 기회가 짝수번 남았을 때는 최대값 유지(교환 후 같은 위치를 한번 더 교환하면 원래 값이 되므로)*/
			if (chance % 2 == 0)
			{
				maxPrice = getPrice(arr);
			}
			/* 기회가 홀수번 남았을 때는 손실액을 최소로 하기 위해 십의 자리와 일의 자리 바꿈*/
			else
			{
				swap(*(arr.end() - 2), *(arr.end() - 1));
				maxPrice = getPrice(arr);
			}
		}
	}
	/* 교환 기회도 있고 현재 값이 최대값도 아닐경우 : 교환 가능한 모든 원소들을 교환해본다. */
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

