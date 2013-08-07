#pragma once

template<class T>
void insertSort(T* a, long size)
{
	T x;
	long i, j;

	for (i = 0; i < size; ++i)
	{
		x = a[i];

		for (j = i - 1; j >= 0 && a[j] > x; --j)
			a[j + 1] = a[j];

		a[j + 1] = x;
	}
}
