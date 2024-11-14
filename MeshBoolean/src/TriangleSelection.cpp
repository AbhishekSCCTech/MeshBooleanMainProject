#include "TriangleSelection.h"
#include <stdexcept>
#include <cmath>

namespace Geometry {

    TriangleSelector::TriangleSelector(Triangulation& triangulation)
        : triangulation(triangulation)
    {
    }

    TriangleSelector::~TriangleSelector()
    {
    }

    // Method to select a triangle by index
    Triangle TriangleSelector::SelectTriangle(size_t index) {
        if (index >= triangulation.triangles().size()) {
            throw std::out_of_range("Index out of range");
        }
        return triangulation.triangles().at(index);
    }


    // Method to calculate the normal vector using cross product
    Point TriangleSelector::calculateNormal(Triangle& triangle) {
        Point p1 = triangle.P1();
        Point p2 = triangle.P2();
        Point p3 = triangle.P3();

        // Calculate vectors V1 and V2
        int V1x = p2.X() - p1.X();
        int V1y = p2.Y() - p1.Y();
        int V1z = p2.Z() - p1.Z();

        int V2x = p3.X() - p1.X();
        int V2y = p3.Y() - p1.Y();
        int V2z = p3.Z() - p1.Z();

        // Calculate cross product V1 x V2
        int Nx = V1y * V2z - V1z * V2y;
        int Ny = V1z * V2x - V1x * V2z;
        int Nz = V1x * V2y - V1y * V2x;

        return Point(Nx, Ny, Nz); // Return the normal as a Point
    }

}