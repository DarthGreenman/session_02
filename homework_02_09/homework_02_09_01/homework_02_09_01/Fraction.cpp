/* Fraction.cpp */

#include "Fraction.h"

namespace bag {
	const std::string view(const Fraction& val) {
		return std::to_string(val.num_) + '/' +
			std::to_string(val.den_);
	}

	const bool operator==(const Fraction& lhs, const Fraction& rhs) {
		return lhs.den_ == rhs.den_ ? lhs.num_ == rhs.num_ :
			lhs.num_ * rhs.den_ == rhs.num_ * lhs.den_;
	}

	const bool operator!=(const Fraction& lhs, const Fraction& rhs) {
		return !(lhs == rhs);
	}

	const bool operator<(const Fraction& lhs, const Fraction& rhs) {
		return lhs.den_ == rhs.den_ ? lhs.num_ < rhs.num_ :
			lhs.num_ * rhs.den_ < rhs.num_ * lhs.den_;
	}

	const bool operator>(const Fraction& lhs, const Fraction& rhs) {
		return lhs.den_ == rhs.den_ ? lhs.num_ > rhs.num_ :
			lhs.num_ * rhs.den_ > rhs.num_ * lhs.den_;
	}

	const bool operator<=(const Fraction& lhs, const Fraction& rhs) {
		return lhs < rhs || lhs == rhs;
	}

	const bool operator>=(const Fraction& lhs, const Fraction& rhs) {
		return lhs > rhs || lhs == rhs;
	}

	Fraction make_fraction(int numerator, int denominator) {
		return Fraction(numerator, denominator);
	}
}