#pragma once

template<class T>
void insertSort(T* a, long nLength)
{
	for (long i = 0; i < nLength; ++i)
	{
		T x = a[i];

		long j;
		for (j = i - 1; j >= 0 && a[j] > x; --j)
			a[j + 1] = a[j];

		a[j + 1] = x;
	}
}

template<class T>
void insertSortGuarded(T* a, long nLength)
{
	for (long i = nLength - 1; i > 0; --i)
		if (a[i] < a[i - 1])
			std::swap(a[i],  a[i - 1]);

	for (long i = 2; i <= nLength; ++i)
	{
		long j = i;
		T x = a[i];
		while (x < a[j - 1])
		{
			a[j] = a[j - 1];
			--j;
		}
		a[j] = x;
	}
}
