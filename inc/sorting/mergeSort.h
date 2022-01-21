/*
* Author - Ritesh Saha
*
* Merge Sort
*
* Time Complexity - O(nlogn)
* Space Complexity - O(n)
*/

#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

namespace algo {
	/*
	* The merge sub-routine assumes that the two sub-arrays are already sorted
	* and the objects are comparable..
	*/
	template <typename T>
	static void merge(T *array, int startIndex, int mid, int endIndex) {
		// End the merge sub-routine if the sub-arrays are already sorted.
		if (array[mid] <= array[mid + 1])
			return;
		int i = startIndex, j = mid + 1, index = 0;
		// Creating a temporary array for storing the sorted sub-array.
		T temp[endIndex - startIndex + 1]; 
		while (i <= mid && j <= endIndex) 
			temp[index++] = (array[i] <= array[j]) ? array[i++] : array[j++];
		for (; i <= mid; i++)
			temp[index++] = array[i];
		for (; j <= endIndex; j++)
			temp[index++] = array[j];
		// Copy the elements of temp back to the original array.
		for (int k = startIndex; k <= endIndex; k++)
			array[k] = temp[k - startIndex];
		return;
	}

	/*
	* The split sub-routine recursively partitions the array into two halves.
	*/
	template <typename T>
	static void split(T *array, int startIndex, int endIndex) {
		// Return if the array contains only 1 element.
		if (startIndex == endIndex)
			return;
		int mid = (startIndex + endIndex) / 2;
		// Sort the left half.
		split(array, startIndex, mid);
		// Sort the right half.
		split(array, mid + 1, endIndex);
		// Merge the sorted halves.
		merge(array, startIndex, mid, endIndex);
	}

	// Helper fuction.
	template <typename T>
	static void mergeSort(T *array, int len) {
		split(array, 0, len - 1);
		return;
	}

	// Following is the implementation of merge-sort for non-comparable objects.
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

#endif // _MERGE_SORT_H_