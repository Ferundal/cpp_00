/*
 * Realisation of methodds of PhoneBook class
 */

#include "PhoneBook.hpp"

void PhoneBook::AddContact () {
	if (fullness < 10)
		++fullness;
	if (lastPosition == PHONE_BOOK_SIZE - 1)
		lastPosition = 0;
	else
		++lastPosition;
	contactArray[lastPosition].FillContact();
}

void PhoneBook::ShowContacts () {
	std::cout << "index     |first name|last name |nickname" <<std::endl;
	if (fullness > 0) {
		Contact &curr = contactArray[lastPosition];
		for (int i = 0; i < fullness; i++) {
			std::cout << std::setw (10) << i << '|';
			std::cout << curr.GetNameLimited(PHONE_FEELD_SIZE) << '|';
			std::cout << curr.GetLastNameLimited(PHONE_FEELD_SIZE) << '|';
			std::cout << curr.GetNicknameLimited(PHONE_FEELD_SIZE);
		}
	}
}