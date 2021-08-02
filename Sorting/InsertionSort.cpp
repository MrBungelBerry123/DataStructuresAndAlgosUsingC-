template <typename T>
void insertionSort(T *array, int len, int (*compareTo)(T&, T&) ) {
	for (int firstUnsortedIndex = 1; firstUnsortedIndex < len; firstUnsortedIndex++) {
		T key = array[firstUnsortedIndex];
		int i = firstUnsortedIndex - 1;
		for (; i >= 0 && (*compareTo)(array[i], key) > 0; i--)
			array[i + 1] = array[i];
		array[i + 1] = key;
	}
}

template <typename T>
void insertionSort(T *array, int len) {
	for (int firstUnsortedIndex = 1; firstUnsortedIndex < len; firstUnsortedIndex++) {
		T key = array[firstUnsortedIndex];
		int i = firstUnsortedIndex - 1;
		for (; i >= 0 && array[i] > key; i--)
			array[i + 1] = array[i];
		array[i + 1] = key;
	}
}
