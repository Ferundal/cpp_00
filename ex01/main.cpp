#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook phoneBook;
	std::string comm;
	std::getline(std::cin, comm);
	while (comm != "EXIT")
	{
		if (comm == "ADD")
			phoneBook.AddContact();
		if (comm == "SEARCH")
			phoneBook.SearchContacts();
		std::getline(std::cin, comm);
	}
}
