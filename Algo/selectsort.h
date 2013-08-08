#pragma once

template<class T>
inline void selectSort(T* a, long nLength)
{
	for(int i = 0; i < nLength; ++i)
	{
		int min = i;
		for(int j = i + 1; j <= nLength; ++j)
		{
			if (a[j] < a[min])
				min = j;
		}
		std::swap(a[i], a[min]);
	}
}

template<class T>
inline void selectBiSort(T* a, long nLength)
{
	for(int i = 0, k = nLength - 1; i < nLength; ++i, --k)
	{
		int min = i;
		int max = k;

		if (k - i <= 0)
			break;

		for(int j = i; j <= k; ++j)
		{
			if (a[min] > a[j]) min = j;
			if (a[max] < a[j]) max = j;
		}

		if (min != i)
		{
			std::swap(a[min], a[i]);
			if (max == i) max = min;
		}

		if (max != k)
			std::swap(a[max], a[k]);
	}
}
