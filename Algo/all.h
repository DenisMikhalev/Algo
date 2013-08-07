#pragma once

#define QUICKSORT_CUTOFF					10
#define QUICKSORT_MAXSTACK					2048

#define PARALLEL_QUICKSORT_CUTOFF			20
#define PARALLEL_QUICKSORT_MIN_PER_THREAD	40

#include <algorithm>
#include <thread>
#include <future>

#include "mergesort.h"
#include "quicksort.h"
#include "parallel_quicksort.h"
#include "insertsort.h"
