<<<<<<< HEAD
/*
* Author - Ritesh Saha.
* Implementation of stack using singly linked list.
*/

#ifndef _STACK_H_
#define _STACK_H_
#include "SinglyLinkedList.h"

namespace ds {

	template <typename T>
	class Stack {
	private:
		ds::SinglyLinkedList<T> *stack;

	public:
		Stack() {
			this->stack = new ds::SinglyLinkedList<T>;
		}

		Stack(T &arr, int size) {
			this->stack = new ds::SinglyLinkedList<T>;
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

=======
/*
* Author - Ritesh Saha.
* Implementation of stack using singly linked list.
*/

#ifndef _STACK_H_
#define _STACK_H_
#include "SinglyLinkedList.h"

namespace ds {

	template <typename T>
	class Stack {
	private:
		ds::SinglyLinkedList<T> *stack;

	public:
		Stack() {
			this->stack = new ds::SinglyLinkedList<T>;
		}

		Stack(T &arr, int size) {
			this->stack = new ds::SinglyLinkedList<T>;
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

>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
#endif // _STACK_H_