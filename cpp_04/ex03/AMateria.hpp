#ifndef AMATERIA_HPP

# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;
class AMateria {
	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& rhs);
		AMateria& operator=(const AMateria& rhs);
		virtual ~AMateria();
	
	public:
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
	
	protected:
		std::string type_;
};

#endif