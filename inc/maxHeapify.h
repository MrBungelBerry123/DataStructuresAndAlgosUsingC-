<<<<<<< HEAD
/*
* Author - Ritesh Saha
* C++ program to convert an array to max heap.
* Time Complexity - O(n)
*/

#ifndef _MAX_HEAPIFY_
#define _MAX_HEAPIFY_
#include "swap.h"
#include <climits>

namespace algo {

	template <typename T>
	static void maxHeapify(T *array, int len) {
		for (int i = len / 2; i >= 0; i--) {
			int leftChild = 2 * i + 1;
			int rightChild = 2 * i + 2;
			int parent = i;
			// Bubble down
			while (leftChild < len) {
				int leftValue = array[leftChild];
				int rightValue = (rightChild < len) ? array[rightChild] : INT_MIN;
				int maxChild = (leftValue >= rightValue) ? leftChild : rightChild;
				if (array[maxChild] > array[parent]) {
					utils::swap(array[maxChild], array[parent]);
					parent = maxChild;
				}
				else break;
				leftChild = 2 * parent + 1;
				rightChild = 2 * parent + 2;
			}
		}
	}

}

=======
/*
* Author - Ritesh Saha
* C++ program to convert an array to max heap.
* Time Complexity - O(n)
*/

#ifndef _MAX_HEAPIFY_
#define _MAX_HEAPIFY_
#include "swap.h"
#include <climits>

namespace algo {

	template <typename T>
	static void maxHeapify(T *array, int len) {
		for (int i = len / 2; i >= 0; i--) {
			int leftChild = 2 * i + 1;
			int rightChild = 2 * i + 2;
			int parent = i;
			// Bubble down
			while (leftChild < len) {
				int leftValue = array[leftChild];
				int rightValue = (rightChild < len) ? array[rightChild] : INT_MIN;
				int maxChild = (leftValue >= rightValue) ? leftChild : rightChild;
				if (array[maxChild] > array[parent]) {
					utils::swap(array[maxChild], array[parent]);
					parent = maxChild;
				}
				else break;
				leftChild = 2 * parent + 1;
				rightChild = 2 * parent + 2;
			}
		}
	}

}

>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
#endif // _MAX_HEAPIFY_