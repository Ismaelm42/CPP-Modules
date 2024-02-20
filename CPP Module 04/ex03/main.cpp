#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("unknown");
	ICharacter* bob = new Character("bob");

	tmp = new Cure();
	std::cout << tmp->getType() << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	delete tmp;
	delete bob;
	delete me;
	delete src;
	return 0;
}

// int main(void)
// {
// 	ICharacter	*character1 = new Character("character1");
// 	ICharacter	*character2 = new Character("character2");
// 	AMateria	*ice = new Ice();

// 	character1->equip(new Ice());
// 	character1->equip(ice);
// 	character1->equip(new Ice());
// 	character1->equip(new Ice());
// 	character1->equip(new Ice());

// 	character2->equip(new Cure());
// 	character2->equip(new Cure());
// 	character2->equip(new Ice());

// 	character1->use(0, *character2);
// 	character1->use(1, *character2);
// 	character1->use(3, *character2);
// 	character2->use(2, *character1);

// 	character1->unequip(2);
// 	character1->unequip(3);
// 	character1->equip(new Cure());
// 	character1->use(2, *character2);
// 	character1->use(3, *character2);

// 	character1->equip(new Cure());
// 	character1->use(3, *character2);

// 	delete character1;
// 	delete character2;
// 	return 0;
// }

// int main()
// {
// 	IMateriaSource	*materiaSource = new MateriaSource();
// 	ICharacter		*character1 = new Character("character1");
// 	ICharacter		*character2 = new Character("character2");
	
// 	materiaSource->learnMateria(new Ice());
// 	materiaSource->learnMateria(new Cure());
// 	materiaSource->learnMateria(new Cure());
// 	materiaSource->learnMateria(new Cure());
// 	materiaSource->learnMateria(new Cure());

// 	character1->equip(materiaSource->createMateria("cure"));
// 	character1->equip(materiaSource->createMateria("cure"));
// 	character1->equip(materiaSource->createMateria("ice"));
// 	character1->equip(materiaSource->createMateria("ice"));
// 	character1->equip(materiaSource->createMateria("cure"));

// 	character1->use(0, *character2);
// 	character1->use(2, *character2);
	
// 	delete materiaSource;
// 	delete character1;
// 	delete character2;
// 	return 0;
// }

