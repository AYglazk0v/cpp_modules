#ifndef IMATERIASOURCES_HPP

# define IMATERIASOURCES_HPP

# include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif