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
			std::cout << "Wrong order! Index:" << i << " Prev:" << src[i - 1] << " Cur:" << src[i] << std::endl;
	}
}

int main(int argc, char* argv[])
{
	srand (time(NULL));

	const int countElem = 100000;
	std::vector<unsigned int> src;
	src.reserve(countElem);
	fillVector(src, countElem);

	auto start = std::chrono::high_resolution_clock::now();
	quickSort(&src.front(), src.size());
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "QuickSort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	quickSortCutoff(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "QuickSort with CUTOFF, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	quickSortNotR(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "QuickSort not recursive, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_quickSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel Quick sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_quickSortCutoff(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel Quick sort with CUTOFF, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_quickSortNotR(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel Quick not recursive, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	insertSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Insert sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	mergeSort(&src.front(), 0, src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Merge sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_mergeSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel merge sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	selectSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Select sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	selectBiSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Select sort bidirectional, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_selectSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel select sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_selectBiSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel select sort bidirectional, total time: " << duration << std::endl;
	isOrdered(src);

	return 0;
}
