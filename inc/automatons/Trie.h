
/*
* Author - Ritesh Saha
* Implementation of Trie(prefix tree) in cpp.
*
* Source - Wikipedia
* In computer science, a trie, also called digital tree or prefix tree, 
* is a type of search tree, a tree data structure used for locating specific keys 
* from within a set. These keys are most often strings, with links between nodes 
* defined not by the entire key, but by individual characters. In order to access 
* a key (to recover its value, change it, or remove it), the trie is traversed depth-first, 
* following the links between nodes, which represent each character in the key. 
*/

#ifndef _TRIE_H_
#define _TRIE_H_
#include "Stack.h"
#include <string>
#define ROUTES 26 // Max number of routes is equivalent to the number of lower case english characters.

namespace ds {

	class Trie {
	private: 
		class Node {
		public: 
			Node *map[ROUTES]{NULL};
			bool EOW; // End of word.

			Node() {
				EOW = false;
			}
		};

		Node *root;
		int keys; // Keeps track of the number of keys.

	public:
		Trie() {
			root = new Node();
			keys = 0;
		}

		~Trie() {
			this->destroy();
		}

	private:
		/* Recursively delete all the nodes by preforming depth first traversial.
		void destroy(Node *node) {
			if (node == NULL)
				return;

			for (int i = 0; i < ROUTES; i++)
				destroy(node->map[i]);
			delete node;
			return;
		}
		*/

		// Iteratively delete all the nodes by using an explicit stack.
		void destroy() {
			ds::Stack<Node*> explicitStack;
			Node *temp = NULL;
			explicitStack.push(root);
			while (!explicitStack.isEmpty() ) {
				temp = explicitStack.pop();
				for (int i = 0; i < ROUTES; i++) {
					if (temp->map[i] == NULL)
						continue;
					explicitStack.push(temp->map[i]);
				}
				delete temp;
			}
			return;
		}

		void _addKey(std::string key) {
			Node *trev = root;
			for (int ch : key) {
				int hash = ch - 97;
				// If a route dosen't exist, create one!
				if (trev->map[hash] == NULL)
					trev->map[hash] = new Node;
				// Traverse the route.
				trev = trev->map[hash];
			}
			trev->EOW = true; // Specify the word node. 
			return;
		}

		Node* _searchPrefix(std::string prefix) {
			Node *trev = root;
			for (int ch : prefix) {
				int hash = ch - 97;
				// Return NULL if a route doesnt exist.
				if (trev->map[hash] == NULL)
					return NULL;
				// Otherwise traverse the route.
				trev = trev->map[hash];
			}
			return trev;
		}

		void _removeKey(std::string key) {
			Node *target = this->_searchPrefix(key);
			if (target == NULL)
				return;
			if (target->EOW) 
				keys -= 1;
			target->EOW = false;	
		}

		bool _search(std::string key) {
			Node *target = this->_searchPrefix(key);
			if (target == NULL)
				return false;
			return target->EOW;
		}

		bool _startsWith(std::string prefix) {
			return this->_searchPrefix(prefix) != NULL;
		}

	public:
		int size() {
			return this->keys;
		}

		void addKey(std::string key) {
			this->_addKey(key);
			keys++;
			return;
		}

		void removeKey(std::string key) {
			this->_removeKey(key);
			return;
		}

		bool search(std::string key) {
			return this->_search(key);
		}

		bool startsWith(std::string prefix) {
			return this->_startsWith(prefix);
		}

	};

}

#endif // _TRIE_H_