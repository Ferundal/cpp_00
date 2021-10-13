/*
 * Realisation of methodds of PhoneBook class
 */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook () {
	fullness = 0;
	lastPosition = 0;
}

void PhoneBook::AddContact () {
	if (fullness < 10)
		++fullness;
	if (lastPosition == PHONE_BOOK_SIZE - 1)
		lastPosition = 0;
	else
		++lastPosition;
	contactArray[lastPosition].FillContact();
}

void PhoneBook::SearchContacts () {
	std::cout << "index     |first name|last name |nickname" <<std::endl;
	if (fullness > 0) {
		int8_t pos = lastPosition;
		for (int i = 0; i < fullness; ++i) {
			Contact &curr = contactArray[pos];
			std::cout << std::setw (PHONE_FEELD_SIZE) << (i + 1) << '|';
			std::cout << std::setw (PHONE_FEELD_SIZE) << curr.GetNameLimited(PHONE_FEELD_SIZE) << '|';
			std::cout << std::setw (PHONE_FEELD_SIZE) << curr.GetLastNameLimited(PHONE_FEELD_SIZE) << '|';
			std::cout << std::setw (PHONE_FEELD_SIZE) << curr.GetNicknameLimited(PHONE_FEELD_SIZE) << std::endl;
			if (pos < PHONE_BOOK_SIZE - 1)
				++pos;
			else
				pos = 0;
		}
		std::cin >> pos;
		if (pos > 0 && pos < PHONE_BOOK_SIZE) {
			pos = (pos - 1 + lastPosition) % PHONE_BOOK_SIZE;
			contactArray[pos].PutContact();
		}
	}
}