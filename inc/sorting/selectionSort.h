/*
* Author - Ritesh Saha
*
* Selection Sort
*
* Time Complexity - O(n^2)
* Space Complexity - O(1)
*/

#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

namespace algo {

	// Selection sort sub-routine for non-comparable objects.
	template <typename T>
	static void selectionSort(T *array, int len, int (*compareTo)(T&, T&) ) {
		bool swap = false;
		for (int i = 0, n = len - 1; i < n; i++) {
			int min = i;
			for (int firstUnsortedIndex = i + 1; firstUnsortedIndex < len; firstUnsortedIndex++) 
				if (compareTo(array[firstUnsortedIndex], array[min]) < 0) {
					min = firstUnsortedIndex;
					swap = true;
				}
			// Swap only if an element smaller than array[i] is found.
			if (swap) {
				T temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				swap = false;
			}
		}
	}

	// Selection sort sub-routine for comparable objects.
	template <typename T>
	static void selectionSort(T *array, int len) {
		bool swap = false;
		for (int i = 0, n = len - 1; i < n; i++) {
			int min = i;
			for (int firstUnsortedIndex = i + 1; firstUnsortedIndex < len; firstUnsortedIndex++) 
				if (array[firstUnsortedIndex] < array[min]) {
					min = firstUnsortedIndex;
					swap = true;
				}
			if (swap) {
				T temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				swap = false;
			}
		}
	}

}

#endif // _SELECTION_SORT_H_