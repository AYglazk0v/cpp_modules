#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& rhs);
		Ice& operator=(const Ice& rhs);
		virtual ~Ice();
	
	public:
	 	#if 0 //std11
		AMateria* clone() const override;
		void use(ICharacter& target) override;
		#endif
		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif