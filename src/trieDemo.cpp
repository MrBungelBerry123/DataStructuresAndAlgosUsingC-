<<<<<<< HEAD
#include "Trie.h"
#include <iostream>

using namespace std;

int main(void) {
	ds::Trie trie;

	trie.addKey(string("helloworld") );
	trie.addKey(string("hello") );
	trie.addKey(string("ritesh") );
	trie.addKey(string("jupyter") );
	trie.addKey(string("joker") );
	trie.addKey(string("joke") );

	cout << trie.search(string("helloworld") ) << endl;
	cout << trie.search(string("hello") ) << endl;
	cout << trie.search(string("joke") ) << endl;
	cout << trie.search(string("joker") ) << endl;
	cout << trie.search(string("hell") ) << endl;
	

	cout << trie.startsWith(string("hello") ) << endl;
	cout << trie.startsWith(string("hell") ) << endl;
	cout << trie.startsWith(string("jok") ) << endl;
	cout << trie.startsWith(string("jupytp") ) << endl;
	cout << trie.startsWith(string("jupyter") ) << endl;

	trie.removeKey(string("helloworld") );
	trie.removeKey(string("hello") );
	trie.removeKey(string("ritesh") );
	trie.removeKey(string("joker") );
	trie.removeKey(string("joke") );
	trie.removeKey(string("jupyter") );

	cout << trie.search(string("jupyter") ) << endl;
	cout << trie.search(string("joke") ) << endl;
	cout << trie.search(string("hello") ) << endl;
	cout << trie.search(string("helloworld") ) << endl;

	return 0;
=======
#include "Trie.h"
#include <iostream>

using namespace std;

int main(void) {
	ds::Trie trie;

	trie.addKey(string("helloworld") );
	trie.addKey(string("hello") );
	trie.addKey(string("ritesh") );
	trie.addKey(string("jupyter") );
	trie.addKey(string("joker") );
	trie.addKey(string("joke") );

	cout << trie.search(string("helloworld") ) << endl;
	cout << trie.search(string("hello") ) << endl;
	cout << trie.search(string("joke") ) << endl;
	cout << trie.search(string("joker") ) << endl;
	cout << trie.search(string("hell") ) << endl;
	

	cout << trie.startsWith(string("hello") ) << endl;
	cout << trie.startsWith(string("hell") ) << endl;
	cout << trie.startsWith(string("jok") ) << endl;
	cout << trie.startsWith(string("jupytp") ) << endl;
	cout << trie.startsWith(string("jupyter") ) << endl;

	trie.removeKey(string("helloworld") );
	trie.removeKey(string("hello") );
	trie.removeKey(string("ritesh") );
	trie.removeKey(string("joker") );
	trie.removeKey(string("joke") );
	trie.removeKey(string("jupyter") );

	cout << trie.search(string("jupyter") ) << endl;
	cout << trie.search(string("joke") ) << endl;
	cout << trie.search(string("hello") ) << endl;
	cout << trie.search(string("helloworld") ) << endl;

	return 0;
>>>>>>> a04fdc2f4df5be282c51d9e64b2d665987a68025
}