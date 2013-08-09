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

void fillVector(std::vector<unsigned int>& dst, int countElem)
{
	dst.clear();
	for (int i = 0; i < countElem; ++i)
	{
		// 		std::random_device randDev;
		// 		std::default_random_engine eng(randDev());
		// 		std::uniform_int_distribution<unsigned int> uniform_dist(1, INT_MAX);
		// 		dst.push_back(uniform_dist(eng)

		dst.push_back(rand() % RAND_MAX);
	}
}
