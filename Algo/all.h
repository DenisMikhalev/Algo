#pragma once

#define QUICKSORT_CUTOFF					10
#define QUICKSORT_MAXSTACK					2048
#define PARALLEL_QUICKSORT_CUTOFF			20
#define PARALLEL_QUICKSORT_MIN_PER_THREAD	40

#define PARALLEL_MERGESORT_CUTOFF			5
#define PARALLEL_MERGESORT_MIN_PER_THREAD	40

#define PARALLEL_SELECTSORT_CUTOFF			5
#define PARALLEL_SELECTSORT_MIN_PER_THREAD	10

#define PARALLEL_INSERTSORT_CUTOFF			5
#define PARALLEL_INSERTSORT_MIN_PER_THREAD	40

#include <algorithm>
#include <thread>
#include <future>
#include <random>

#include "mergesort.h"
#include "quicksort.h"
#include "insertsort.h"
#include "selectsort.h"

#include "parallel_mergesort.h"
#include "parallel_quicksort.h"
#include "parallel_insertsort.h"
#include "parallel_selectsort.h"

#include "utils.h"
