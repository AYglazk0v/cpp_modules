#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template <typename T> int easyfind(T& data, int num) {
	typename T::const_iterator it;
	it = std::find(data.begin(), data.end(), num);
	if (it == data.end()) {
		throw std::exception();
	}
	return *it;
}
#endif