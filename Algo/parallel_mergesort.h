#pragma once

template<class T>
void parallel_mergeSort(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_MERGESORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	if (nBlockSize < PARALLEL_MERGESORT_CUTOFF)
	{
		mergeSort(a, 0, nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < nThreads - 1; ++i)
	{
		threads[i] = std::thread(&mergeSort<T>, a + i*nBlockSize, 0, nBlockSize - 1);
	}
	mergeSort(a + (nThreads - 1)*nBlockSize, 0, nLength - (nThreads - 1)*nBlockSize - 1);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(a, nBlockSize, nLength);
}
