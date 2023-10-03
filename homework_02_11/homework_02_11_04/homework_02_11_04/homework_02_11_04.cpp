// Geometry.cpp :

#include <iostream>
#include <memory>

#include "..\..\..\lib\Geometric_shapes\Geometric_shapes\Codes\Geometric_shapes.h"
#include "..\..\..\lib\Geometric_shapes\Geometric_shapes\Codes\Types.h"
#include "..\..\..\lib\localisation.h"

int main()
{
	bag::Console_localisation locale{
		bag::Console_localisation::Code_pages::rus
	};

	using geo::Param_list;
	using geo::Param;
	using geo::Form;
	using geo::Part;

	const std::vector<geo::Param_list> shapes_data{
		Param_list{ Form::Triangle, {{Part::side, 30},{Part::side, 40},{Part::side, 50}} } ,
		Param_list{ Form::Triangle, {{Part::side, 40},{Part::angle, 30}} },
		Param_list{ Form::Triangle, {{Part::side, 30},{Part::side, 40}} },
		Param_list{ Form::Triangle, {{Part::side, 30}} },
		Param_list{ Form::Triangle, {{Part::side, 30},{Part::side, 40},{Part::side, 150}} }, // Некорректные данные длин сторон
		Param_list{ Form::Triangle, {{Part::angle, 30},{Part::angle, 40},{Part::angle, 50}} }, // Неизвестная фигура
		Param_list{ Form::Triangle, {{Part::side, 30},{Part::side, 40},{Part::side, 50},{Part::side, 50}} }, // Неизвестная фигура
		Param_list{	Form::Quadrangle, {{Part::side, 30},{Part::side, 40},{Part::side, 50},{Part::side, 60}} },
		Param_list{	Form::Quadrangle, {{Part::side, 30},{Part::side, 40}, {Part::angle, 50}} },
		Param_list{	Form::Quadrangle, {{Part::side, 30},{Part::side, 40}} },
		Param_list{	Form::Quadrangle, {{Part::side, 30},{Part::angle, 40}} },
		Param_list{	Form::Quadrangle, {{Part::side, 30}} },
		Param_list{	Form::Quadrangle, {{Part::angle, 30}} } // Неизвестная фигура
	};

	std::vector<std::unique_ptr<geo::IShape*>> shapes{};
	for (const auto& data : shapes_data) {
		try {
			shapes.push_back(
				std::make_unique<geo::IShape*>(
					geo::make_shape(data)
				)
			);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << "\n\n";
		}
	}

	for (const auto& shape : shapes) {
		auto&& [name, is_correct,
			sides, angles] = (*shape)->type_info();
		if (is_correct) {
			using std::cout;
			cout << "\nФигура\n" << name << "\nсоздана.";

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
			cout << '\n';
		}
	}
	return 0;
}