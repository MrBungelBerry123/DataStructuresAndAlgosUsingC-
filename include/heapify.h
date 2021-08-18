/*
* Author - Ritesh Saha
* 
* Heapify implementation in cpp.
*
* Time Complexity - O(n)
*/

#include <climits>

namespace algorithms {

	template <typename T>
	inline void Swap(T &j, T &i) {
		T temp = j;
		j = i;
		i = temp;
	}

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
					Swap(array[maxChild], array[parent]);
					parent = maxChild;
				}
				else break;
				leftChild = 2 * parent + 1;
				rightChild = 2 * parent + 2;
			}
		}
	}

	template <typename T>
	static void minHeapify(T *array, int len) {
		for (int i = len / 2; i >= 0; i--) {
			int leftChild = 2 * i + 1;
			int rightChild = 2 * i + 2;
			int parent = i;
			// Bubble down
			while (leftChild < len) {
				int leftValue = array[leftChild];
				int rightValue = (rightChild < len) ? array[rightChild] : INT_MAX;
				int minChild = (leftValue <= rightValue) ? leftChild : rightChild;
				if (array[minChild] < array[parent]) {
					Swap(array[minChild], array[parent]);
					parent = minChild;
				}
				else break;
				leftChild = 2 * parent + 1;
				rightChild = 2 * parent + 2;
			}
		}
	}

	// Utility functions
	template <typename T>
	static bool checkMaxHeapProperty(T *array, int len) {
		for (int i = 0; i < len; i++) {
			int leftChild = 2 * i + 1;
			int rightChild = 2 * i + 2;

			int leftValue = (leftChild < len) ? array[leftChild] : INT_MIN;
			int rightValue = (rightChild < len) ? array[rightChild] : INT_MIN;

			if (array[i] < leftValue || array[i] < rightValue) 
				return false;
		}
		return true;
	}

	template <typename T>
	static bool checkMinHeapProperty(T *array, int len) {
		for (int i = 0; i < len; i++) {
			int leftChild = 2 * i + 1;
			int rightChild = 2 * i + 2;

			int leftValue = (leftChild < len) ? array[leftChild] : INT_MAX;
			int rightValue = (rightChild < len) ? array[rightChild] : INT_MAX;

			if (array[i] > leftValue || array[i] > rightValue) 
				return false;
		}
		return true;
	}

}