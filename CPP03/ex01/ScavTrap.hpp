#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap( const std::string& );
	~ScavTrap();

	void	attack( const std::string& );
	void	guardGate();

};

#endif