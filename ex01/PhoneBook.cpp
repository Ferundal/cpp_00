/*
 * Realisation of methodds of PhoneBook class
 */

#include "PhoneBook.hpp"

static int8_t PBStringToDigit(std::string s) {
	if (s == "1")
		return (1);
	else if (s == "2")
		return (2);
	else if (s == "3")
		return (3);
	else if (s == "4")
		return (4);
	else if (s == "5")
		return (5);
	else if (s == "6")
		return (6);
	else if (s == "7")
		return (7);
	else if (s == "8")
		return (8);
	else
		return (-1);
}

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
		std::string s_pos;
		std::getline(std::cin, s_pos);
		pos = PBStringToDigit(s_pos);
		while (pos == -1) {
			std::getline(std::cin, s_pos);
			pos = PBStringToDigit(s_pos);
		}
		pos = (pos - 1 + lastPosition) % PHONE_BOOK_SIZE;
		contactArray[pos].PutContact();
	}
}