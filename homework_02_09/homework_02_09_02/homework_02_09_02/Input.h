﻿/* Input.h */

#ifndef INPUT_H
#define INPUT_H

#include <string>

namespace bag {
    template <typename T>
    T get_input_value(const std::string&, const std::string & =
        "Введите корректное значение для данного типа.");

    template <typename T>
    std::istream& get_input_value(std::istream&, T&, const std::string&,
        const std::string & = "Введите корректное значение для данного типа.");
}

namespace bag {
    template <typename T>
    T get_input_value(const std::string& invite, const std::string& alarm)
    {
        while (true) {
            using std::cout;
            using std::cin;
            cout << invite;
            T res{};
            cin >> res;
            if (cin.fail()) {
                cin.clear();
                cin.ignore((std::numeric_limits<std::streamsize>::max)(),
                    '\n');
                cout << alarm << '\n';
            }
            else {
                cin.ignore((std::numeric_limits<std::streamsize>::max)(),
                    '\n');
                return res;
            }
        }
    }

    template <typename T>
    std::istream& get_input_value(std::istream& in, T& cmd,
        const std::string& invite, const std::string& alarm)
    {
        while (true) {
            std::cout << invite;
            in >> cmd;
            if (in.fail()) {
                in.clear();
                in.ignore((std::numeric_limits<std::streamsize>::max)(),
                    '\n');
                std::cout << alarm << '\n';
            }
            else {
                in.ignore((std::numeric_limits<std::streamsize>::max)(),
                    '\n');
                return in;
            }
        }
    }
}

#endif /* INPUT_H */