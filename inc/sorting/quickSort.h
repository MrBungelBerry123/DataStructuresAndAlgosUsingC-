
/*
* Author - Ritesh Saha
* 
* Randomized Quick sort algorithm
* 
* Average case time complexity: O(nlogn)
*/

#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_
#include <ctime>
#include <stdlib.h>
#include "swap.h"

namespace algo {

	// Randomized Lomuto's partition scheme.
	template <typename T>
	static int partition(T *array, int left, int right) {
		// Randomly choose a pivot.
		// The probability of choosing any element belonging to the array is 1 / array.length.
		srand(time(0) );
		int pivot = rand() % (right - left + 1) + left;
		utils::swap(array[right], array[pivot]);
		// The right most element is the pivot.
		int i = left - 1;
		for (int j = left; j < right; j++) 
			if (array[j] <= array[right])
				utils::swap(array[j], array[++i]);
		utils::swap(array[i + 1], array[right]);
		return i + 1; // Correct sorted index of pivot.
	}

	// Recursively partition the array.
	template <typename T>
	static void quickSort(T *array, int left, int right) {
		// Return if the array consists of 1 or no elements.
		if (right <= left) 
			return;
		// Find the sorted index of the pivot.
		int position = partition(array, left, right);
		// Partition the left region.
		quickSort(array, left, position - 1);
		// Partition the right region.
		quickSort(array, position + 1, right);
		return;
	}

	// Helper function.
	template <typename T>
	static void quickSort(T *array, int len) {
		quickSort(array, 0, len - 1);
		return;
	}
	
}

#endif // _QUICK_SORT_H_