/* race_simulator.cpp */

#include "../lib/Racers.h"
#include "../lib/Types.h"

#include "../lib/Localisation.h"
#include "../lib/Input.h"

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

namespace race_view {
    using Menu = std::vector<std::pair<race::Menubar, std::string>>;
    Menu make_menu(const std::string& menu_raw, char del);
    Menu make_menu(char type_race);
    std::vector<std::pair<race::Typeid, std::string>> make_racers();
    
    void view();
    void view(size_t bar_num, race::Menubar bar_id, const std::string& bar_name);
    void view(const std::vector<std::pair<race::Menubar, std::string>>& menu);
    void view(const race::Info& info);
};

int main()
{
    bag::Console_localisation locale{
        bag::Console_localisation::Code_pages::rus
    };
    using std::cout;
    using std::cin;

    /***********************************************************************************/
    /* Добро пожаловать в гоночный симулятор:
     * 1. Cоздание экземпляра типа Race.
     * 2. Выбор типов участников.
     * 3. Инициализация дистанции. */
    cout << "ДОБРО ПОЖАЛОВАТЬ В ГОНОЧНЫЙ СИМУЛЯТОР!\n";
    const auto menu_main =
        race_view::make_menu("Гонка для наземного транспорта |"
        "Гонка для воздушного транспорта |"
        "Гонка для наземного и воздушного транспортов", '|');
    race_view::view(menu_main); /* Вывод меню выбора типа гонки */
    const char type_race{ bag::get_input_value<char>("Выберите тип гонки: ") };
    
    if (std::toupper(type_race) == static_cast<char>(race::Menubar::QUIT)) {
        return 0; /* Выход */
    }

    /***********************************************************************************/
    const size_t distance{ bag::get_input_value<size_t>("Укажите длину дистанции: ") };
    cout << "\nДОЛЖНО БЫТЬ ЗАРЕГИСТРИРОВАНО НЕ МЕНЕЕ 2-х ТРАНСПОРТНЫХ \nСРЕДСТВ.\n";
    const auto menu_sub =
        race_view::make_menu("Зарегистровать транспорт|", '|');
    race_view::view(menu_sub); /* Вывод меню регистрации */
    if (std::toupper(bag::get_input_value<char>("Выберите действие: ")) ==
        static_cast<char>(race::Menubar::QUIT))
    {
        return 0;
    }

    /***********************************************************************************/
    /* Вывод информации по гонке */
    const auto menu_racers = race_view::make_menu(type_race);
    race_view::view(menu_racers); /* Вывод меню выбора участников */
       
    race::Racers racers{};
    for (char pos{ static_cast<char>(race::Menubar::BAR_01) };
        std::toupper(pos) != static_cast<char>(race::Menubar::QUIT);)
    {
        race_view::view(racers.info());
        for (; bag::get_input_value<char>(cin, pos, "\nВыберите транспортное средство: ") &&
            std::toupper(pos) != static_cast<char>(race::Menubar::QUIT);)
        {
            try {
                if (const bool is_add{ racers.add_racer(pos) }; is_add) {
                    break;
                }
                else {
                    std::cout << "Транспортное средство было зарегистрированное ранее.";
                }
            }
            catch (const std::exception& e) {
                cout << e.what();
            }
        }
    }
   /*
    std::system("cls");
    race::view(race::make_menu());
    cout << "\nУчастники гонок:\n";
    race::view(racers.info());
   */
    std::system("pause");
    return 0;
}

namespace race_view
{ 
    std::vector<std::pair<race::Menubar, std::string>> make_menu(
        const std::string& menu_raw, char del
    )
    {
        std::stringstream menu_stream{ menu_raw };
        std::string bar_name;
        std::vector<std::pair<race::Menubar, std::string>> menu{};
        auto bar_id{ race::Menubar::BAR_01 };
        
        while (std::getline(menu_stream, bar_name, del)) {
            const std::pair<race::Menubar, std::string> bar{
                std::make_pair(bar_id, bar_name)
            };
            ++bar_id;
            menu.push_back(bar);
        }
        menu.push_back(std::make_pair(race::Menubar::QUIT, "Выход"));
        return menu;
    }

    std::vector<std::pair<race::Menubar, std::string>> make_menu(char type_race)
    {
        static auto racers = race_view::make_racers();
        std::vector<std::pair<race::Menubar, std::string>> menu{};
        for (const auto& racer : racers) {
            auto&& [id, name] = racer;
            if (std::toupper(type_race) == static_cast<char>(id.habitat))
            {
                menu.push_back(std::make_pair(id.menubar, name));
            }
        }
        menu.push_back(std::make_pair(race::Menubar::QUIT, "Выход"));
        return menu;
    }
    
    std::vector<std::pair<race::Typeid, std::string>> make_racers()
    {
        using namespace race::vehicle;
        const std::vector<std::pair<race::Typeid, std::string>> menu{
            {std::make_pair(Camel::id,       Camel::name)},
            {std::make_pair(Fast_camel::id,  Fast_camel::name)},
            {std::make_pair(Centaur::id,     Centaur::name)},
            {std::make_pair(Boots::id,       Boots::name)},
            {std::make_pair(Carpet::id,      Carpet::name)},
            {std::make_pair(Eagle::id,       Eagle::name)},
            {std::make_pair(Broom::id,       Broom::name)}
        };
        return menu;
    }
   
    void view()
    {
        std::cout << "\n| N | ";
        std::cout.setf(std::ios::left);
        std::cout.width(50);
        std::cout << "НАИМЕНОВАНИЕ ДЕЙСТВИЯ";
        std::cout << "| ВЫБОР |" << '\n';
    }
     
    void view(size_t bar_num, race::Menubar bar_id, const std::string& bar_name)
    {
        std::cout << "| " << bar_num << " | ";
        std::cout.setf(std::ios::left);
        std::cout.width(50);
        std::cout << bar_name;
        std::cout << "|   " << static_cast<char>(bar_id);
        std::cout << "   |\n";
    }

    void view(const std::vector<std::pair<race::Menubar, std::string>>& menu)
    {
        race_view::view();
        size_t bar_num{};
        for(const auto& bar : menu) {
            auto&& [bar_id, bar_name] = bar;
            view(++bar_num, bar_id, bar_name);
        }
    }

    void view(const race::Info& info)
    {
        auto&& [number, members] = info;
        for (size_t i{}; i < number; ++i) {
            std::cout << members[i]->name() << (i + 1 == number ? "." : ", ");
        }
    }
}