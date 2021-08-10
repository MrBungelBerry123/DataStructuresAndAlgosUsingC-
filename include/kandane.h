/*
* Author - Ritesh Saha
*
* Maximum sub-array problem.
*
* Kandane's algorithm
* 
* Time Complexity - O(n)
* Space Complexity - O(1)
*/

#include <climits>

namespace algorithms { 

	class tuple {
		public:
		int left, right, sum;
		tuple(int left = 0, int right = 0, int sum = 0) {
			this->left = left;
			this->right = right;
			this->sum = sum;
		}
	};

	template <typename T>
	static tuple maxSubArray(T *array, int len) {
		int maxSubArraySum = INT_MIN;
		int max_left = 0, max_right = 0, left = 0, right = 0;
		int sum = array[0];
		for (int i = 1; i < len; i++) {
			sum += array[i];
			if (sum >= array[i])
				right += 1;
			else {
				sum = array[i];
				left = i;
				right = i;
			}
			if (sum > maxSubArraySum) {
				maxSubArraySum = sum;
				max_left = left;
				max_right = right;
			}
		}
		return tuple(max_left, max_right, maxSubArraySum);
	}

}