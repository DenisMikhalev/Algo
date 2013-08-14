#pragma once

template<class T>
inline void downHeap(T* a, long k, long N)
{
	while(2*k <= N)
	{
		int j = 2*k;
		if(j < N && a[j] < a[j + 1])
			j++;

		if(a[k] >= a[j])
			break; 

		std::swap(a[k], a[j]);
		k = j;
	}
}
template<class T>
inline void heapSort(T* a, long nLength)
{
	for(long i = nLength / 2 - 1; i >= 0; --i)
		downHeap(a, i, nLength - 1);

	for(long i = nLength - 1; i > 0; --i)
	{
		std::swap(a[0], a[i]);
		downHeap(a, 0, i - 1);
	}
}
