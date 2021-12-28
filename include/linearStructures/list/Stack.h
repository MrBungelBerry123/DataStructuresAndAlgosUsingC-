/*
* Author - Ritesh Saha.
* Implementation of stack using singly linked list.
*/

#include "SinglyLinkedList.h"

namespace dataStructures {

	template <typename T>
	class Stack {
	private:
		dataStructures::SinglyLinkedList<T> *stack;

	public:
		Stack() {
			this->stack = new dataStructures::SinglyLinkedList<T>;
		}

		Stack(T &arr, int size) {
			this->stack = new dataStructures::SinglyLinkedList<T>;
			for (int i = 0; i < size; i++)
				stack->insertFront(arr[i]);
		}

		~Stack() {
			delete this->stack;
		}

		T* toArray() {
			return this->stack->toArray();		
		}

		int size() {
			return stack->size();
		}

		bool isEmpty() {
			return stack->isEmpty();
		}

		void push(T key) {
			stack->insertFront(key);
			return;
		}

		T pop() {
			return stack->removeFront();
		}

		T peek() {
			return stack->lookUp(0);
		}

		void reverse() {
			this->stack->reverse();
		}

	};

}