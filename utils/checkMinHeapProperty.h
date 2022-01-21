<<<<<<< HEAD
/*
* Author - Ritesh Saha
* Cpp program to check if an array satisfies min heap property.
*/	
#ifndef _CHECK_MIN_PROPERTY_
#define _CHECK_MIN_PROPERTY_

namespace utils {

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

=======
/*
* Author - Ritesh Saha
* Cpp program to check if an array satisfies min heap property.
*/	
#ifndef _CHECK_MIN_PROPERTY_
#define _CHECK_MIN_PROPERTY_

namespace utils {

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

>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
#endif // _CHECK_MIN_PROPERTY_