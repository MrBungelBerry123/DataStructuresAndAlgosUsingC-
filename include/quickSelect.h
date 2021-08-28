/*
* Author - Ritesh Saha
* C++ implementation of quickselect algorithm.
* Finding the kth smallest element in O(n) time.
*/

namespace algorithms {

	template <typename T>
	inline void Swap(T &j, T &i) {
		T temp = j;
		j = i;
		i = temp;
	}

	// Randomized Lomuto's partition scheme.
	template <typename T>
	static int partition(T *array, int left, int right) {
		// Randomly choose a pivot.
		// The probability of choosing any element belonging to the array is 1 / array.length.
		srand(time(0) );
		int pivot = rand() % (right - left + 1) + left;
		Swap(array[right], array[pivot]);
		// The right most element is the pivot.
		int i = left - 1;
		for (int j = left; j < right; j++) 
			if (array[j] <= array[right])
				Swap(array[j], array[++i]);
		Swap(array[i + 1], array[right]);
		return i + 1; // Correct sorted index of pivot.
	}

	// Recursive implementation of quick select sub-routine.
	template <typename T>
	static int quickSelect(T *array, int left, int right, int k) {
		int position = partition(array, left, right);
		// Found the kth smallest element.
		if (position == k) 
			return position;
		// Look for the element in the left partition.
		else if (position > k)
			return quickSelect(array, left, position - 1, k);
		// Look for the element in the right partition.
		else
			return quickSelect(array, position + 1, right, k);
	}
	
	// Iterative implementation of quick select sub-routine.
	template <typename T>
	static int quickSelectIterative(T *array, int len, int k) {
		k -= 1; // Recall we programmers start counting from 0 unlike non-programmers(heathens).
		int left = 0, right = len - 1;
		int position = partition(array, left, right);
		while (position != k) {
			if (position > k)
				right = position - 1;
			else if (position < k)
				left = position + 1;
			position = partition(array, left, right);
		}
		return position;
	}

	// Helper function.
	template <typename T>
	static int quickSelect(T *array, int len, int k) {
		return quickSelect(array, 0, len - 1, k - 1);
	}

}