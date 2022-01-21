
/*
* Author - Ritesh Saha
*
* Shell sort
* Time Complexity - O(n^2)
* Time complexity can be improved by using a different sequence of gap values.
* Space Complexity - O(1)
*/

#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

namespace algo {

	// Sub-routine for comparable objects.
	template <typename T>
	static void shellSort(T *array, int len) {
		for (int gap = len / 2; gap > 0; gap /= 2) {
			// Insertion Sort
			for (int firstUnsortedIndex = gap; firstUnsortedIndex < len; firstUnsortedIndex += gap) {
				T key = array[firstUnsortedIndex];
				int i = firstUnsortedIndex - gap;
				for (; i >= 0 && array[i] > key; i -= gap)
					array[i + gap] = array[i];
				array[i + gap] = key;
			}
		}
	}

	// Sub-routine for non-comparable objects.
	template <typename T>
	static void shellSort(T *array, int len, int (*compareTo)(T&, T&) ) {
		for (int gap = len / 2; gap > 0; gap /= 2) {
			// Insertion Sort
			for (int firstUnsortedIndex = gap; firstUnsortedIndex < len; firstUnsortedIndex += gap) {
				T key = array[firstUnsortedIndex];
				int i = firstUnsortedIndex - gap;
				for (; i >= 0 && (*compareTo)(array[i], key) > 0; i -= gap)
					array[i + gap] = array[i];
				array[i + gap] = key;
			}
		}
	}
	
}

#endif // _SHELL_SORT_H_