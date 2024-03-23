#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	Base* base;
	srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			base = new A;
			break;
		case 1:
			base = new B;
			break;
		case 2:
			base = new C;
	}
	return base;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "pointer object type is: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "pointer object type is: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "pointer object type is: C" << std::endl;

}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "object type is: A" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "object type is: B" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "object type is: C" << std::endl;
	}
	catch(const std::exception& e){}
}

int	main()
{
	Base *b = generate();

	identify(b);
	identify(*b);
	delete b;
}
