/* guard_lock은 자동으로 lock과 unlock을 호출 */

/*#include <thread>
#include <mutex>
#include <iostream>

std::recursive_mutex mtx;
void ThreadFunc(int nID, int& nVal)
{
	for (int i = 0; i < 5; ++i)
	{
		std::lock_guard<std::recursive_mutex> lg(mtx);

		std::cout << "Value of " << nID << " -> " << nVal << std::endl;
		++nVal;
	}
}

int main()
{
	int nVal = 0;
	std::thread th1(ThreadFunc, 0, std::ref(nVal));
	std::thread th2(ThreadFunc, 1, std::ref(nVal));

	th1.join();
	th2.join();

	return 0;
}*/