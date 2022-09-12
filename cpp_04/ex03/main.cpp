#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "---------------" << std::endl;
	{
		IMateriaSource* s = new MateriaSource();
		s->learnMateria(new Ice());
		s->learnMateria(new Cure());
		AMateria *ice = s->createMateria("ice");
		ICharacter *bob = new Character("Bob");
		ICharacter *tom = new Character("Tom");
		bob->equip(ice);
		bob->use(0, *tom);
		bob->unequip(0);
		bob->use(0, *tom);
		AMateria *i = s->createMateria("fg");
		bob->equip(i);
		bob->use(0, *tom);
		AMateria * j = s->createMateria("cure");
		bob->equip(j);
		bob->use(1, *tom);
		bob->use(0, *tom);

		delete bob;
		delete tom;
		delete s;
		delete ice;

	}
	return 0;
};