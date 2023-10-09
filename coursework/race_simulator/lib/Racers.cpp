/* "Racers.cpp */

#include "Racers.h"
#include "Vehicle_land.h"
#include "Vehicle_air.h"

#include <stdexcept>

namespace race
{
	Racers::Racers()
	{
	}

	Racers::~Racers()
	{
		for (auto& racer : racers_) {
			if (racer) {
				delete racer;
				racer = nullptr;
			}
		}
	}

    Vehicle* Racers::make_racer(char pos)
    {
        Vehicle* racer{};
        switch (pos)
        {
            case static_cast<char>(Menubar::BAR_01):
                racer =
                    new Vehicle_land<vehicle::Camel>({ Feature{Seq::first, 5.0},
                        Feature{Seq::others, 8.0} }, 10.0, 30);
                break;
            case static_cast<char>(Menubar::BAR_02):
                racer =
                    new Vehicle_land<vehicle::Fast_camel>({ Feature{Seq::first, 5.0},
                        Feature{Seq::second, 6.5}, Feature{Seq::others, 8.0} }, 40.0, 10);
                break;
            case static_cast<char>(Menubar::BAR_03):
                racer =
                    new Vehicle_land<vehicle::Centaur>({ Feature{Seq::all, 2.0} },
                        15.0, 8);
                break;
            case static_cast<char>(Menubar::BAR_04):
                racer =
                    new Vehicle_land<vehicle::Boots>({ Feature{Seq::first, 10.0},
                        Feature{Seq::others, 5.0} }, 6.0, 60);
                break;
            case static_cast<char>(Menubar::BAR_05):
                racer =
                    new Vehicle_air<vehicle::Carpet>({ Feature{Seq::thousand, 0.0},
                        Feature{Seq::five_thousand, 3.0}, Feature{Seq::ten_thousand, 10.0},
                        Feature{Seq::ten_thousand, 5.0} }, 10.0);
                break;
            case static_cast<char>(Menubar::BAR_06):
                racer =
                    new Vehicle_air<vehicle::Eagle>({ Feature{Seq::all, 6.0} }, 8.0);
                break;
            case static_cast<char>(Menubar::BAR_07):
                racer =
                    new Vehicle_air<vehicle::Broom>({ Feature{Seq::thousand, 1.0} }, 20.0);
                break;
            default:
                throw std::logic_error{ "Выберите корректное значение." };
        }
        return racer;
    }

	bool Racers::add_racer(char pos)
	{
        if (const Vehicle* racer{ make_racer(std::toupper(pos)) }; racer) {
            for (const auto& racer_registered : racers_) {
                if (racer_registered->name() == racer->name()) {
                    return false;
                }
            }
            racers_.push_back(const_cast<Vehicle*>(racer));
            return true;
        }
        return false;
    }

    Info Racers::info() const {
        return
            Info{ racers_.size(), racers_ };
    }
}