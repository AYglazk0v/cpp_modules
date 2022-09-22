#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span {
	private:
		unsigned int amount_;
		std::vector<int> container_;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& rhs);
		Span& operator=(const Span& rhs);
		~Span();

	public:
		void addNumber(int number);
		void addNumber(std::vector<int> data);
		int shortestSpan();
		int longestSpan();
	
	public:
		void print();
};

#endif