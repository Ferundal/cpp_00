/*
 * Realisation of methodds of Contact class
 */

#include "Contact.hpp"

static std::string CutStringByLimit (std::string &str, unsigned int limit) {
	std::string new_str (str);
	unsigned int	len = new_str.size();
	if (len > limit) {
		new_str.resize(limit);
		if (limit > DOTS_AMNT)
			new_str.replace(len - DOTS_AMNT, len, DOTS_AMNT, '.');
	} else
		new_str.resize(limit, ' ');
	return (new_str);
}

void Contact::FillContact () {
	std::cout << "Insert name:" << std::endl;
	std::cin >> name;
	std::cout << "Insert last name:" << std::endl;
	std::cin >> lastName;
	std::cout << "Insert nickname:" << std::endl;
	std::cin >> nickname;
	std::cout << "Insert phone number:" << std::endl;
	std::cin >> phoneNumber;
	std::cout << "Insert darkest secret:" << std::endl;
	std::cin >> darkestSecret;
}

std::string Contact::GetNameLimited (unsigned int limit) {
	return (CutStringByLimit(name, limit));
}

std::string Contact::GetLastNameLimited (unsigned int limit){
	return (CutStringByLimit(lastName, limit));
}

std::string Contact::GetNicknameLimited (unsigned int limit){
	return (CutStringByLimit(nickname, limit));
}