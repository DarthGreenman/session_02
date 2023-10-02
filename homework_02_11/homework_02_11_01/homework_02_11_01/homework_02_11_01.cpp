// homework_02_11_01.cpp 

#include <iostream>
#include <string>

#include "../../lib/Greeter/Greeter/Greeter.h"
#include "../../lib/localisation.h"

int main()
{
    const bag::Console_localisation locale{
        bag::Console_localisation::Code_pages::rus
    };

    std::cout << "Введите имя: ";
    std::string name{};
    std::cin >> name;

    bag::Greeter message;
    std::cout << message.greet(name);

    return 0;
}