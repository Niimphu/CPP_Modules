#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap randall( "Randall" );
	randall.setAttackDamage( 3 );
	randall.setEnergyPoints( 4 );
	std::cout << randall.getName() << "'s stats" << std::endl;
	std::cout << "Hitpoints: " << randall.getHitPoints() << std::endl;
	std::cout << "Energy points: " << randall.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << randall.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ClapTrap bertha( "Bertha" );
	std::cout << bertha.getName() << "'s stats" << std::endl;
	std::cout << "Hitpoints: " << bertha.getHitPoints() << std::endl;
	std::cout << "Energy points: " << bertha.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << bertha.getAttackDamage() << std::endl;
	std::cout << std::endl;

	randall.attack( bertha.getName() );
	bertha.takeDamage( randall.getAttackDamage() );
	std::cout << std::endl;

	bertha.beRepaired( 1 );
	std::cout << std::endl;

	bertha.attack( randall.getName() );
	randall.takeDamage( bertha.getAttackDamage() );
	std::cout << std::endl;

	randall.attack( bertha.getName() );
	bertha.takeDamage( randall.getAttackDamage() );
	std::cout << std::endl;

	randall.attack( bertha.getName() );
	bertha.takeDamage( randall.getAttackDamage() );
	std::cout << std::endl;

	randall.attack( bertha.getName() );
	bertha.takeDamage( randall.getAttackDamage() );
	std::cout << std::endl;

	randall.attack( bertha.getName() );
	std::cout << std::endl;

	bertha.attack( randall.getName() );
	std::cout << std::endl;
	return 0;
}
