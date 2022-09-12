#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& rhs);
		WrongCat& operator=(const WrongCat& rhs);
		~WrongCat();
	
	public:
		void makeSound() const;
};

#endif