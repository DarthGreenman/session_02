/* Fraction.cpp */

#include "Fraction.h"

#include <vector>

namespace bag {
	const std::string view(const Fraction& val) {
		return val.num_ == 0 ? "0" : val.num_ == val.den_ ? "1" :
			std::to_string(val.num_) + '/' +
			std::to_string(val.den_);
	}

	const bool operator==(const Fraction& lhs, const Fraction& rhs)
	{
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

	const Fraction operator+(const Fraction& lhs, const Fraction& rhs)	{
		return Fraction(lhs.num_ * rhs.den_ + rhs.num_ * lhs.den_,
			lhs.den_ * rhs.den_);
	}

	const Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
		return Fraction(lhs.num_ * rhs.den_ - rhs.num_ * lhs.den_,
			lhs.den_ * rhs.den_);
	}

	const Fraction operator*(const Fraction& lhs, const Fraction& rhs)
	{
		const int div{ 
			common_divisor(lhs.num_ * rhs.num_, lhs.den_ * rhs.den_)
		};
		return Fraction(lhs.num_ * rhs.num_ / div, lhs.den_ * rhs.den_ / div);
	}

	const Fraction operator/(const Fraction& lhs, const Fraction& rhs)	{
		return lhs * Fraction(rhs.den_, rhs.num_);
	}

	Fraction& Fraction::operator++()
	{
		num_ += den_;
		return *this;
	}

	const Fraction Fraction::operator++(int)
	{
		Fraction fr(*this);
		++*this;
		return fr;
	}

	Fraction& Fraction::operator--()
	{
		num_ -= den_;
		return *this;
	}

	const Fraction Fraction::operator--(int)
	{
		Fraction fr(*this);
		--*this;
		return fr;
	}

	int common_divisor(int num_one, int num_two)
	{
		for (int div{ num_one <= num_two ? num_one : num_two }; div > 1; --div) {
			if (num_one % div == 0 && num_two % div == 0) {
				return div;
			}
		}
		const int default_common_divisor{ 1 };
		return default_common_divisor;
	}
}