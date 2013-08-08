#include "utils.h"

#include <algorithm>
#include <thread>

unsigned long getCountThreads(unsigned long nLength, unsigned long min_per_thread)
{
	const unsigned long max_threads = (nLength + min_per_thread - 1) / min_per_thread;
	const unsigned long nConcurrency = std::thread::hardware_concurrency();
	return std::min(nConcurrency != 0 ? nConcurrency : 2 , max_threads);
}

unsigned long getBlocksSize(unsigned long nLength, unsigned long nThreads)
{
	return nLength / nThreads;
}
