#include "../utility/Swap.h"
#include "../include/linearStructures/MedianHeap.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(void) {

	dataStructures::MedianHeap<int> heap;

	srand(time(0) );

	// Keep adding elements until the heap throws an out of range exception.
	try {
		while (true)
			heap.insert(rand() % 99);
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}

	// Keep deleting elements until the heap throws an out of range exception.
	try {
		while (true)
			heap.deleteMedian();
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}

	return 0;
}