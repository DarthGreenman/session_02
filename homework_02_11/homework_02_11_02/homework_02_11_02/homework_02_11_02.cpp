// homework_02_11_02.cpp 

#include <iostream>
#include <string>

#include "Greeter.h"
#include "ILeaver.h"
#include "localisation.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::cerr;

    const bag::Console_localisation locale{
        bag::Console_localisation::Code_pages::rus
    };

    cout << "Введите имя: ";
    std::string name{};
    cin >> name;

    bag::Greeter hello;
    cout << hello.greet(name);
    
    bag::ILeaver* goodbye{};
    try {
        goodbye = bag::make_leaver();
    }
    catch (const std::exception& e) {
        cerr << e.what();
        return 1;
    }
    cout << '\n' << goodbye->leave(name);

    goodbye->release();
    goodbye = nullptr;

    return 0;
}