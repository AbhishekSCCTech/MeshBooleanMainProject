#pragma once
#include "Triangle.h"
#include<vector>

namespace Geometry
{
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        std::vector<double> UniqueNumbers;
        std::vector<Triangle> Triangles;
       

    private:
        std::vector<Point> points;
        std::vector<Triangle> triangles; 
    };
}