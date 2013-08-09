#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "all.h"

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
	insertSortGuarded(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Insert sort with guarded key, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	binInsertSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Insert binary sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_insertSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel insert sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_insertSortGuarded(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel insert sort with guarded key, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_binInsertSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel insert binary sort, total time: " << duration << std::endl;
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

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	bubbleSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Bubble sort, total time: " << duration << std::endl;
	isOrdered(src);

	fillVector(src, countElem);
	start = std::chrono::high_resolution_clock::now();
	parallel_bubbleSort(&src.front(), src.size());
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double>(stop - start).count();
	std::cout << "Parallel bubble sort, total time: " << duration << std::endl;
	isOrdered(src);

	return 0;
}
