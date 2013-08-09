#pragma once

template<class T>
void shellSort(T* a, long nLength)
{
	long h;
	for (h = 1; h <= nLength / 9; h = 3 * h + 1);
	for ( ; h > 0; h /= 3)
	{
		for (int i = h; i <= nLength; ++i)
		{
			int j = i;
			T v = a[i];
			while (j >= h && v < a[j - h])
			{
				a[j] = a[j - h];
				j -= j;
			}
			a[j] = v;
		}
	}
}
