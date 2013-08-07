#pragma once

template<class T>
inline void quickSortCutoff(T* a, long nLength)
{
	_qsortCutoff(a, nLength - 1);
	insertSort(a, nLength);
}

template<class T>
inline void _qsortCutoff(T* a, long nLength)
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

	if (j > QUICKSORT_CUTOFF) quickSort(a, j + 1);
	if (nLength > i + QUICKSORT_CUTOFF) quickSort(a + i, nLength - i);
}

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

template<class T>
void quickSortNotR(T* a, long size)
{
	long i, j;
	long lb, ub;

	long lbstack[QUICKSORT_MAXSTACK];
	long ubstack[QUICKSORT_MAXSTACK];

	long stackpos = 1;
	long ppos;

	T pivot;
	T temp;

	lbstack[1] = 0;
	ubstack[1] = size-1;

	do
	{
		lb = lbstack[stackpos];
		ub = ubstack[stackpos];
		stackpos--;

		do
		{
			ppos = (lb + ub) >> 1;
			i = lb;
			j = ub;
			pivot = a[ppos];

			while ( i <= j )
			//do
			{
				while ( a[i] < pivot ) i++;
				while ( pivot < a[j] ) j--;

				if ( i <= j )
				{
					std::swap(a[i], a[j]);
					i++;
					j--;
				}
			} //while ( i <= j );

			if (i < ppos)
			{
				if (i < ub)
				{
					++stackpos;
					lbstack[ stackpos ] = i;
					ubstack[ stackpos ] = ub;
				}
				ub = j;
			}
			else
			{
				if ( j > lb )
				{
					++stackpos;
					lbstack[ stackpos ] = lb;
					ubstack[ stackpos ] = j;
				}
				lb = i;
			}
		} while ( lb < ub );
	} while ( stackpos != 0 );
}
