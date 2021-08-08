// Author - Ritesh Saha

// Merge Sort

namespace algorithms {

	template <typename T>
	static void merge(T *array, int startIndex, int mid, int endIndex) {
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
	static void split(T *array, int startIndex, int endIndex) {
		if (startIndex == endIndex)
			return;
		int mid = (startIndex + endIndex) / 2;
		split(array, startIndex, mid);
		split(array, mid + 1, endIndex);
		merge(array, startIndex, mid, endIndex);
	}

	template <typename T>
	static void mergeSort(T *array, int len) {
		split(array, 0, len - 1);
		return;
	}


	template <typename T>
	static void merge(T *array, int startIndex, int mid, int endIndex, int(*compareTo)(T&, T&) ) {
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
	static void split(T *array, int startIndex, int endIndex, int(*compareTo)(T&, T&) ) {
		if (startIndex == endIndex)
			return;
		int mid = (startIndex + endIndex) / 2;
		split(array, startIndex, mid, compareTo);
		split(array, mid + 1, endIndex, compareTo);
		merge(array, startIndex, mid, endIndex, compareTo);
	}

	template <typename T>
	static void mergeSort(T *array, int len, int(*compareTo)(T&, T&) ) {
		split(array, 0, len - 1, compareTo);
		return;
	}

}