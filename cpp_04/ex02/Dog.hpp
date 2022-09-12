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
		const std::string GetIdea(const int index) const override;
		void SetIdea(std::string& idea, int index) override;
		#endif
		void makeSound() const;
		const std::string GetIdea(const int index) const;
		void SetIdea(std::string& idea, int index);

	private:
		Brain *brain_;
};

#endif