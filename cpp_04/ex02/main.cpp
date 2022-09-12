#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
//	Animal *a = new Animal();

	Cat *c = new Cat();
	c->makeSound();
	Dog *d = new Dog();
	d->makeSound();
	std::string idea = "qwertyuiop";
	d->SetIdea(idea, 1);
	std::cout << d->GetIdea(1) << std::endl;
	delete c;
	delete d;
}
