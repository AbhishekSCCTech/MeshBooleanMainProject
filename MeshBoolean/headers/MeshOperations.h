#pragma once
#include "Triangulation.h"
#include<vector>

namespace Geometry
{
    class MeshOperations
    {
    public:
        MeshOperations();
        ~MeshOperations();

        
        std::vector<double> CrossProduct(Triangulation& tri, Triangulation& tri2);
        std::vector<double> AveragePoint(Triangulation& tri);
        double getAngleBetweenNormalAndXAxis(Triangulation& tri, Point normal);

   
    };
}