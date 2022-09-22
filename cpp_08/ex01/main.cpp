#include "Span.hpp"

int main()
{
	Span sp = Span(20);
	sp.addNumber(21);
	sp.addNumber(22);
	sp.addNumber(35);
	sp.addNumber(34);
	sp.addNumber(42);

	sp.print();

	std::cout << std::endl;

	std::vector<int> v;
	for(int i = 0; i < 10; ++i){
		v.push_back(i*2);
	}
	sp.addNumber(v);
	sp.print();
	std::cout << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}