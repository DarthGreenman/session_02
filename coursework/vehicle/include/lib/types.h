/* types.h */

#ifndef RACE_SIMULATOR_TYPES_H
#define RACE_SIMULATOR_TYPES_H

#include "utilities.h"
#include "menubar.h"

#include <string>

namespace vehicles
{
	/* ������������� ������� ���� �������� ���������. */
	enum class Habitat : char {
		LND = 'A', AIR, ALL
	};

	/* ������������� ��� �������������� � ����� ���� �������� ���������. */
	struct Typeid {
		Habitat		habitat;
		ui::Barkey	bar_key;
	};

	/*
	* ���������� ���� ���������� ������������ ��� ���� �����������
	* ��������� � ���������� ����� ����������:
	* - ��� ������������� ��������;
	* - �������� ������� ��������� ��������� �� ����� ����������� ����;
	* - ������������� ��� �������������� � ����� ���� �������� ���������.
	*/
	namespace types
	{
		using std::string;
		using bag::equal;
		using bag::greater;
		using bag::less;
		using ui::Barkey;
		
		template<typename Arg>
		struct Bactrian {
			static double influence_param(Arg param) {
				return 
					equal<Arg>(param, 0) ? 5.0 : 8.0;
			}
			static inline const string name{ "�������" };
			static inline const Typeid key{ Habitat::LND, Barkey::BAR_01 };
		};
		template<typename Arg>
		struct Dromedar {
			static double influence_param(Arg param) {
				return 
					equal<Arg>(param, 0) ? 5.0 :
						equal<Arg>(param, 1) ? 6.5 : 8.0;
			}
			static inline const string name{ "�������-���������" };
			static inline const Typeid key{ Habitat::LND, Barkey::BAR_02 };
		};
		template<typename Arg>
		struct Centaur {
			static double influence_param(Arg param) {
				return
					greater<Arg>(param, 0) || equal<Arg>(param, 0) ? 2.0 : 0.0;
			}
			static inline const string name{ "�������" };
			static inline const Typeid key{ Habitat::LND, Barkey::BAR_03 };
		};
		template<typename Arg>
		struct Boots {
			static double influence_param(Arg param) {
				return 
					equal<Arg>(param, 0) ? 10.0 : 5.0;
			}
			static inline const string name{ "�������-���������" };
			static inline const Typeid key{ Habitat::LND, Barkey::BAR_04 };
		};
		template<typename Arg>
		struct Carpet {
			static size_t influence_param(Arg param) {
				return 
					less<Arg>(param, 1000.0) ? 0 :
						less<Arg>(param, 5000.0) ? 3 :
							less<Arg>(param, 10000.0) ? 10 : 5;
			}
			static inline const string name{ "�����-�������" };
			static inline const Typeid key{ Habitat::AIR, Barkey::BAR_05 };
		};
		template<typename Arg>
		struct Eagle {
			static size_t influence_param(Arg param) {
				return 
					greater<Arg>(param, 0.0) || equal<Arg>(param, 0.0) ? 6 : 0;
			}
			static inline const string name{ "����" };
			static inline const Typeid key{ Habitat::AIR, Barkey::BAR_06 };
		};
		template<typename Arg>
		struct Broom {
			static size_t influence_param(Arg param) {
				return
					static_cast<size_t>(param / 10000);
			}
			static inline const string name{ "�����" };
			static inline const Typeid key{ Habitat::AIR, Barkey::BAR_07 };
		};
	};
}
#endif /* RACE_SIMULATOR_TYPES_H */