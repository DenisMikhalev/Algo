#pragma once

#include <vector>

unsigned long getCountThreads(unsigned long, unsigned long);
unsigned long getBlocksSize(unsigned long, unsigned long);

void fillVector(std::vector<unsigned int>&, int);

template<class T>
void isOrdered(std::vector<T>& src)
{
	const unsigned long nThreads = getCountThreads(src.size(), 1);
	const unsigned long nBlockSize = getBlocksSize(src.size(), nThreads);

	std::vector<std::thread> threads(nThreads - 1);
	for(unsigned long i = 0; i < nThreads - 1; ++i)
	{
		threads[i] = std::thread([=](){
			long nPos = i*nBlockSize;
			for (int j = nPos + 1; j < nPos + nBlockSize - 1; ++j)
			{
				if (src[j - 1] > src[j])
					std::cout << "Wrong order! Index:" << j << " Prev:" << src[j - 1] << " Cur:" << src[j] << std::endl;
			}
		});
	}

	for (int i = (nThreads - 1)*nBlockSize; i < src.size(); ++i)
	{
		if (src[i - 1] > src[i])
			std::cout << "Wrong order! Index:" << i << " Prev:" << src[i - 1] << " Cur:" << src[i] << std::endl;
	}

	for (int i = nBlockSize; i < src.size(); i += nBlockSize)
	{
		if (src[i - 1] > src[i])
			std::cout << "Wrong order! Index:" << i << " Prev:" << src[i - 1] << " Cur:" << src[i] << std::endl;
	}

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}
