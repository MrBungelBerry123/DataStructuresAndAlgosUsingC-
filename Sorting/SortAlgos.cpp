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

template <typename T>
void selectionSort(T *array, int len, int (*compareTo)(T&, T&) ) {
	bool swap = false;
	for (int i = 0, n = len - 1; i < n; i++) {
		int min = i;
		for (int firstUnsortedIndex = i + 1; firstUnsortedIndex < len; firstUnsortedIndex++) 
			if (compareTo(array[firstUnsortedIndex], array[min]) < 0) {
				min = firstUnsortedIndex;
				swap = true;
			}
		if (swap) {
			T temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			swap = false;
		}
	}
}

template <typename T>
void selectionSort(T *array, int len) {
	bool swap = false;
	for (int i = 0, n = len - 1; i < n; i++) {
		int min = i;
		for (int firstUnsortedIndex = i + 1; firstUnsortedIndex < len; firstUnsortedIndex++) 
			if (array[firstUnsortedIndex] < array[min]) {
				min = firstUnsortedIndex;
				swap = true;
			}
		if (swap) {
			T temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			swap = false;
		}
	}
}