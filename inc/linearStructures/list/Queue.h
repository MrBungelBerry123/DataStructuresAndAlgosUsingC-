<<<<<<< HEAD
/*
* Author - Ritesh Saha
* Implementation of queue in cpp using a doubly linked list.
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "DoublyLinkedList.h"

namespace ds {

	template <typename T>
	class Queue {
	private:
		ds::DoublyLinkedList<T> *queue;

	public:
		Queue() {
			this->queue = new ds::DoublyLinkedList<T>;
		}

		Queue(T *arr, int size) {
			this->queue = new ds::DoublyLinkedList<T>;
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

=======
/*
* Author - Ritesh Saha
* Implementation of queue in cpp using a doubly linked list.
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "DoublyLinkedList.h"

namespace ds {

	template <typename T>
	class Queue {
	private:
		ds::DoublyLinkedList<T> *queue;

	public:
		Queue() {
			this->queue = new ds::DoublyLinkedList<T>;
		}

		Queue(T *arr, int size) {
			this->queue = new ds::DoublyLinkedList<T>;
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

>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
#endif // _QUEUE_H_