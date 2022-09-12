#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include "Brain.hpp"

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
		virtual const std::string GetIdea(const int index) const = 0;
		virtual void SetIdea(std::string& idea, int index) = 0;
};

#endif