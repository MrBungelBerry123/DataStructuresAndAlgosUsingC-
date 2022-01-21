
#include "kadane.h"
#include <iostream>
#include <ctime>
#define MAX_SIZE 10
#define UPPER_BOUND 30
#define LOWER_BOUND -10

int main(void) {
	int array[MAX_SIZE];

	srand(time(0) );

	// Populate the array with random integers.
	for (int i = 0; i < MAX_SIZE; i++)
		array[i] = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;

	// Original array.
	for (int i = 0; i < MAX_SIZE; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	algo::tuple subArray = algo::maxSubArray(array, MAX_SIZE);

	std::cout << subArray.sum << std::endl;
	for (int i = subArray.left; i <= subArray.right; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	return 0;
}