// Author - Ritesh Saha

// Insertion Sort.
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
void insertionSort(T *array, int len, int gap) {
	for (int firstUnsortedIndex = gap; firstUnsortedIndex < len; firstUnsortedIndex += gap) {
		T key = array[firstUnsortedIndex];
		int i = firstUnsortedIndex - gap;
		for (; i >= 0 && array[i] > key; i -= gap)
			array[i + gap] = array[i];
		array[i + gap] = key;
	}
}

template <typename T>
void insertionSort(T *array, int len, int (*compareTo)(T&, T&), int gap) {
	for (int firstUnsortedIndex = gap; firstUnsortedIndex < len; firstUnsortedIndex += gap) {
		T key = array[firstUnsortedIndex];
		int i = firstUnsortedIndex - gap;
		for (; i >= 0 && (*compareTo)(array[i], key) > 0; i -= gap)
			array[i + gap] = array[i];
		array[i + gap] = key;
	}
}


// Shell Sort
template <typename T>
void shellSort(T *array, int len) {
	for (int gap = len / 2; gap > 0; gap /= 2)
		insertionSort(array, len, gap);
}

template <typename T>
void shellSort(T *array, int len, int (*compareTo)(T&, T&) ) {
	for (int gap = len / 2; gap > 0; gap /= 2)
		insertionSort(array, len, compareTo, gap);
}


// Selection Sort
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


// Merge Sort
template <typename T>
void merge(T *array, int startIndex, int mid, int endIndex) {
	if (array[mid] <= array[mid + 1])
		return;
	int i = startIndex, j = mid + 1, index = 0;
	T temp[endIndex - startIndex + 1];
	while (i <= mid && j <= endIndex) 
		temp[index++] = (array[i] <= array[j]) ? array[i++] : array[j++];
	for (; i <= mid; i++)
		temp[index++] = array[i];
	for (; j <= endIndex; j++)
		temp[index++] = array[j];
	for (int k = startIndex; k <= endIndex; k++)
		array[k] = temp[k - startIndex];
	return;
}

template <typename T>
void split(T *array, int startIndex, int endIndex) {
	if (startIndex == endIndex)
		return;
	int mid = (startIndex + endIndex) / 2;
	split(array, startIndex, mid);
	split(array, mid + 1, endIndex);
	merge(array, startIndex, mid, endIndex);
}

template <typename T>
void mergeSort(T *array, int len) {
	split(array, 0, len - 1);
	return;
}


template <typename T>
void merge(T *array, int startIndex, int mid, int endIndex, int(*compareTo)(T&, T&) ) {
	if ((*compareTo)(array[mid], array[mid + 1]) <= 0)
		return;
	int i = startIndex, j = mid + 1, index = 0;
	T temp[endIndex - startIndex + 1];
	while (i <= mid && j <= endIndex) 
		temp[index++] = ((*compareTo)(array[i], array[j]) <= 0) ? array[i++] : array[j++];
	for (; i <= mid; i++)
		temp[index++] = array[i];
	for (; j <= endIndex; j++)
		temp[index++] = array[j];
	for (int k = startIndex; k <= endIndex; k++)
		array[k] = temp[k - startIndex];
	return;
}

template <typename T>
void split(T *array, int startIndex, int endIndex, int(*compareTo)(T&, T&) ) {
	if (startIndex == endIndex)
		return;
	int mid = (startIndex + endIndex) / 2;
	split(array, startIndex, mid, compareTo);
	split(array, mid + 1, endIndex, compareTo);
	merge(array, startIndex, mid, endIndex, compareTo);
}

template <typename T>
void mergeSort(T *array, int len, int(*compareTo)(T&, T&) ) {
	split(array, 0, len - 1, compareTo);
	return;
}