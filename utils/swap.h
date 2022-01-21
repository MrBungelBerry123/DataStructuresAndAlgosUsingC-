// Author - Ritesh Saha
#ifndef _SWAP_H_
#define _SWAP_H_

namespace utils {

	template <typename T>
	inline void swap(T &j, T &i) {
		T temp = j;
		j = i;
		i = temp;
	}

}

#endif // _SWAP_H_