#include "Zombie.hpp"

int	main( void ) {
	Zombie* Fred = newZombie("Fred");
	Fred->announce();

	std::cout << std::endl;

	randomChump("Chad");

	std::cout << std::endl;

	delete Fred;

	return 0;
}
