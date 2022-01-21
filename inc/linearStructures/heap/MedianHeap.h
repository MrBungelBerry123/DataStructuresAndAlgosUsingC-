
/*
* Author - Ritesh Saha
* Implementation of median heap.
* This data structue keeps track of the median element.
*/

#ifndef _MEDIAN_HEAP_H_
#define _MEDIAN_HEAP_H_
#include "MinHeap.h"
#include "MaxHeap.h"
#include <cmath>

namespace ds {

	template <typename T>
	class MedianHeap {

	private:
		ds::MinHeap<T> *hMin;
		ds::MaxHeap<T> *hMax;

	public:
		MedianHeap() {
			hMin = new ds::MinHeap<T>();
			hMax = new ds::MaxHeap<T>();
		}

		MedianHeap(int size) {
			hMin = new ds::MinHeap<T>(ceil(size / 2) );
			hMax = new ds::MaxHeap<T>(floor(size / 2) );
		}

	private:
		void balanceHeapSizes() {
			if (this->hMax->currentSize == this->hMin->currentSize || this->hMax->currentSize + 1 == this->hMin->currentSize)
				return;
			else if (this->hMax->currentSize > this->hMin->currentSize) {
				this->hMin->insert(this->hMax->peek() );
				this->hMax->pop();
				return;
			}
			this->hMax->insert(this->hMin->peek() );
			this->hMin->pop();
			return;
		}

	public:
		T getMedian() {
			int n = this->hMin->currentSize + this->hMax->currentSize;
			if (n % 2 != 0)
				return this->hMin->peek();
			return (double)((this->hMin->peek() + this->hMax->peek()) / 2.0);
		}

		void insert(T key) {
			if (this->hMin->currentSize == 0) {
				this->hMin->insert(key);
				return;
			}
			else if (this->hMax->currentSize == 0) {
				if (key > this->hMin->peek() ) {
					T curMin = this->hMin->pop();
					this->hMin->insert(key);
					this->hMax->insert(curMin);
				}
				else
					this->hMax->insert(key);
				return;
			}
			T max = this->hMax->peek();
			if (key < max)
				this->hMax->insert(key);
			else
				this->hMin->insert(key);
			this->balanceHeapSizes();
			return;
		}

		void deleteMedian() {
			this->hMax->pop();
			this->balanceHeapSizes();
		}

	};

}

#endif // _MEDIAN_HEAP_H_