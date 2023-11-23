#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat: public Animal {
public:
	Cat( void );
	~Cat( void );

	Cat	&operator=( const Cat& );

	void	makeSound( void ) const;


};

#endif
