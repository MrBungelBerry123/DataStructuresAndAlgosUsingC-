<<<<<<< HEAD
#include "maxHeapify.h"
#include "checkMaxHeapProperty.h"
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

	std::cout << "Unheapified array: " << std::endl;
	display(array);

	algo::maxHeapify(array, MAX_SIZE);

	std::cout << "Heapified array: " << std::endl;
	display(array);

	bool isHeap = utils::checkMaxHeapProperty(array, MAX_SIZE);

	if (isHeap)
		std::cout << "Is a heap." << std::endl;
	else
		std::cout << "Is not a heap." << std::endl;

	return 0;
=======
#include "maxHeapify.h"
#include "checkMaxHeapProperty.h"
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

	std::cout << "Unheapified array: " << std::endl;
	display(array);

	algo::maxHeapify(array, MAX_SIZE);

	std::cout << "Heapified array: " << std::endl;
	display(array);

	bool isHeap = utils::checkMaxHeapProperty(array, MAX_SIZE);

	if (isHeap)
		std::cout << "Is a heap." << std::endl;
	else
		std::cout << "Is not a heap." << std::endl;

	return 0;
>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
}