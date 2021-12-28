/*
* Author - Ritesh Saha
* Implementation of queue in cpp using a doubly linked list.
*/

#include "DoublyLinkedList.h"

namespace dataStructures {

	template <typename T>
	class Queue {
	private:
		dataStructures::DoublyLinkedList<T> *queue;

	public:
		Queue() {
			this->queue = new dataStructures::DoublyLinkedList<T>;
		}

		Queue(T *arr, int size) {
			this->queue = new dataStructures::DoublyLinkedList<T>;
			for (int i = 0; i < size; i++)
				this->queue->insertRear(arr[i]);
		}

		~Queue() {
			delete this->queue;
		}

		T* toArray() {
			return this->queue->toArray();
		}

		int size() {
			return this->queue->size();
		}

		bool isEmpty() {
			return this->isEmpty();
		}

		void enqueue(T key) {
			this->queue->insertRear(key);
		}

		T dequeue() {
			return this->queue->removeFront();
		}

		T peek() {
			return this->queue->lookUp(0);
		}

		void reverse() {
			return this->queue->reverse();
		}

	};

}