#include "Stack.h"
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
	ds::Stack<int> stack;
	srand(time(0) );

	// Populate the stack with random integers.
	for (int i = 0; i < MAX_SIZE; i++) {
		int temp = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
		cout << temp << " ";
		stack.push(temp);
	}
	cout << endl;

	int *arr = stack.toArray();
	display(arr, stack.size() );
	stack.reverse();
	delete [] arr;
	arr = stack.toArray();
	display(arr, stack.size() );
	delete [] arr;

	try {
		while (true) 
			cout << stack.pop() << " ";
	}
	catch (std::out_of_range exp) {
		cout << endl;
		cout << exp.what() << endl;
	}
	return 0;
}