/*
 *  Conact.hpp
 *
 *  Class contain user information and can get fill it from standart input
 */
#ifndef _Contact_hpp_
#define _Contact_hpp_

# include <string>
# include <iostream>
# define DOTS_AMNT 3

class Contact {
private:
	std::string	name;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	int			FillContact ();
	void		PutContact ();
	std::string	*GetNameLimited (unsigned int limit);
	std::string	*GetLastNameLimited (unsigned int limit);
	std::string	*GetNicknameLimited (unsigned int limit);
};

#endif