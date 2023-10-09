/* Vihicle_air.h */

#ifndef RACE_SIMULATOR_VEHICLE_AIR_H
#define RACE_SIMULATOR_VEHICLE_AIR_H

#include "Vehicle_base.h"
#include "Vehicle.h"
#include "Types.h"

namespace race
{
	using std::vector;
	using std::string;

	template<class T>
	class Vehicle_air :	
		public Vehicle_base,
		public Vehicle
	{
	public:
		Vehicle_air(const vector<Feature>& features, double speed);
		~Vehicle_air();

		string name() const override final;
		double speed() const override final;

	private:
		std::vector<Feature> features_;
	};

	template<class T>
	inline Vehicle_air<T>::Vehicle_air(const vector<Feature>& features,
		double speed) :
		Vehicle_base{ speed }, features_{ features }
	{
	}

	template<class T>
	inline Vehicle_air<T>::~Vehicle_air()
	{
	}

	template<class T>
	inline string Vehicle_air<T>::name() const {
		return
			T::name;
	}

	template<class T>
	inline double Vehicle_air<T>::speed() const	{
		return
			T::speed(Vehicle_base::speed(), features_);
	}
}
#endif /* RACE_SIMULATOR_VEHICLE_AIR_H */