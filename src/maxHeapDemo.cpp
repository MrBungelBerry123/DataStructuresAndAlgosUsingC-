#include "MaxHeap.h"
#include "checkMaxHeapProperty.h"
#include <iostream>
#include <ctime>

void display(int *arr, int siz) {
	for (int i = 0; i < siz; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(void) {

	ds::MaxHeap<int> heap = ds::MaxHeap<int>(10);
	
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
	
	bool isHeap = utils::checkMaxHeapProperty(arr, 10);
	if (isHeap)
		std::cout << "is a heap\n";
	else
		std::cout << "not a heap\n";

	// Keep deleting elements until the heap throws an out of range exception.
	try {
		int size = 10;
		while (true) {
			heap.pop();
			size--;
			arr = heap.toArray(arr, size);
			display(arr, size);
		}
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}

	delete [] arr;
	return 0;
}