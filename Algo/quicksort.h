#pragma once

template<class T>
inline void quickSort(T* a, long nLength)
{
	if (nLength < 2)
		return;

	long i = 0, j = nLength - 1;
	T p = a[nLength >> 1];

	while (i <= j)
	{
		while (a[i] < p) i++;
		while (a[j] > p) j--;

		if (i <= j)
		{
			if (i < j) std::swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (j > 0) quickSort(a, j + 1);
	if (nLength > i) quickSort(a + i, nLength - i);
}
