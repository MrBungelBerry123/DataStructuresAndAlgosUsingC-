/*
* Author - Ritesh Saha
* Implementation of doubly linked list in cpp.
*/

#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_
#include <stdexcept>

namespace ds {
	
	template <typename T>
	class DoublyLinkedList {

	private:
		struct Node {
			Node *left;
			Node *right;
			T data;

			Node() {
				this->left = NULL;
				this->right = NULL;
				this->data = T();
			}

			Node(const T data) {
				this->left = NULL;
				this->right = NULL;
				this->data = data;
			}

			Node(Node *left, T data) {
				this->left = left;
				left->right = this;
				this->right = NULL;
				this->data = data;
			}

			Node(Node *left, Node *right, T data) {
				this->left = left;
				left->right = this;
				this->right = right;
				right->left = this;
				this->data = data;
			}
		};

		Node *root;
		Node *rear;
		int length;

	public:
		DoublyLinkedList() {
			this->root = new Node;
			this->rear = root;
			this->length = 0;
		}

		~DoublyLinkedList() {
			this->destroy();
		}

	private:
		// Iteratively delete the list.
		void destroy() {
			while (root != NULL) {
				Node *prev = root;
				root = root->right;
				delete prev;
			}
			return;
		}

		/* Recursively delete the list.
		void destroy(Node *trev) {
			if (trev == NULL)
				return;

			destroy(trev->left);
			delete(trev);
			return;
		}
		*/

		// Iteratively reverse the list.
		void _reverse() {
			DoublyLinkedList<std::pair<Node*, Node*> > explicitStack;
			for (Node *trev = root->right; trev != NULL; trev = trev->right)
				explicitStack.insertFront(std::make_pair(trev, trev->right) );
			std::pair<Node*, Node*> temp = explicitStack.removeFront();
			root->right = temp.first;
			temp.first->left = root;
			while (!explicitStack.isEmpty() ) {
				temp = explicitStack.removeFront();
				temp.second->right = temp.first;
				temp.first->left = temp.second;
				temp.first->right = NULL;
			}
			return;
		}

		/* Recursively reverse the list.
		void _reverse(Node *prevNode, Node *curNode) {
			if (curNode == NULL) {
				root->right = prevNode;
				prevNode->left = root;
				return;
			}
			_reverse(curNode, curNode->right);
			curNode->right = prevNode;
			prevNode->left = curNode;
			prevNode->right = NULL;
			return;
		}
		*/

		Node* _search(T key) {
			Node *trev = root->right;
			for (; trev != NULL; trev = trev->right)
				if (trev->data == key)
					return trev;
			return NULL;
		}

	public:
		inline int size() {
			return this->length;
		}

		inline bool isEmpty() {
			return root->right == NULL;
		}

		bool search(T key) {
			for (Node *trev = root->right; trev != NULL; trev = trev->right)
				if (trev->data == key)
					return true;
			return false;
		}

		T* toArray() {
			T *arr = new T[this->length];
			int i = 0;
			for (Node *trev = root->right; trev != NULL; trev = trev->right, i++)
				arr[i] = trev->data;
			return arr;
		}

		void insertFront(T key) {
			if (root->right == NULL)
				root->right = new Node(root, key);
			else
				root->right = new Node(root, root->right, key);
			if (length == 0)
				rear = root->right;
			length += 1;
			return;
		}

		void insertRear(T key) {
			rear->right = new Node(rear, key);
			rear = rear->right;
			length += 1;
			return;
		}

		T removeFront() {
			if (this->isEmpty() )
				throw std::out_of_range("Empty list!");
			Node *temp = root->right;
			root->right = root->right->right;
			if (root->right != NULL)
				root->right->left = root;
			T data = temp->data;
			delete temp;
			length -= 1;
			if (length == 0)
				rear = root;
			return data;
		}

		T removeRear() {
			if (this->isEmpty() )
				throw std::out_of_range("Empty list!");
			Node *temp = rear;
			rear = rear->left;
			rear->right = NULL;
			T data = temp->data;
			delete temp;
			length -= 1;
			return data;
		}

		T remove(T key) {
			if (this->isEmpty() )
				throw std::out_of_range("Empty list!");
			Node *target = this->_search(key);
			if (target == NULL)
				throw std::out_of_range("Element does not exists!");
			if (target->right == NULL)
				this->removeRear();
			else if (target->left == root)
				this->removeFront();
			target->left->right = target->right;
			target->right->left = target->left;
			T data = target->data;
			delete target;
			length -= 1;
			return data;
		}

		T lookUp(int index) {
			if (index < 0 || index > this->length)
				throw std::out_of_range("Index out of bounds!");
			Node *trev = root->right;
			for (; trev != NULL & index != 0; trev = trev->right, index--);
			if (trev == NULL)
				throw std::out_of_range("List is empty!");
			return trev->data;
		}

		void reverse() {
			if (this->length <= 1)
				return;
			this->rear = root->right;
			this->_reverse();
			return;
		}

	};

}

#endif // _Doubly_Linked_List_H_