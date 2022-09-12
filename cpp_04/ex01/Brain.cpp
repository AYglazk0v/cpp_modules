#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[ DEFAULT CTOR BRAIN ]" << std:: endl;
	for (int i = 0; i < 100; ++i) {
		ideas_[i] = "DEFAULT IDEA";
	}
}

Brain::~Brain() {
	std::cout << "[ Brain DESTR ]" << std::endl;
}

Brain::Brain(const Brain& rhs) {
	*this = rhs;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this == &rhs) {
		return *this;
	}
	for (int i = 0; i < 100; ++i) {
		ideas_[i] = rhs.ideas_[i];
	}
	return *this;
}

void Brain::SetIdea(std::string& idea, int index) {
	if (index < 1 || index > 101) {
		std::cout << "Index ![1;100]" << std::endl;
	} else { 
		ideas_[index - 1] = idea;
	}
}

const std::string Brain::GetIdea(const int index) const {
	if (index < 1 || index > 101) {
		std::cout << "Index ![1;100]" << std::endl;
		return NULL;
	} else {
		return ideas_[index - 1];
	}
}