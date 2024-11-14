#pragma once
#include "Triangle.h"
#include "Triangulation.h"


namespace Geometry {
	class TriangleSelector {
	public:
		TriangleSelector(Triangulation& triangulation);
		~TriangleSelector();

		Triangle SelectTriangle(size_t index);
		Point calculateNormal(Triangle& triangle);

	private:
		Triangulation triangulation;
	};
}
