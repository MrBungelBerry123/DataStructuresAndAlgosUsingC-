<<<<<<< HEAD
#include "MinHeap.h"
#include "checkMinHeapProperty.h"
#include <iostream>
#include <ctime>

inline void display(int *arr, int siz) {
	for (int i = 0; i < siz; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(void) {

	ds::MinHeap<int> heap = ds::MinHeap<int>(10);
	
	srand(time(0) );

	// Keep adding elements until the heap throws an out of range exception.
	try {
		while (true)
			heap.insert(rand() % 99);
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}

	int *arr = new int[10];
	std::cout << heap.peek() << std::endl;
	heap.toArray(arr, 10);
	display(arr, 10);
	
	bool isHeap = utils::checkMinHeapProperty(arr, 10);
	if (isHeap)
		std::cout << "is a heap\n";
	else
		std::cout << "not a heap\n";

	// Keep deleting elements until the heap throws an out of range exception.
	try {
		while (true)
			heap.pop();
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}

	delete [] arr;
	return 0;
=======
#include "MinHeap.h"
#include "checkMinHeapProperty.h"
#include <iostream>
#include <ctime>

inline void display(int *arr, int siz) {
	for (int i = 0; i < siz; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(void) {

	ds::MinHeap<int> heap = ds::MinHeap<int>(10);
	
	srand(time(0) );

	// Keep adding elements until the heap throws an out of range exception.
	try {
		while (true)
			heap.insert(rand() % 99);
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}

	int *arr = new int[10];
	std::cout << heap.peek() << std::endl;
	heap.toArray(arr, 10);
	display(arr, 10);
	
	bool isHeap = utils::checkMinHeapProperty(arr, 10);
	if (isHeap)
		std::cout << "is a heap\n";
	else
		std::cout << "not a heap\n";

	// Keep deleting elements until the heap throws an out of range exception.
	try {
		while (true)
			heap.pop();
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}

	delete [] arr;
	return 0;
>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
}