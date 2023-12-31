#ifndef CURE_H
# define CURE_H

# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria{
public:
	Cure( void );
	Cure( const Cure& );
	~Cure( void );

	Cure&	operator=( const Cure& );

	void		use( ICharacter& );
	AMateria*	clone( void ) const;


};

#endif
