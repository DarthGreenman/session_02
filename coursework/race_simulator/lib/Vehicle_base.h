/* Vehicle_base.h */

#ifndef RACE_SIMULATOR_VEHICLE_BASE_H
#define RACE_SIMULATOR_VEHICLE_BASE_H

#include "Types.h"
#include <string>

namespace race
{
	using std::string;

	class Vehicle_base {
	public:
		Vehicle_base(double speed);
		virtual ~Vehicle_base();

		double speed() const;

	private:
		double speed_;
	};

	inline Vehicle_base::Vehicle_base(double speed) :
		speed_{ speed }
	{
	}

	inline Vehicle_base::~Vehicle_base()
	{
	}

	inline double Vehicle_base::speed() const {
		return speed_;
	}
}
#endif /* RACE_SIMULATOR_VEHICLE_BASE_H */