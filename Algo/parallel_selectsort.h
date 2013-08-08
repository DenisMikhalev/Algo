#pragma once

template<class T>
inline void parallel_selectSort(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_SELECTSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_SELECTSORT_CUTOFF)
	{
		selectSort(a, nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&selectSort<T>, a, nBlockSize);
		std::advance(a, nBlockSize);
	}
	selectSort(a, nBlockSize);


	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	merge(begin, nBlockSize, nLength);
}

template<class T>
inline void parallel_selectBiSort(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_SELECTSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_SELECTSORT_CUTOFF)
	{
		selectBiSort(a, nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&selectBiSort<T>, a, nBlockSize);
		std::advance(a, nBlockSize);
	}
	selectBiSort(a, nBlockSize);


	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	merge(begin, nBlockSize, nLength);
}
