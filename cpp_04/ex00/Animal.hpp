#ifndef ANIMAL_HPP

# define ANIMAL_HPP
# include <iostream>

class Animal {
	protected:
		std::string type_;
	
	public:
		Animal();
		Animal(const Animal& rhs);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();
	
	public:
		const std::string& getType() const;
		virtual void makeSound() const;
};

#endif