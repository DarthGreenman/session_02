/* shape.cpp */

#include "shape.h"

namespace geo 
{
	Shape::Shape()
	{
	}

	Shape::~Shape()
	{
	}

	unsigned Shape::number_sides() const
	{
		return number_sides_;
	}
}