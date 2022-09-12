#ifndef CAT_HPP

# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		~Cat();
		Cat(const Cat& rhs);
		Cat& operator=(const Cat& rhs);
		
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