/* shape.h */

#ifndef SHAPE_H
#define SHAPE_H

namespace geo {
	class Shape	{
	public:
		Shape();
		~Shape();

		virtual unsigned number_sides() const;

	private:
		unsigned number_sides_{ 0 };
	};
}
#endif /* SHAPE_H */