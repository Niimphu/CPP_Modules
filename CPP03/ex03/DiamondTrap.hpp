#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "iostream"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
public:
	DiamondTrap( const std::string& );
	~DiamondTrap();

	void	setName( const std::string& );

	std::string	getName( void );

	void	whoAmI( void );

private:
	std::string	_name;

};

#endif
