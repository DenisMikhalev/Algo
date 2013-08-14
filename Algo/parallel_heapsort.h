#pragma once

template<class T>
inline void parallel_heapSort(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_HEAPSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	if (nBlockSize < PARALLEL_HEAPSORT_CUTOFF)
	{
		heapSort(a, nLength);
		std::sort(a + nBlockSize*nThreads, a + nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&heapSort<T>, a + i*nBlockSize, nBlockSize);
	}
	heapSort(a + (nThreads - 1)*nBlockSize, nLength - (nThreads - 1)*nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(a, nBlockSize, nLength);
}