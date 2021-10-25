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
	firstContactPosition = PHONE_BOOK_SIZE - 1;

}

void PhoneBook::AddContact () {
	if (fullness < PHONE_BOOK_SIZE)
		++fullness;
	if (firstContactPosition == PHONE_BOOK_SIZE - 1)
		firstContactPosition = 0;
	else
		++firstContactPosition;
	contactArray[firstContactPosition].FillContact();
}

void PhoneBook::SearchContacts () {
	std::cout << "index     |first name|last name |nickname" <<std::endl;
	if (fullness > 0) {
		int8_t pos = firstContactPosition;
		for (int i = 0; i < fullness; ++i) {
			Contact &curr = contactArray[pos];
			std::cout << std::setw (PHONE_FEELD_SIZE) << (i + 1) << '|';
			std::cout << std::setw (PHONE_FEELD_SIZE) << curr.GetNameLimited(PHONE_FEELD_SIZE) << '|';
			std::cout << std::setw (PHONE_FEELD_SIZE) << curr.GetLastNameLimited(PHONE_FEELD_SIZE) << '|';
			std::cout << std::setw (PHONE_FEELD_SIZE) << curr.GetNicknameLimited(PHONE_FEELD_SIZE) << std::endl;
			if (pos != 0)
				--pos;
			else
				pos = PHONE_BOOK_SIZE - 1;
		}
		std::string s_pos;
		std::cout << "Enter contact index higher than 0 and lower than " << (int)fullness << ':' << std::endl;
		std::getline(std::cin, s_pos);
		pos = PBStringToDigit(s_pos);
		while (pos == -1 || pos > fullness) {
			std::cout << "Enter contact index higher than 0 and lower than " << (int)fullness << ':' << std::endl;
			std::getline(std::cin, s_pos);
			pos = PBStringToDigit(s_pos);
		}
		pos = firstContactPosition - (pos - 1);
		if (pos < 0)
			pos += PHONE_BOOK_SIZE;
		contactArray[pos].PutContact();
	}
}