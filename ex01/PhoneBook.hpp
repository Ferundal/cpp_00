/*
 *  PhoneBook.hpp
 *
 *  Phone book can be filled with contacts, it also can show them
 */
#ifndef _PhoneBook_hpp_
# define _PhoneBook_hpp_

# include <string>
# include <iostream>
# include <stdint.h>
# include <iomanip>
# include "Contact.hpp"

# define PHONE_BOOK_SIZE 10
# define PHONE_FEELD_SIZE 10

class PhoneBook {
private:
	Contact	contactArray[PHONE_BOOK_SIZE];
	int8_t	lastPosition;
	int8_t	fullness;
public:
	void AddContact ();
	void ShowContacts ();
};

#endif