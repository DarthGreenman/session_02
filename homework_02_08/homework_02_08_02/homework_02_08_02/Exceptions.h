/* Exceptions.h */
/*
* ������� ����� Errors_data (����������� �� std::logic_error) - ����������
* ��� ���������� ������� ������������ ��� ������������� ������ ��������,
* ��������, ��������, ��������������� ���������. ��� �� ������� �����
* ���������� ��������� ���� Bad_value � Bad_data � ���� ���������
* geo::Errors_data, ��� ��������� �������� ����.
* ���������� Errors_data ���������� ������ ��������, ��������: < 0; > 180; > 360 � �.�.
* ���������� Bad_data ���������� ������ ������ ��������, ��������:
* ����� ����� != 180 (360); ����� ������� >= ����� ��������� ������.
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

namespace geo {
	class Errors_data
		: public std::logic_error {
	public:
		Errors_data(const std::string& message) :
			std::logic_error(message) {}

		~Errors_data() {}

		const char* what() const noexcept override {
			return std::exception::what();
		}
	};

	class Bad_value
		: public Errors_data {
	public:
		Bad_value(const std::string& message) :
			Errors_data(message) {}

		~Bad_value() {}

		const char* what() const noexcept override {
			return Errors_data::what();
		}
	};

	class Bad_data
		: public Errors_data {
	public:
		Bad_data(const std::string& message) :
			Errors_data(message) {}

		~Bad_data() {}

		const char* what() const noexcept override {
			return Errors_data::what();
		}
	};
}
#endif /* EXCEPTIONS_H */