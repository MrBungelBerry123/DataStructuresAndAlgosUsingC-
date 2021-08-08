// Author - Ritesh Saha

#include "insertionSort.h"

// Shell Sort
template <typename T>
static void shellSort(T *array, int len) {
	for (int gap = len / 2; gap > 0; gap /= 2)
		insertionSort(array, len, gap);
}

template <typename T>
static void shellSort(T *array, int len, int (*compareTo)(T&, T&) ) {
	for (int gap = len / 2; gap > 0; gap /= 2)
		insertionSort(array, len, compareTo, gap);
}