/* quadrilateral.cpp */

#include "quadrilateral.h"

namespace geo
{
	Quadrilateral::Quadrilateral()
	{
	}

	Quadrilateral::~Quadrilateral()
	{
	}

	unsigned Quadrilateral::number_sides() const
	{
		return number_sides_;
	}
}