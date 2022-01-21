<<<<<<< HEAD
/*
* Author - Ritesh Saha
*
* Maximum sub-array problem.
*
* This algorithm is taken from Introduction to algorithms, 3rd edition (CRCT) chapter 4.
* 
* Finding the maximum sub-array in O(nlogn) time complexity.
* Time Complexity - O(nlogn)
*/

#ifndef _MAX_CONTIGOUS_SUB_ARRAY_
#define _MAX_CONTIGOUS_SUB_ARRAY_
#include <climits>

namespace algo {

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
	static tuple findMaxCrossingSubArray(T *array, int left, int mid, int right) {
		int max_left = 0, max_right = 0;
		int left_sum = INT_MIN;
		int sum = 0;
		for (int i = mid; i >= left; i--) {
			sum += array[i];
			if (sum > left_sum) {
				left_sum = sum;
				max_left = i;
			}
		}
		int right_sum = INT_MIN;
		sum = 0;
		for (int j = mid + 1; j <= right; j++) {
			sum += array[j];
			if (sum > right_sum) {
				right_sum = sum;
				max_right = j;
			}
		}
		return tuple(max_left, max_right, left_sum + right_sum);
	}

	template <typename T>
	static tuple findMaximumSubArray(T* array, int left, int right) {
		if (left == right)
			return tuple(left, right, array[left]);
		int mid = (left + right) / 2;
		tuple leftHalf = findMaximumSubArray(array, left, mid);
		tuple rightHalf = findMaximumSubArray(array, mid + 1, right);
		tuple crossOver = findMaxCrossingSubArray(array, left, mid, right);

		if (leftHalf.sum >= rightHalf.sum && leftHalf.sum >= crossOver.sum)
			return leftHalf;
		else if (rightHalf.sum >= leftHalf.sum && rightHalf.sum >= crossOver.sum)
			return rightHalf;
		return crossOver;
	}

	template <typename T>
	static tuple findMaximumSubArray(T* array, int len) {
		return findMaximumSubArray(array, 0, len - 1);
	}
	
}

#endif // _MAX_CONTIGOUS_SUB_ARRAY_
/*
Pseudocode:

Find-Max-Crossing-Subarray(A, left, mid, right)
1 - left_sum = -infinity
2 - sum = 0
3 - for i = mid downto left
4 -		sum = sum + A[i]
5 -		if sum > left_sum
6 -			left_sum = sum
7 -			max-left = i
8 -	right_sum = -infinity
9 - sum = 0
10 - for j = mid + 1 upto high
11 -	sum = sum + A[i]
12 -    if sum > right_sum
13 -		right_sum = sum
14 -		max-right = j
13 -return(max-left, max-right, left_sum + right_sum)


Find-Maximum-Subarray(A, left, right)
1 - if left == right
2 -		return(left, right, A[left])
3 -	else mid = (left + right) / 2
4 -		(left-low, left-high, left-sum) = Find-Maximum-Subarray(A, left, mid)
5 -		(right-low, right-high, right-sum) = Find-Maximum-Subarray(A, mid + 1, right)
6 -		(cross-left, cross-right-cross-sum) = Find-Max-Crossing-Subarray(A, left, mid, right)
7 - 	if left-sum >= right-sum and left-sum >= cross-sum
8 -			return (left-low, left-high, left-sum)
9 -		else right-sum > left-sum and right-sum > cross-sum
10 -		return (right-low, right-high, right-sum)
11 -	return (cross-left, cross-high, cross-sum)

=======
/*
* Author - Ritesh Saha
*
* Maximum sub-array problem.
*
* This algorithm is taken from Introduction to algorithms, 3rd edition (CRCT) chapter 4.
* 
* Finding the maximum sub-array in O(nlogn) time complexity.
* Time Complexity - O(nlogn)
*/

#ifndef _MAX_CONTIGOUS_SUB_ARRAY_
#define _MAX_CONTIGOUS_SUB_ARRAY_
#include <climits>

namespace algo {

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
	static tuple findMaxCrossingSubArray(T *array, int left, int mid, int right) {
		int max_left = 0, max_right = 0;
		int left_sum = INT_MIN;
		int sum = 0;
		for (int i = mid; i >= left; i--) {
			sum += array[i];
			if (sum > left_sum) {
				left_sum = sum;
				max_left = i;
			}
		}
		int right_sum = INT_MIN;
		sum = 0;
		for (int j = mid + 1; j <= right; j++) {
			sum += array[j];
			if (sum > right_sum) {
				right_sum = sum;
				max_right = j;
			}
		}
		return tuple(max_left, max_right, left_sum + right_sum);
	}

	template <typename T>
	static tuple findMaximumSubArray(T* array, int left, int right) {
		if (left == right)
			return tuple(left, right, array[left]);
		int mid = (left + right) / 2;
		tuple leftHalf = findMaximumSubArray(array, left, mid);
		tuple rightHalf = findMaximumSubArray(array, mid + 1, right);
		tuple crossOver = findMaxCrossingSubArray(array, left, mid, right);

		if (leftHalf.sum >= rightHalf.sum && leftHalf.sum >= crossOver.sum)
			return leftHalf;
		else if (rightHalf.sum >= leftHalf.sum && rightHalf.sum >= crossOver.sum)
			return rightHalf;
		return crossOver;
	}

	template <typename T>
	static tuple findMaximumSubArray(T* array, int len) {
		return findMaximumSubArray(array, 0, len - 1);
	}
	
}

#endif // _MAX_CONTIGOUS_SUB_ARRAY_
/*
Pseudocode:

Find-Max-Crossing-Subarray(A, left, mid, right)
1 - left_sum = -infinity
2 - sum = 0
3 - for i = mid downto left
4 -		sum = sum + A[i]
5 -		if sum > left_sum
6 -			left_sum = sum
7 -			max-left = i
8 -	right_sum = -infinity
9 - sum = 0
10 - for j = mid + 1 upto high
11 -	sum = sum + A[i]
12 -    if sum > right_sum
13 -		right_sum = sum
14 -		max-right = j
13 -return(max-left, max-right, left_sum + right_sum)


Find-Maximum-Subarray(A, left, right)
1 - if left == right
2 -		return(left, right, A[left])
3 -	else mid = (left + right) / 2
4 -		(left-low, left-high, left-sum) = Find-Maximum-Subarray(A, left, mid)
5 -		(right-low, right-high, right-sum) = Find-Maximum-Subarray(A, mid + 1, right)
6 -		(cross-left, cross-right-cross-sum) = Find-Max-Crossing-Subarray(A, left, mid, right)
7 - 	if left-sum >= right-sum and left-sum >= cross-sum
8 -			return (left-low, left-high, left-sum)
9 -		else right-sum > left-sum and right-sum > cross-sum
10 -		return (right-low, right-high, right-sum)
11 -	return (cross-left, cross-high, cross-sum)

>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
*/