#include "Span.hpp"

Span::Span() : amount_(0) {}

Span::Span(unsigned int n) : amount_(n) {}

Span::~Span() {}

Span::Span(const Span& rhs) : amount_(rhs.amount_) {
	std::copy(rhs.container_.begin(), rhs.container_.end(), std::back_inserter(container_));
}

Span& Span::operator=(const Span& rhs){
	if (this == &rhs){
		return *this;
	}
	amount_ = rhs.amount_;
	std::copy(rhs.container_.begin(), rhs.container_.end(), std::back_inserter(container_));
	return *this;
}

void Span::addNumber(int number) {
	if (container_.size() == amount_) {
		throw std::range_error("add number INT: Range error!");
	}
	container_.push_back(number);
}

void Span::addNumber(std::vector<int> data) {
	if (data.size() + container_.size() <= amount_) {
		container_.insert(container_.end(), data.begin(), data.end());
	} else {
		throw std::range_error("add number VECTOR: Range error!");
	}
}

int Span::shortestSpan() {
	if (container_.size() <= 1) {
		throw std::range_error("ShortestSpan error: little data in vector!");
	}
	std::sort(container_.begin(), container_.end());
	int result = abs(container_[1] - container_[0]);
	for (unsigned int i = 0; i < container_.size() - 1; ++i) {
		if (abs(container_[i + 1] - container_[i]) < result) {
			result = abs(container_[i + 1] - container_[i]);
		}
	}
	return result;
}

int Span::longestSpan() {
	if (container_.size() <= 1) {
		throw std::range_error("ShortestSpan error: little data in vector!");
	}
	std::sort(container_.begin(), container_.end());
	return abs(container_.back() - container_.front());
}

void Span::print() {
	std::cout << "{ ";
	for (size_t i = 0; i < container_.size(); ++i) {
		std::cout << container_.at(i) << " ";
	}
	std::cout << "}" << std::endl;
}