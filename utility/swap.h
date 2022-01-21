namespace utils {

	template <typename T>
    void Swap(T &j, T &i) {
		T temp = j;
		j = i;
		i = temp;
	}

}