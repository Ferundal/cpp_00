#include <iostream>

int	is_lower_case(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

int	main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		int pos;
		while (argc > 1)
		{
			pos = 0;
			++argv;
			while ((*argv)[pos] != '\0')
			{
				if (is_lower_case((*argv)[pos]) == true)
					std::cout << (char)((*argv)[pos] - 32);
				else
					std::cout << (*argv)[pos];
				++pos;
			}
			std::cout << std::endl;
			--argc;
		}
	}
}