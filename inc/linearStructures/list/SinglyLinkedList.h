/*
* Author - Ritesh Saha
* Implementation of singly linked list in cpp.
*/

#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_
#include <cstddef>
#include <stdexcept>

namespace ds {
	
	template <typename T>
	class SinglyLinkedList {

	private:
		struct Node {
			Node *next;
			T data;

			Node() {
				this->next = NULL;
				this->data = T();
			}

			Node(T data) {
				this->next = NULL;
				this->data = data;
			}

			Node(Node *next, T data) {
				this->next = next;
				this->data = data;
			}
		};

		Node *root;
		int length;

	public:
		SinglyLinkedList() {
			root = new Node;
			length = 0;
		}

		~SinglyLinkedList() {
			this->destroy();
		}

	private:
		// Iteratively delete the list.
		void destroy() {
			while (root != NULL) {
				Node *prev = root;
				root = root->next;
				delete prev;
			}
			return;
		}

		/* Recursively delete the list.
		void destroy(Node *trev) {
			if (trev == NULL)
				return;
			destroy(trev->next);
			delete trev;
			return;
		}
		*/

		/*
		Return the node you are looking for and the node pointing at it.
		*/
		std::pair<Node*, Node*> _search(T key) {
			Node *trev = root->next;
			Node *prev = root;
			for (; trev != NULL; prev = trev, trev = trev->next)
				if (trev->data == key)
					return std::make_pair(prev, trev);
			return std::make_pair(prev, trev);
		}

		/*
		Node* _remove() {
			if (this->isEmpty() )
				return NULL;
			Node *temp = root->next;
			root->next = temp->next;
			return temp;
		}
		*/

		/* Recursively reverse the list.
		void _reverse(Node *prevNode, Node *curNode) {
			if (curNode == NULL) {
				root->next = prevNode;
				return;
			}
			_reverse(curNode, curNode->next);
			curNode->next = prevNode;
			return;
		}
		*/


		// Iteratively reverse the list.
		void _reverse() {
			SinglyLinkedList<std::pair<Node*, Node*> > explicitStack;
			explicitStack.insertFront(std::make_pair((Node*)NULL, root->next) );
			for (Node *trev = root->next; trev != NULL; trev = trev->next)
				explicitStack.insertFront(std::make_pair(trev, trev->next) );
			std::pair<Node*, Node*> temp = explicitStack.removeFront();
			root->next = temp.first;
			while (!explicitStack.isEmpty() ) {
				temp = explicitStack.removeFront();
				temp.second->next = temp.first;
			}
			return;
		}

	public:
		inline int size() {
			return this->length;
		}

		inline bool isEmpty() {
			return root->next == NULL;
		}

		bool search(T key) {
			for (Node *trev = root->next; trev != NULL; trev = trev->next)
				if (trev->data == key)
					return true;
			return false;
		} 

		T* toArray() {
			T *arr = new T[this->length];
			int i = 0;
			for (Node *trev = root->next; trev != NULL; trev = trev->next, i++)
				arr[i] = trev->data;
			return arr;
		}

		void insertFront(T key) {
			Node *temp = root->next;
			root->next = new Node(key);
			root->next->next = temp; 
			length += 1;
			return;
		}

		void insertRear(T key) {
			Node *trev = root;
			for (; trev->next != NULL; trev = trev->next);
			trev->next = new Node(key);
			length += 1;
			return; 
		}

		T removeFront() {
			if (this->isEmpty() )
				throw std::out_of_range("Empty list!");
			Node *node = root->next;
			T temp = node->data;
			root->next = node->next;
			delete node;
			length--;
			return temp;
		}

		T removeRear() {
			Node *trev = root->next;
			Node *prev = root;
			if (trev == NULL) 
				throw std::out_of_range("Empty list!");
			for (; trev->next != NULL; prev = trev, trev = trev->next);
			T temp = trev->data;
			delete trev;
			prev->next = NULL;
			length--;
			return temp;
		}

		T remove(T key) {
			std::pair<Node*, Node*> target = _search(key);
			if (target.second == NULL)
				throw std::out_of_range("Element does not exist!");
			target.first->next = target.second->next;
			T temp = target.second->data;
			delete target.second;
			return temp;
		}

		T lookUp(int index) {
			if (index < 0 || index > this->length)
				throw std::out_of_range("Index out of bounds!");
			Node *trev = root->next;
			for (; trev != NULL && index != 0; trev = trev->next, index--);
			if (trev == NULL)
				throw std::out_of_range("Empty list!");
			return trev->data;
		}

		void reverse() {
			this->_reverse();
		}

	};

}

#endif // _SINGLY_LINKED_LIST_H_