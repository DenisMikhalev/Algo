#pragma once

template<class T>
void parallel_insertSort(T* a, long nLength)
{
	const unsigned long nThreads = getCountThreads(nLength, PARALLEL_INSERTSORT_MIN_PER_THREAD);
	const unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_INSERTSORT_CUTOFF)
	{
		insertSort(a, nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&insertSort<T>, a + i*nBlockSize, nBlockSize);
	}
	insertSort(a + (nThreads - 1)*nBlockSize, nLength - (nThreads - 1)*nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(begin, nBlockSize, nLength);
}

template<class T>
void parallel_insertSortGuarded(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_INSERTSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_INSERTSORT_CUTOFF)
	{
		insertSortGuarded(a, nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&insertSortGuarded<T>, a + i*nBlockSize, nBlockSize - 1);
	}
	insertSortGuarded(a + (nThreads - 1)*nBlockSize, nLength - (nThreads - 1)*nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(begin, nBlockSize, nLength);
}

template<class T>
void parallel_binInsertSort(T* a, long nLength)
{
	unsigned long nThreads = getCountThreads(nLength, PARALLEL_INSERTSORT_MIN_PER_THREAD);
	unsigned long nBlockSize = getBlocksSize(nLength, nThreads);

	T* begin = a;
	if (nBlockSize < PARALLEL_INSERTSORT_CUTOFF)
	{
		binInsertSort(a, nLength);
		return;
	}

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < (nThreads - 1); ++i)
	{
		threads[i] = std::thread(&binInsertSort<T>, a + i*nBlockSize, nBlockSize - 1);
	}
	binInsertSort(a + (nThreads - 1)*nBlockSize, nLength - (nThreads - 1)*nBlockSize);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	merge(begin, nBlockSize, nLength);
}
