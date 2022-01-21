#include <iostream>
#include <ctime>
#include "LeastKHeap.h"

using namespace std;

void display(int *arr, int siz) {
	for (int i = 0; i < siz; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(void) {

	ds::LeastKHeap<int> heap(5, 10);

	srand(time(0) );

	// Keep adding elements until the heap throws an out of range exception.
	try {
		while (true) {
			int temp = rand() % 99;
			heap.insert(temp);
			cout << temp << " ";
		}
	}
	catch (std::out_of_range exp) {
		cout << endl;
		std::cout << exp.what() << std::endl;
	}

	for (int i = 0; i < 5; i++)
		cout << heap.peek(i) << " ";
	cout << endl;

	cout << heap.length() << endl;
	int *arr = new int[15];
	arr = heap.toArray(arr, 15);

	display(arr, 15);

	// Keep deleting elements until the heap throws an out of range exception.
	try {
		int size = 15;
		while (true) {
			heap.pop();
			size--;
			arr = heap.toArray(arr, size);
			display(arr, size);
		}
		cout << endl;
	}
	catch (std::out_of_range exp) {
		std::cout << exp.what() << std::endl;
	}
	
	delete [] arr;

	return 0;
}