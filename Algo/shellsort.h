#pragma once

template<class T>
void shellSort(T* a, long nLength)
{
	long h;
	for (h = 1; h <= nLength / 3; h = 3 * h + 1);
	for ( ; h > 0; h /= 3)
	{
		for (int i = h; i <= nLength; ++i)
		{
			for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
			{
				std::swap(a[j], a[j - h]);
			}
		}
	}
}
