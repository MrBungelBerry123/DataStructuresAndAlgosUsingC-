/*
* Author - Ritesh Saha
* Implementation of singly linked list in cpp.
*/
#include <cstddef>
#include <stdexcept>

namespace dataStructures {
	
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

		// Recursively delete the list.
		void destroy(Node *trev) {
			if (trev == NULL)
				return;
			destroy(trev->next);
			delete trev;
			return;
		}

		std::pair<Node*, Node*> search_(T key) {
			Node *trev = root->next;
			Node *prev = root;
			for (; trev != NULL; prev = trev, trev = trev->next)
				if (trev->data == key)
					return std::make_pair(prev, trev);
			return std::make_pair(prev, trev);
		}

		/*
		Node* remove_() {
			if (this->isEmpty() )
				return NULL;
			Node *temp = root->next;
			root->next = temp->next;
			return temp;
		}
		*/

		// Recursively reverse the list.
		void reverse_(Node *prevNode, Node *curNode) {
			if (curNode == NULL) {
				root->next = prevNode;
				return;
			}
			reverse_(curNode, curNode->next);
			curNode->next = prevNode;
			return;
		}


		// Iteratively reverse the list.
		void reverse_() {
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
			for (; trev->next != NULL; prev = trev, trev = trev->next);
			if (trev == NULL) 
				throw std::out_of_range("Empty list!");
			T temp = trev->data;
			delete trev;
			prev->next = NULL;
			length--;
			return temp;
		}

		T remove(T key) {
			std::pair<Node*, Node*> target = search_(key);
			if (target.second == NULL)
				throw std::out_of_range("Element does not exist!");
			target.first->next = target.second->next;
			T temp = target.second->data;
			delete target.second;
			return temp;
		}

		void reverse() {
			this->reverse_();
		}

	};

}