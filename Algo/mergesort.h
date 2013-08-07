#pragma once

template<class T>
void merge(T* pSrc, long nBlockSize, long nLength)
{
	T* pBegin = pSrc;
	T* pEnd = pSrc + nLength;

	int nBlocks = nLength / nBlockSize;
	for (int j = 1; j < nBlocks; ++j)
	{
		std::inplace_merge(pBegin, pBegin + j*nBlockSize, pBegin + (j + 1)*nBlockSize);
	}

	long backSize = nLength - (nBlocks - 1)*nBlockSize;
	std::inplace_merge(pBegin, pBegin + nBlocks*nBlockSize, pBegin + nLength);
}
