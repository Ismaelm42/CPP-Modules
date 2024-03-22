#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	Base *b = Base::generate();

	Base::identify(b);
	Base::identify(*b);
	delete b;
}
