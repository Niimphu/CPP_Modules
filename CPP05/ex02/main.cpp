#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;
using std::cerr;

int	main( void ) {
	Bureaucrat daisy("Daisy", 130);
	cout << daisy << endl;

	Bureaucrat tony("Tony", 28);
	cout << tony << endl;

	Bureaucrat mary("Mary", 2);
	cout << mary << endl;
	cout << endl;

	try {
		ShrubberyCreationForm form = ShrubberyCreationForm( "Park" );
		daisy.signForm( form );
		daisy.executeForm( form );
	}
	catch ( std::exception& e ) {
		cerr << e.what() << endl;
	}
	cout << endl;

	try {
		RobotomyRequestForm	form = RobotomyRequestForm( daisy.getName() );
		tony.signForm( form );
		tony.executeForm( form );
	}
	catch ( std::exception& e ) {
		cerr << e.what() << endl;
	}
	cout << endl;

	try {
		PresidentialPardonForm	form = PresidentialPardonForm( tony.getName() );
		tony.executeForm( form );
	}
	catch ( std::exception& e ) {
		cerr << e.what() << endl;
	}
	try {
		PresidentialPardonForm	form = PresidentialPardonForm( tony.getName() );
		tony.signForm( form );
	}
	catch ( std::exception& e ) {
		cerr << e.what() << endl;
	}
	cout << endl;

	try {
		PresidentialPardonForm	form = PresidentialPardonForm( tony.getName() );
		mary.signForm( form );
		mary.executeForm( form );
	}
	catch ( std::exception& e ) {
		cerr << e.what() << endl;
	}
	cout << endl;
}
