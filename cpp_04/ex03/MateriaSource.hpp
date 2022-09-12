#ifndef MATERIASOURCE_HPP

# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *materias_[4];
		void DeleteAllMaterias();
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& rhs);
		MateriaSource& operator=(const MateriaSource& rhs);
		virtual ~MateriaSource();
	
	public:
	 	#if 0 //std11
		void learnMateria(AMateria* src) override;
		AMateria* createMateria(const std::string& type) override;
		#endif
		void learnMateria(AMateria* src);
		AMateria* createMateria(const std::string& type);
};

#endif