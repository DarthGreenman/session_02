// homework_02_10_02.cpp

#include "lib\utilities\localisation.h"
#include "lib\geo\Triangle.h"
#include "lib\geo\Quadrilateral.h"
#include "lib\geo\IShape.h"

#include <iostream>

int main()
{
	bag::Console_localisation localisation{
		bag::Console_localisation::Code_pages::rus
	};

	try
	{
		const geo::Triangle triangle{ 30, 50, 40 };
		const geo::Isosceles isosceles{ 60, 120 };
		const geo::Rectangular rectangular{ 30, 40 };
		const geo::Equilateral equilateral{ 250 };

		const geo::Quadrilateral quadrilateral{ 100, 130, 200, 420 };
		const geo::Square square{ 100 };
		const geo::Rectangle rectangle{ 100, 50 };
		const geo::Parallelogram parallelogram{ 100, 150, 30 };
		const geo::Rhombus rhombus{ 100, 110 };

		using Interface_shape = geo::IShape;
		const Interface_shape* p_tr{ &triangle },
			* p_is{ &isosceles },
			* p_rc{ &rectangular },
			* p_eq{ &equilateral },
			* p_qu{ &quadrilateral },
			* p_sq{ &square },
			* p_re{ &rectangle },
			* p_pr{ &parallelogram },
			* p_rh{ &rhombus };

		const std::vector<const Interface_shape*> list{
				p_tr, p_is, p_rc, p_eq, p_qu, p_sq, p_re, p_pr, p_rh
		};

		using std::cout;
		for (const auto& p : list) {
			auto&& [name, is_correct, sides, angles] = p->type_info();
			cout << "\nИмя типа: " << name;

			cout << "\nстороны: ";
			for (size_t i{}; i < sides.size(); ++i) {
				const std::string sep{ i != sides.size() - 1 ? ", " : ";" };
				cout << sides[i] << sep;
			}

			cout << "\nуглы: ";
			for (size_t i{}; i < angles.size(); ++i) {
				const std::string sep{ i != angles.size() - 1 ? ", " : "." };
				cout << angles[i] << sep;
			}
			cout << "\n\n";
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}

	return 0;
}