/*
* Author - Ritesh Saha
*
* Shell sort
* Time Complexity - O(n^2)
* Time complexity can be improved by using a different sequence of gap values.
* Space Complexity - O(1)
*/

#include "insertionSort.h"

namespace algorithms {

	// Sub-routine for comparable objects.
	template <typename T>
	static void shellSort(T *array, int len) {
		for (int gap = len / 2; gap > 0; gap /= 2)
			insertionSort(array, len, gap);
	}

	// Sub-routine for non-comparable objects.
	template <typename T>
	static void shellSort(T *array, int len, int (*compareTo)(T&, T&) ) {
		for (int gap = len / 2; gap > 0; gap /= 2)
			insertionSort(array, len, compareTo, gap);
	}

}