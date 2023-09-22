/* Fraction.h */

#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <stdexcept>

namespace bag {
	class Fraction	{
		friend const std::string view(const Fraction&);

		friend const bool operator==(const Fraction&, const Fraction&);
		friend const bool operator!=(const Fraction&, const Fraction&);
		friend const bool operator<	(const Fraction&, const Fraction&);
		friend const bool operator>	(const Fraction&, const Fraction&);
		friend const bool operator<=(const Fraction&, const Fraction&);
		friend const bool operator>=(const Fraction&, const Fraction&);

		friend const Fraction operator+(const Fraction&, const Fraction&);
		friend const Fraction operator-(const Fraction&, const Fraction&);
		friend const Fraction operator*(const Fraction&, const Fraction&);
		friend const Fraction operator/(const Fraction&, const Fraction&);

	public:
		Fraction() : num_{}, den_{} {}
		Fraction(int numerator, int denominator) :
			num_{ numerator },
			den_{ denominator != 0 ? denominator :
			throw std::logic_error("Знаменатель равен нулю.") } {}
		~Fraction() {}

		Fraction& operator++();
		const Fraction operator++(int);
		Fraction& operator--();
		const Fraction operator--(int);
	
	private:
		int num_;
		int den_;
	};

	int common_divisor(int, int);
}
#endif /* FRACTION_H */