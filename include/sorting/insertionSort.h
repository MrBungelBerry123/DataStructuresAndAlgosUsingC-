/*
* Author - Ritesh Saha
*
* Insertion Sort.
*
* Time Complexity - O(n^2)
* Space Complexity - O(1)
*/

namespace algorithms {
	/* 
	* Insertion sort sub-routine which accepts a function pointer as one of the arguments.
	* This function is meant for comparing two objects and its implementation 
	* is provided by the user. 
	* This sub-routine is for objects which donot override the '>' operator.
	*/
	template <typename T>
	static void insertionSort(T *array, int len, int (*compareTo)(T&, T&) ) {
		for (int firstUnsortedIndex = 1; firstUnsortedIndex < len; firstUnsortedIndex++) {
			T key = array[firstUnsortedIndex];
			int i = firstUnsortedIndex - 1;
			for (; i >= 0 && (*compareTo)(array[i], key) > 0; i--)
				array[i + 1] = array[i];
			array[i + 1] = key;
		}
	}

	/*
	* Insertion ort sub-routine for comparable objects.
	* That is, they override the '>' operator.
	*/
	template <typename T>
	static void insertionSort(T *array, int len) {
		for (int firstUnsortedIndex = 1; firstUnsortedIndex < len; firstUnsortedIndex++) {
			T key = array[firstUnsortedIndex];
			int i = firstUnsortedIndex - 1;
			for (; i >= 0 && array[i] > key; i--)
				array[i + 1] = array[i];
			array[i + 1] = key;
		}
	}

	/*
	* This sub-routine acts as a helper function for shellSort sub-routine.
	* It sorts the array based on the specified gap value.
	* This sub-routine also assumes that the objects are comparable.
	*/
	template <typename T>
	static void insertionSort(T *array, int len, int gap) {
		for (int firstUnsortedIndex = gap; firstUnsortedIndex < len; firstUnsortedIndex += gap) {
			T key = array[firstUnsortedIndex];
			int i = firstUnsortedIndex - gap;
			for (; i >= 0 && array[i] > key; i -= gap)
				array[i + gap] = array[i];
			array[i + gap] = key;
		}
	}

	/*
	* A helper function for shellSort for objects which donot override the '>' operator.
	*/
	template <typename T>
	static void insertionSort(T *array, int len, int (*compareTo)(T&, T&), int gap) {
		for (int firstUnsortedIndex = gap; firstUnsortedIndex < len; firstUnsortedIndex += gap) {
			T key = array[firstUnsortedIndex];
			int i = firstUnsortedIndex - gap;
			for (; i >= 0 && (*compareTo)(array[i], key) > 0; i -= gap)
				array[i + gap] = array[i];
			array[i + gap] = key;
		}
	}
	
}