#include "Cat.hpp"

Cat::Cat() : brain_(new Brain()) {
	type_ = "CAT";
	std::cout << "[ CAT Default ctor ]" << std::endl;
}

Cat::~Cat() {
	std::cout << "[ CAT Destr ]" << std::endl;
	delete brain_;
}

Cat::Cat(const Cat& rhs) : Animal() {
	std::cout << "[ CAT COPY CTOR ]" << std::endl;
	brain_ = new Brain();
	for (int i = 0; i < 100; ++i) {
		std::string idea = rhs.GetIdea(i + 1);
		brain_->SetIdea(idea, i + 1);
	}
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete brain_;
	brain_ = new Brain();
	for (int i = 0; i < 100; ++i) {
		std::string idea = rhs.GetIdea(i + 1);
		brain_->SetIdea(idea, i + 1);
	}
	type_ = rhs.type_;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MAAAAU" << std::endl;
}

const std::string Cat::GetIdea(const int index) const {
	return brain_->GetIdea(index);
}

void Cat::SetIdea(std::string& idea, int index) {
	brain_->SetIdea(idea, index);
}