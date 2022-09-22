#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack<T> &mutantStack) : std::stack<T>(mutantStack) {};
		MutantStack const &operator=(MutantStack<T> &mutantStack) {
			std::stack<T>::operator=(mutantStack);
			return (*this);
		}

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}
};

#endif