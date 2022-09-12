#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "------------" << std::endl;
	const WrongAnimal* base = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	std::cout << base->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	base->makeSound();
	cat->makeSound();

	delete base;
	delete cat;

	return 0;
}