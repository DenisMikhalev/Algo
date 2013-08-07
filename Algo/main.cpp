#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "all.h"

void fillVector(std::vector<unsigned int>& dst, int countElem)
{
	dst.clear();
	for (int i = 0; i < countElem; ++i) { dst.push_back(rand() % INT_MAX); }
}

template<class T>
void isOrdered(std::vector<T> src)
{
	for (int i = 1; i < src.size(); ++i)
	{
		if (src[i - 1] > src[i])
			std::cout << "Wrong order: " << i << " " << src[i - 1] << " " << src[i] << std::endl;
	}
}

int main(int argc, char* argv[])
{
	srand (time(NULL));

	const int countElem = 1010001;
	std::vector<unsigned int> src;
	src.reserve(countElem);
	fillVector(src, countElem);

	auto start = std::chrono::high_resolution_clock::now();
	quickSort(&src.front(), src.size());
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "QuickSort, total time: " << duration << std::endl;
	isOrdered(src);

	start = std::chrono::high_resolution_clock::now();
	parallel_quickSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel Quick sort, total time: " << duration << std::endl;
	isOrdered(src);

	return 0;
}
