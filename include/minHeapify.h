/*
* Author - Ritesh Saha
* C++ program to convert an array to min heap.
* Time Complexity - O(n)
*/	
#include <climits>

namespace algorithms {

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
					utils::Swap(array[minChild], array[parent]);
					parent = minChild;
				}
				else break;
				leftChild = 2 * parent + 1;
				rightChild = 2 * parent + 2;
			}
		}
	}

}