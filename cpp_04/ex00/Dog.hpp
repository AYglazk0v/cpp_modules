#ifndef DOG_HPP

# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& rhs);
		Dog& operator=(const Dog& rhs);
		~Dog();
	
	public:
	 	#if 0 //STD11
		void makeSound() const override;
		#endif
		void makeSound() const;
};

#endif