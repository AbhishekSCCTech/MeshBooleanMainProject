#pragma once
#include "Triangulation.h"
#include "Matrix4x4.h"
#include <map>
#include <cmath>
namespace Transformation
{
	using namespace Geometry;
	class Transformation
	{
	public:
		bool operator()(double a, double b) const;
		Triangulation scaling(Triangulation& triangulation, Geometry::Matrix4x4& matrix, double scalex = 2.0, double scaley = 2.0, double scalez = 1.0);
		Triangulation translation(Triangulation& triangulation, Geometry::Matrix4x4& matrix, double tx = -35.74942, double ty = 34.95682, double tz = 28.57143);
		Triangulation rotation(Triangulation& triangulation, Geometry::Matrix4x4& matrix, double anglex, double angley, double anglez);
		/*Triangulation rotationX(Triangulation& triangulation, Geometry::Matrix4x4& matrix, double anglex=45.0, double angley, double anglez);*/
	};
}