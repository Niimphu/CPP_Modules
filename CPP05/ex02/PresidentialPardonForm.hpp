#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm: public AForm {
public:
	PresidentialPardonForm( const std::string& = std::string( "Dummy" ) );
	PresidentialPardonForm( const PresidentialPardonForm& );
	~PresidentialPardonForm( void );

	PresidentialPardonForm&	operator=( const PresidentialPardonForm& );

	void	execute( Bureaucrat const& ) const;

};

#endif
