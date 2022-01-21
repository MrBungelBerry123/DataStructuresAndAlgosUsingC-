/*
* Author - Ritesh Saha
* 
* Heap sort implementation in cpp.
*
* Time Complexity - O(nlogn)
*/

#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_
#include "maxHeapify.h"
#include "swap.h"
#include <climits>

namespace algo {

	template <typename T>
	static void bubbleDown(T *array, int parent, int end) {
		T temp = array[parent];
		int leftChild = 2 * parent + 1;
		int rightChild = 2 * parent + 2;
		while (leftChild <= end) {
			T leftValue = array[leftChild];
			T rightValue = (rightChild <= end) ? array[rightChild] : INT_MIN;
			T maxChild = (leftValue >= rightValue) ? leftChild : rightChild;
			if (array[maxChild] > temp) {
				array[parent] = array[maxChild];
				parent = maxChild;
			} 
			else break;
			leftChild = 2 * parent + 1;
			rightChild = 2 * parent + 2;
		}
		array[parent] = temp;
	}

	template <typename T>
	static void heapSort(T *array, int len) {
		algo::maxHeapify(array ,len);
		utils::swap(array[0], array[len - 1]);
		for (int i = len - 2; i > 0; i--) {
			bubbleDown(array, 0, i);
			utils::swap(array[0], array[i]);
		}
	}

}

#endif // _HEAP_SORT_H_