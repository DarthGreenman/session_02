/* Vehicle_land.h */

#ifndef RACE_SIMULATOR_VEHICLE_LAND_H
#define RACE_SIMULATOR_VEHICLE_LAND_H

#include "Vehicle_base.h"
#include "Vehicle.h"
#include "Types.h"

#include <string>
#include <vector>

namespace race 
{
	using std::vector;
	using std::string;
	
	template<class T>
	class Vehicle_land : 
		public Vehicle_base,
		public Vehicle
	{
	public:
		Vehicle_land(const vector<Feature>& features, double speed,
			double time_before_rest);
		~Vehicle_land();

		string name() const override final;
		double speed() const override final;

	private:
		vector<Feature> features_;
		double time_before_rest_;
	};

	template<class T>
	inline Vehicle_land<T>::Vehicle_land(const vector<Feature>& features,
		double speed, double time_before_rest) :
		Vehicle_base{ speed }, features_{ features }, 
		time_before_rest_{ time_before_rest }
	{
	}

	template<class T>
	inline Vehicle_land<T>::~Vehicle_land()
	{
	}

	template<class T>
	inline string Vehicle_land<T>::name() const {
		return
			T::name;
	}

	template<class T>
	inline double Vehicle_land<T>::speed() const {
		return
			T::speed(Vehicle_base::speed(), time_before_rest_, features_);
	}
}
#endif /* RACE_SIMULATOR_VEHICLE_LAND_H */