/* Vehicle.h */

#ifndef RACE_SIMULATOR_VEHICLE_H
#define RACE_SIMULATOR_VEHICLE_H

#include <string>

namespace race
{
	struct Vehicle {
		virtual std::string name() const = 0;
		virtual double speed() const = 0;
		virtual ~Vehicle() = 0 {}
	};
}
#endif /* RACE_SIMULATOR_VEHICLE_H */