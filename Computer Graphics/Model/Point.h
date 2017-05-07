//
// Created by maples on 4/19/17.
//

#ifndef COMPUTER_GRAPHICS_POINT_H
#define COMPUTER_GRAPHICS_POINT_H

#include "Object.h"

#include <array>

class Point2D : public Object
{
public:
    Point2D(double x, double y) : X(x), Y(y)
    {
    }

    std::array<double, 2> Get();

private:
    double X;
    double Y;
};

class Point3D : public Object
{
public:
    Point3D(double x, double y, double z) : X(x), Y(y), Z(z)
    {
    }

    std::array<double, 3> Get();

private:
    double X;
    double Y;
    double Z;
};


#endif //COMPUTER_GRAPHICS_POINT_H
