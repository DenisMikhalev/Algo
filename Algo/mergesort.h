#pragma once

template<class T>
inline void inplaceMerge(T* f, T* m, T* l)
{
	if (f == m || m == l)
		return;

	long len1 = m - f;
	long len2 = l - m;

	if (len1 + len2 == 2)
	{
		if (*m < *f)
			std::iter_swap(f, m);
		return;
	}

	T* first_cut = f;
	T* second_cut = m;

	long len11 = 0;
	long len22 = 0;

	if (len1 > len2)
	{
		len11 = len1 / 2;
		std::advance(first_cut, len11);
		second_cut = std::lower_bound(m, l, *first_cut);
		len22 = std::distance(m, second_cut);
	}
	else
	{
		len22 = len2 / 2;
		std::advance(second_cut, len22);
		first_cut = std::upper_bound(f, m, *second_cut);
		len11 = std::distance(f, first_cut);
	}

	std::rotate(first_cut, m, second_cut);
	T* new_middle = first_cut;
	std::advance(new_middle, std::distance(m, second_cut));
	inplaceMerge(f, first_cut, new_middle);
	inplaceMerge(new_middle, second_cut, l);
}

template<class T>
inline void merge(T* pSrc, long nBlockSize, long nLength)
{
	if (nBlockSize >= nLength)
		return;

	int nBlocks = nLength / nBlockSize;
	for (int j = 1; j < nBlocks; ++j)
	{
		std::inplace_merge(pSrc, pSrc + j*nBlockSize, pSrc + (j + 1)*nBlockSize);
		//inplaceMerge(pSrc, pSrc + j*nBlockSize, pSrc + (j + 1)*nBlockSize);
	}
	std::inplace_merge(pSrc, pSrc + nBlocks*nBlockSize, pSrc + nLength);
	//inplaceMerge(pSrc, pSrc + nBlocks*nBlockSize, pSrc + nLength);
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
