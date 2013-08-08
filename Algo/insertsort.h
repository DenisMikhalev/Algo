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

template<class T>
inline long binInsertFind(T* a, T x, long nLength)
{
	long r = nLength - 1;

	if (x < a[0])
		return 0;
	else if (x > a[r])
		return r;

	long l = 0;
	long c = r >> 1;
	T cx = a[c];

	while (true)
	{
		if (x < cx)
		{
			if (c - l <= 1)
				return c;
			r = c;
		}
		else
		{
			if (r - c <= 1)
				return c + 1;
			l = c;
		}
		c = l + ((r - l) >> 1);
		cx = a[c];
	}
}

template<class T>
void binInsertSort(T* a, long nLength)
{
	for (long i = 0; i < nLength; ++i)
	{
		if (a[i] <= a[i + 1])
			continue;

		T x = a[i + 1];
		long pos = binInsertFind(a, x, i + 1); 
		for (long j = i; j >= pos; --j)
		{
			a[j + 1] = a[j];
		}
		a[pos] = x;
	}
}
