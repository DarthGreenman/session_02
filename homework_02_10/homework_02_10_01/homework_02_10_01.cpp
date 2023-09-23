/* homework_02_10_01.cpp */

/*
* Введите имя: Виталий
* Здравствуйте, Виталий!
*/

#include <iostream>
#include <string>

#include "localisation.h"

int main() {
	bag::Console_localisation locale{
		bag::Console_localisation::Code_pages::rus
	};

	std::cout << "Введите имя: ";
	std::string name{};
	std::cin >> name;

	std::cout << "Здравствуйте, " << name << '!';

	return 0;
}