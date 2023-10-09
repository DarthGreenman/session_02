/* Types.h */

#ifndef RACE_SIMULATOR_TYPES_H
#define RACE_SIMULATOR_TYPES_H

#include <string>
#include <vector>

namespace race
{
	enum class Seq : size_t {
		first = 1, second, others, all,
		thousand = 1000, five_thousand = 5000, ten_thousand = 10000
	};

	struct Feature {
		Seq seq;
		double value;
	};

	enum class Menubar : char {
		QUIT = 'Q', BAR_01= 'A', BAR_02, BAR_03, BAR_04, BAR_05, BAR_06, BAR_07
	};
	
	inline Menubar& operator++(Menubar& bar) {
		bar = static_cast<Menubar>(static_cast<char>(bar) + 1);
		return bar;
	}

	inline Menubar operator++(Menubar& bar, int) {
		Menubar prev{ bar };
		bar = static_cast<Menubar>(static_cast<char>(bar) + 1);
		return prev;
	}

	enum class Habitat : char {
		LND = 'A', AIR, ALL
	};

	struct Typeid {
		Habitat habitat;
		Menubar menubar;
	};
	
	namespace vehicle
	{
		using std::vector;
		using std::string;
		
		struct Camel {
			static double speed(double speed, double time_before_rest,
				const vector<Feature>& features);
			static inline const string name{ "Верблюд" };
			static inline const Typeid id{ Habitat::LND, Menubar::BAR_01 };
		};
		struct Fast_camel {
			static double speed(double speed, double time_before_rest,
				const vector<Feature>& features);
			static inline const string name{ "Верблюд-быстроход" };
			static inline const Typeid id{ Habitat::LND, Menubar::BAR_02 };
		};
		struct Centaur {
			static double speed(double speed, double time_before_rest,
				const vector<Feature>& features);
			static inline const string name{ "Кентавр" };
			static inline const Typeid id{ Habitat::LND, Menubar::BAR_03 };
		};
		struct Boots {
			static double speed(double speed, double time_before_rest,
				const vector<Feature>& features);
			static inline const string name{ "Ботинки-вездеходы" };
			static inline const Typeid id{ Habitat::LND, Menubar::BAR_04 };
		};
		struct Carpet {
			static double speed(double speed,
				const vector<Feature>& features);
			static inline const string name{ "Ковер-самолет" };
			static inline const Typeid id{ Habitat::AIR, Menubar::BAR_05 };
		};
		struct Eagle {
			static double speed(double speed,
				const vector<Feature>& features);
			static inline const string name{ "Орел" };
			static inline const Typeid id{ Habitat::AIR, Menubar::BAR_06 };
		};
		struct Broom {
			static double speed(double speed,
				const vector<Feature>& features);
			static inline const string name{ "Метла" };
			static inline const Typeid id{ Habitat::AIR, Menubar::BAR_07 };
		};
	};
}
#endif /* RACE_SIMULATOR_TYPES_H */