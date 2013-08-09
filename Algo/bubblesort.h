#pragma once

template<class T>
inline void bubbleSort(T* a, long nLength)
{
	for(long i = 0; i < nLength; ++i)
	{
		bool isDone = true;
		for(long j = nLength - 1; j > i; --j)
		{
			if (a[j - 1] > a[j])
			{
				isDone = false;
				std::swap(a[j - 1], a[j]);
			}
		}

		if (isDone)
			break;
	}
}
