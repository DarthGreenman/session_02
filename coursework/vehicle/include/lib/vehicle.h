/* vehicle.h */

#ifndef RACE_SIMULATOR_VEHICLE_H
#define RACE_SIMULATOR_VEHICLE_H

/*
* ������� ��� ������������ ������� ����������� ����� ����������
* ���������� ��������� ��� ����������� �����. 
*/

#include <string>

namespace vehicles
{
	struct Vehicle {
		virtual std::string name() const = 0;
		virtual double race_time(double distance) const = 0;
		virtual ~Vehicle() {}
	};
}
#endif /* RACE_SIMULATOR_VEHICLE_H */