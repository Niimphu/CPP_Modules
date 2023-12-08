#ifndef CURE_H
# define CURE_H

# include <iostream>
# include "Materia.hpp"

class Cure: public AMateria{
public:
	Cure( void );
	~Cure( void );

	void		use( ICharacter& );
	AMateria*	clone( void ) const;


};

#endif