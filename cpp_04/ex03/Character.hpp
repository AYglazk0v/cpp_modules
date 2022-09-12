#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter
{
	private:
	 	std::string name_;
		AMateria* type_[4];
		void DeleteAllMaterias();

	public:
		Character();
		Character(const std::string &name);
		Character(const Character& rhs);
		Character& operator=(const Character& rhs);
		virtual ~Character();
	
	public:
		#if 0 //std11
		const std::string& getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
		#endif
		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif