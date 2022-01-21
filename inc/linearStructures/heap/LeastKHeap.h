
/*
* Author - Ritesh Saha
* Implementation of least k heap.
* This data structure keeps track of the least k elements.
*/

#ifndef _LEAST_K_HEAP_H_
#define _LEAST_K_HEAP_H_
#include "MinHeap.h"

#define LEAST_K 5

namespace ds {

	template <typename T>
	class LeastKHeap {

	private:
		T *arr;
		ds::MinHeap<T> *heap;
		int k;
		int currentSize;

	public:
		LeastKHeap() {
			this->arr = new T[LEAST_K];
			this->k = LEAST_K;
			this->heap = new ds::MinHeap<T>();
			this->currentSize = 0;
		}

		LeastKHeap(const int k) {
			this->arr = new T[k];
			this->k = k;
			this->heap = new ds::MinHeap<T>();
			this->currentSize = 0;
		}

		LeastKHeap(const int k, const int size) {
			this->arr = new T[k];
			this->k = k;
			this->heap = new ds::MinHeap<T>(size);
			this->currentSize = 0;
		}

		~LeastKHeap() {
			delete [] arr;
			delete heap;
		}

	private:
		void arrayInsert(T key) {
			int trev = currentSize - 1;
			for (; trev >= 0 && arr[trev] > key; trev--)
				arr[trev + 1] = arr[trev];
			arr[trev + 1] = key;
			currentSize++;
			return;
		}

		T arrayRemove(int index) {
			int trev = index;
			T temp = arr[index];
			for (; trev < currentSize - 1; trev++)
				arr[trev] = arr[trev + 1];
			currentSize--;
			return temp;
		}

	public:
		int length() {
			return currentSize + this->heap->currentSize;
		}

		bool isEmpty() {
		 	return currentSize == 0;
		}

		bool isFull() {
			return this->heap->isFull();
		}

		T peek(int i) {
			if (i < 0 || i > k)
				throw std::out_of_range("Invalid Index!");
			return this->arr[i];
		}

		T* toArray(T *container, int size) {
			if (this->isEmpty() )
				return container;
			else if (this->length() > size)
				throw std::out_of_range("Array size mismatch!");
			int i = 0;
			for (; i < this->currentSize; i++)
				container[i] = arr[i];
			for (int j = 0; j < this->heap->currentSize; j++)
				container[i++] = this->heap->get(j);
			return container;
		}

		void insert(T key) {
			if (this->heap->isFull() )
				throw std::out_of_range("Maximum capacity reached!");
			else if (currentSize < k) {
				this->arrayInsert(key);
				return;
			}
			else if (arr[k - 1] > key) {
				T temp = arr[k - 1];
				currentSize--;
				this->arrayInsert(key);
				this->heap->insert(temp);
				return;
			}
			this->heap->insert(key);
			return;
		}

		T remove(int index) {
			if (this->isEmpty() )
				throw std::out_of_range("Heap is empty!");
			else if (index < currentSize) {
				T temp = this->arrayRemove(index);
				if (!this->heap->isEmpty() ) {
					T val = this->heap->pop();
					this->arrayInsert(val);
				}
				return temp;
			}
			return this->heap->remove(index - k);
		}

		T pop() {
			return remove(0);
		}
	};

}

#endif // __LEAST_K_HEAP_H_