/*
* Author - Ritesh Saha
* C++ program to convert an array to max heap.
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

}