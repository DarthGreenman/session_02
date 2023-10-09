/* Types.cpp */

#include "Types.h"

namespace race
{
	double vehicle::Camel::speed(double speed,
		double time_before_rest,
		const std::vector<Feature>& features)
	{
		return 10.0;
	}

	double vehicle::Fast_camel::speed(double speed,
		double time_before_rest,
		const std::vector<Feature>& features)
	{
		return 20.0;
	}

	double vehicle::Centaur::speed(double speed,
		double time_before_rest,
		const std::vector<Feature>& features)
	{
		return 30.0;
	}

	double vehicle::Boots::speed(double speed,
		double time_before_rest,
		const std::vector<Feature>& features)
	{
		return 40.0;
	}

	double vehicle::Carpet::speed(double speed,
		const std::vector<Feature>& features)
	{
		return 50.0;
	}

	double vehicle::Eagle::speed(double speed,
		const std::vector<Feature>& features)
	{
		return 60.0;
	}

	double vehicle::Broom::speed(double speed,
		const std::vector<Feature>& features)
	{
		return 70.0;
	}

}