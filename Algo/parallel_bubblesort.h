#pragma once

template<class T>
inline void parallel_bubbleSort(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_BUBBLESORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_BUBBLESORT_CUTOFF)
	{
		quickSort(a, nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&bubbleSort<T>, a, nBlockSize);
		std::advance(a, nBlockSize);
	}
	bubbleSort(a, nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(begin, nBlockSize, nLength);
}
