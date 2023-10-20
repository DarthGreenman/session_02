/* vehicle_land.h */

/*
* ��� �������� ������������ ������� ����������� �������� ������.
* ������������ �������� ������� ����� ��������� ��������
* ��������������� ������� std::same_as<T, ...>.
* ��� ��� ����� ����� ���� ���������� ���� � �������� � ����������
* � ������������� ������ �� ������������, �� ���������:
*  - ����������� �� ���������;
*  - ����������� ����� � �������� ������������ ������������;
*  - ����������� ����������� � �������� ������������ ������������;
*  - ����������,
* ��� ������������� ������������ ������������. ����������� �� ���������
* � ���������� ���������� ����.
*/

#ifndef RACE_SIMULATOR_VEHICLE_LAND_H
#define RACE_SIMULATOR_VEHICLE_LAND_H

#ifdef VEHICLE_LIBRARY_EXPORT
#define VEHICLE_LIBRARY_DLL __declspec(dllexport)
#else
#define VEHICLE_LIBRARY_DLL __declspec(dllimport)
#endif

#include "vehicle.h"
#include "types.h"

#include <string>
#include <concepts>

namespace vehicles 
{
	template<typename T>
	concept Type_land = std::same_as<T, types::Bactrian<size_t>> ||
		std::same_as<T, types::Dromedar<size_t>> ||
		std::same_as<T, types::Centaur<size_t>> ||
		std::same_as<T, types::Boots<size_t>>;
	
	template<class T> 
		requires Type_land<T> 
	class Vehicle_land : 
		public Vehicle
	{
	public:
		Vehicle_land() = default;
		VEHICLE_LIBRARY_DLL Vehicle_land(double speed, double time_before_rest);
		~Vehicle_land() =default;

	public:
		VEHICLE_LIBRARY_DLL std::string name() const override final;
		VEHICLE_LIBRARY_DLL double race_time(double distance) const override final;

	private:
		double speed_{};
		double time_before_rest_{};
	};
}
#endif /* RACE_SIMULATOR_VEHICLE_LAND_H */