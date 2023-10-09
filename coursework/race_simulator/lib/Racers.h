/* Racers.h */

#ifndef RACE_SIMULATOR_RACERS_H
#define RACE_SIMULATOR_RACERS_H

#include <vector>

#include "Vehicle.h"
#include "Types.h"

namespace race
{
	using std::vector;

	struct Info {
		size_t number_members;
		vector<Vehicle*> list_members;
	};

	class Racers
	{
	public:
		Racers();
		~Racers();

	private:
		Vehicle* make_racer(char pos);

	public:
		bool add_racer(char pos);
		Info info() const;

	private:
		vector<Vehicle*> racers_{};
	};
}
#endif /* RACE_SIMULATOR_RACERS_H */