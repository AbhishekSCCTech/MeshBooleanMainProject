#include "Triangulation.h"
#include "MeshOperations.h"
#include <cmath>
#define M_PI 3.14

using namespace Geometry;

Geometry::MeshOperations::MeshOperations()
{

}

Geometry::MeshOperations::~MeshOperations()
{

}


std::vector<double> Geometry::MeshOperations::CrossProduct(Triangulation& tri, Triangulation& tri2)
{
    Geometry::Triangle triangle1 = tri.Triangles[0];

    Geometry::Triangle triangle2 = tri2.Triangles[0];


    double ax = tri.UniqueNumbers[triangle1.Normal().X()], ay = tri.UniqueNumbers[triangle1.Normal().Y()], az = tri.UniqueNumbers[triangle1.Normal().Z()];
    double bx = tri2.UniqueNumbers[triangle2.Normal().X()], by = tri2.UniqueNumbers[triangle2.Normal().Y()], bz = tri2.UniqueNumbers[triangle2.Normal().Z()];

    double crossX = ay * bz - az * by;
    double crossY = az * bx - ax * bz;
    double crossZ = ax * by - ay * bx;

    std::vector<double> pn = { crossX, crossY, crossZ };
    return  pn;
}


std::vector<double> Geometry::MeshOperations::AveragePoint(Triangulation& tri) {
    Geometry::Triangle triangle1 = tri.Triangles[0];
    double ax = tri.UniqueNumbers[triangle1.P1().X()], ay = tri.UniqueNumbers[triangle1.P1().Y()], az = tri.UniqueNumbers[triangle1.P1().Z()];
    double bx = tri.UniqueNumbers[triangle1.P2().X()], by = tri.UniqueNumbers[triangle1.P2().Y()], bz = tri.UniqueNumbers[triangle1.P2().Z()];
    double cx = tri.UniqueNumbers[triangle1.P3().X()], cy = tri.UniqueNumbers[triangle1.P3().Y()], cz = tri.UniqueNumbers[triangle1.P3().Z()];

    double Avgx = (ax + bx + cx) / 3;
    double Avgy = (ay + by + cy) / 3;
    double Avgz = (az + bz + cz) / 3;

    std::vector<double> AvgPoint = { Avgx, Avgy, Avgz };
    return  AvgPoint;
}

double Geometry::MeshOperations::getAngleBetweenNormalAndXAxis(Triangulation& tri, Point normal) {
    double nx = tri.UniqueNumbers[normal.X()];
    double ny = tri.UniqueNumbers[normal.Y()];
    double nz = tri.UniqueNumbers[normal.Z()];

    double magnitude = std::sqrt(nx * nx + ny * ny + nz * nz);

    double cosTheta = nx / magnitude;
    double angle = std::acos(cosTheta) * (180.0 / M_PI);
    return angle;
}


