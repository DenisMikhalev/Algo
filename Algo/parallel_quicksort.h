#pragma once

template<class T>
inline void parallel_quickSort(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_QUICKSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_QUICKSORT_CUTOFF)
	{
		quickSort(a, nLength);
		std::sort(begin + nBlockSize*nThreads, begin + nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&quickSort<T>, a + i*nBlockSize, nBlockSize);
	}
	quickSort(a + (nThreads - 1)*nBlockSize, nLength - (nThreads - 1)*nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(begin, nBlockSize, nLength);
}

template<class T>
inline void parallel_quickSortCutoff(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_QUICKSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_QUICKSORT_CUTOFF)
	{
		quickSortCutoff(a, nLength);
		std::sort(begin + nBlockSize*nThreads, begin + nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&quickSortCutoff<T>, a + i*nBlockSize, nBlockSize);
	}
	quickSortCutoff(a + (nThreads - 1)*nBlockSize, nLength - (nThreads - 1)*nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(begin, nBlockSize, nLength);
}

template<class T>
inline void parallel_quickSortNotR(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_QUICKSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_QUICKSORT_CUTOFF)
	{
		quickSortNotR(a, nLength);
		std::sort(begin + nBlockSize*nThreads, begin + nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&quickSortNotR<T>, a + i*nBlockSize, nBlockSize);
	}
	quickSortNotR(a + (nThreads - 1)*nBlockSize, nLength - (nThreads - 1)*nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(begin, nBlockSize, nLength);
}
