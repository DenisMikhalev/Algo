#pragma once

template<class T>
inline void merge(T* pSrc, long nBlockSize, long nLength)
{
	if (nBlockSize >= nLength)
		return;

	T* pBegin = pSrc;
	T* pEnd = pSrc + nLength;

	int nBlocks = nLength / nBlockSize;
	for (int j = 1; j < nBlocks; ++j)
	{
		std::inplace_merge(pBegin, pBegin + j*nBlockSize, pBegin + (j + 1)*nBlockSize);
	}
	std::inplace_merge(pBegin, pBegin + nBlocks*nBlockSize, pBegin + nLength);
}

template<class T>
inline void merge(T* a, long lb, long split, long ub)
{
	long pos1 = lb;
	long pos2 = split+1;

	long pos3 = 0; 

	T* temp = new T[ub - lb + 1];

	while (pos1 <= split && pos2 <= ub)
	{
		if (a[pos1] < a[pos2])
			temp[pos3++] = a[pos1++];
		else
			temp[pos3++] = a[pos2++];
	}

	while (pos2 <= ub)		temp[pos3++] = a[pos2++];
	while (pos1 <= split)	temp[pos3++] = a[pos1++];

	for (pos3 = 0; pos3 < ub - lb + 1; ++pos3)
		a[lb + pos3] = temp[pos3];

	delete[] temp;
}

template<class T>
inline void mergeSort(T* a, long lb, long ub)
{ 
	if (lb < ub)
	{
		long split = (lb + ub) >> 1;

		mergeSort(a, lb, split);
		mergeSort(a, split + 1, ub);
		merge(a, lb, split, ub);
	}
}
