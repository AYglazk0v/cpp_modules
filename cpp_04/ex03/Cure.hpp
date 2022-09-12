#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& rhs);
		Cure& operator=(const Cure& rhs);
		virtual ~Cure();
	
	public:
		#if 0 //std11
		AMateria* clone() const override;
		void use(ICharacter& target) override;
		#endif
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif