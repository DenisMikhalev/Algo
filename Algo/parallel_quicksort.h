#pragma once

template<class T>
inline void parallel_quickSort(T* a, long nLength)
{
	unsigned long const min_per_thread = PARALLEL_QUICKSORT_MIN_PER_THREAD;
	unsigned long const max_threads = (nLength + min_per_thread - 1) / min_per_thread;
	const unsigned long nConcurrency = std::thread::hardware_concurrency();
	const unsigned long nThreads = std::min(nConcurrency != 0 ? nConcurrency : 2 , max_threads);
	const unsigned long nBlockSize = nLength / nThreads;

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
		threads[i] = std::thread(&quickSort<T>, a, nBlockSize);
		std::advance(a, nBlockSize);
	}
	quickSort(a, nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	std::sort(begin + nBlockSize*nThreads, begin + nLength);
	merge(begin, nBlockSize, nLength);
}
