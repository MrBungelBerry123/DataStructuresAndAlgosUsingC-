// Author - Ritesh Saha

// Insertion Sort.

namespace algorithms {

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