#include "Triangulation.h"

using namespace Geometry;

Triangulation::Triangulation()
{

}

Triangulation::~Triangulation()
{

}

//std::vector<Triangle>& Triangulation::getTriangles() {
//    return triangles; // Returns a reference to the vector of triangles
//}


void Triangulation::add(const Triangulation& other) {
    // Add points from the 'other' Triangulation to this one
    points.insert(points.end(), other.points.begin(), other.points.end());
}

// Definition of the clear method
void Triangulation::clear() {
    // Clears the points vector
    points.clear();
}