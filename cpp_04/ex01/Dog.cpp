#include "Dog.hpp"

Dog::Dog() : brain_(new Brain()) {
	type_ = "DOG";
	std::cout << "[ Dog DEFAULT CTOR ]" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal() {
	std::cout << "[ Dog COPY CTOR ]" << std::endl;
	brain_ = new Brain();
	for (int i = 0; i < 100; ++i) {
		std::string idea = rhs.GetIdea(i + 1);
		brain_->SetIdea(idea, i + 1);
	}
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete brain_;
	brain_ = new Brain();
	for (int i = 0; i < 100; ++i){
		std::string idea = rhs.GetIdea(i + 1);
		brain_->SetIdea(idea, i + 1);
	}
	type_ = rhs.type_;
	return *this;
}

Dog::~Dog() {
	std::cout << "[ DOG DESTR ]" << std::endl;
	delete brain_;
}

void Dog::makeSound() const {
	std::cout << "HAW" << std::endl;
}

const std::string Dog::GetIdea(const int index) const {
	return brain_->GetIdea(index);
}

void Dog::SetIdea(std::string& idea, int index) {
	brain_->SetIdea(idea, index);
}