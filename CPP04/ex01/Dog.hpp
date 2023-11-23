#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog: public Animal {
public:
	Dog( void );
	~Dog( void );

	Dog	&operator=( const Dog& );

	void	makeSound( void ) const;


};

#endif
