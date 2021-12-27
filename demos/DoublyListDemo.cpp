#include "../include/linearStructures/list/DoublyLinkedList.h"
#include <iostream>
#include <ctime>
#define MAX_SIZE 10
#define UPPER_BOUND 100
#define LOWER_BOUND 1

using namespace std;

inline void display(int *array, int len) {
	for (int i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int main(void) {

	dataStructures::DoublyLinkedList<int> list;

	srand(time(0) );

	// Populate the list with random integers.
	for (int i = 0; i < MAX_SIZE; i++) {
		int temp = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
		cout << temp << " ";
		list.insertRear(temp);
	}
	cout << endl;

	int *arr = list.toArray();
	display(arr, list.size() );
	list.reverse();
	delete [] arr;
	arr = list.toArray();
	display(arr, list.size() );
	delete [] arr;
	
	while (!list.isEmpty() ) 
		cout << list.removeRear() << " ";
	cout << endl;


	return 0;
}