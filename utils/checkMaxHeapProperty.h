/*
* Author - Ritesh Saha
* Cpp function to check if an array satifies max heap property.
*/
#ifndef _CHECK_MAX_PROPERTY_
#define _CHECK_MAX_PROPERTY_

namespace utils {

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
	
}

#endif // _CHECK_MAX_PROPERTY_