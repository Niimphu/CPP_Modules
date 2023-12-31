#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

std::string	getInput( const std::string& fieldName );

class	Contact {
public:
	Contact( void );

	std::string	getFirstName( void );
	std::string	getLastName( void );
	std::string	getNickname( void );
	std::string	getPhoneNumber( void );
	std::string	getDarkestSecret( void );

    void		setFirstName( const std::string& );
    void		setLastName( const std::string& );
	void		setNickname( const std::string& );
    void		setPhoneNumber( const std::string& );
    void		setDarkestSecret( const std::string& );

    bool		isValidPhoneNumber( void );

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif
