<<<<<<< HEAD
/*
* Author - Ritesh Saha
*
* Maximum sub-array problem.
*
* Kadane's algorithm
* 
* Time Complexity - O(n)
* Space Complexity - O(1)
*/
#ifndef _KADANE_H_
#define _KADANE_H_
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

#endif // _KADANE_H_
/*
* Kadane's algorithm

maxSubArray(A)
1 - sum = A[1]
2 - for i = 2 upto A.length
3 -		sum = sum + A[i]
4 -		sum = Max(sum, A[i])	

maxSubArray(A)
0 -	maxSum = -infinity
1 - max_left = max_right = left = right = 1
2 - sum = A[1]
3 - for i = 2 upto A.length
4 -		sum = sum + A[i]
5 - 	if sum >= A[i]
6 -			right = right + 1
7 -		if sum < A[i]
8 -			sum = A[i]
9 -			left = right = i
10-		if sum > maxSum
11- 		maxSum = sum
12-			max_left = left
13-			max_right = right
14-	return(max_left, max_right, maxSum)
=======
/*
* Author - Ritesh Saha
*
* Maximum sub-array problem.
*
* Kadane's algorithm
* 
* Time Complexity - O(n)
* Space Complexity - O(1)
*/
#ifndef _KADANE_H_
#define _KADANE_H_
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

#endif // _KADANE_H_
/*
* Kadane's algorithm

maxSubArray(A)
1 - sum = A[1]
2 - for i = 2 upto A.length
3 -		sum = sum + A[i]
4 -		sum = Max(sum, A[i])	

maxSubArray(A)
0 -	maxSum = -infinity
1 - max_left = max_right = left = right = 1
2 - sum = A[1]
3 - for i = 2 upto A.length
4 -		sum = sum + A[i]
5 - 	if sum >= A[i]
6 -			right = right + 1
7 -		if sum < A[i]
8 -			sum = A[i]
9 -			left = right = i
10-		if sum > maxSum
11- 		maxSum = sum
12-			max_left = left
13-			max_right = right
14-	return(max_left, max_right, maxSum)
>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
*/