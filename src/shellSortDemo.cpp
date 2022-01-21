
#include "shellSort.h"
#include <iostream>
#include <ctime>
#define MAX_SIZE 100
#define UPPER_BOUND 10000
#define LOWER_BOUND 1

inline void display(int *array) {
	for (int i = 0; i < MAX_SIZE; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int main(void) {
	int array[MAX_SIZE];

	srand(time(0) );

	// Populate the array with random integers.
	for (int i = 0; i < MAX_SIZE; i++)
		array[i] = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;

	std::cout << "Unsorted array: " << std::endl;
	display(array);

	algo::shellSort(array, MAX_SIZE);

	std::cout << "Sorted array: " << std::endl;
	display(array);

	return 0;
}