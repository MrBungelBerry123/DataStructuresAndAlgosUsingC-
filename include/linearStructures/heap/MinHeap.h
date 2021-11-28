/*
* Author - Ritesh Saha
*
* Implementation of min heap in cpp.
*/

#include "../../minHeapify.h"
#include <stdexcept>

#define DEFAULT_SIZE 50

namespace dataStructures {
	
	template <typename T>
	class MinHeap {

	private:
		T *heap;
		int maxSize;

	public:
		int currentSize;

		MinHeap() {
			heap = new T[DEFAULT_SIZE];
			currentSize = 0;
			maxSize = DEFAULT_SIZE;
		}

		MinHeap(const int size) {
			heap = new T[size];
			currentSize = 0;
			maxSize = size;
		}

		MinHeap(T *array, const int size) {
			heap = new T[size];
			for (int i = 0; i < size; i++) 
				heap[i] = array[i];
			algorithms::minHeapify(heap, size);
			currentSize = size;
			maxSize = size;
		}

		~MinHeap() {
			this->destroy();
		}

		bool isEmpty() {
			return currentSize == 0;
		}

		bool isFull() {
			return currentSize == maxSize;
		}

		T peek() {
			if (this->isEmpty() )
				throw std::out_of_range("Heap is empty!");
			return this->heap[0];
		}

		inline T get(int index) {
			if (index > currentSize || index < 0 || this->isEmpty() )
				throw std::out_of_range("Invalid Index!");
			return this->heap[index];
		}

		T* toArray(T *container, int size) {
			if (this->isEmpty() )
				return container;
			if (size < this->currentSize)
				throw std::out_of_range("Array size mismatch");
			for (int i = 0; i < this->currentSize; i++)
				container[i] = this->heap[i];
			return container;
		}

	private:
		inline void destroy() {
			delete [] this->heap;
		}

		inline int getParent(int index) {
			return (index - 1) / 2;
		}

		inline int getLeftChild(int index) {
			return 2 * index + 1;
		}

		inline int getRightChild(int index) {
			return 2 * index + 2;
		}

		void heapifyAbove(int index) {
			T temp = this->heap[index];
			while (index != 0) {
				int parentIndex = getParent(index);
				if (temp < this->heap[parentIndex]) {
					this->heap[index] = this->heap[parentIndex];
					index = parentIndex;
				}
				else break;
			}
			this->heap[index] = temp;
			return;
		}

		void heapifyBelow(int index) {
			T temp = this->heap[index];
			int leftChild = getLeftChild(index);
			int rightChild = getRightChild(index);
			for (; leftChild < currentSize; leftChild = getLeftChild(index), rightChild = getRightChild(index)) {
				T leftValue = this->heap[leftChild];
				T rightValue = (rightChild < currentSize) ? this->heap[rightChild] : INT_MAX;
				int minChild = (leftValue <= rightValue) ? leftChild : rightChild;
				if (this->heap[minChild] < temp) {
					this->heap[index] = this->heap[minChild];
					index = minChild;
				}
				else break;
			}
			this->heap[index] = temp;
			return;
		}

	public:
		void insert(T key) {
			if (currentSize >= maxSize) 
				throw std::out_of_range("Heap Size Exceeded!");
			this->heap[currentSize] = key;
			this->heapifyAbove(currentSize);
			currentSize += 1;
			return;
		}

		T remove(int index){
			if (index > currentSize || index < 0 || this->isEmpty() )
				throw std::out_of_range("Invalid Index!");
			T temp = this->heap[index];
			this->heap[index] = this->heap[--currentSize];
			if (this->heap[index] < this->heap[getParent(index)]) 
				this->heapifyAbove(index);
			else
				this->heapifyBelow(index);
			return temp;
		}

		T pop() {
			return remove(0);
		}

	};

}