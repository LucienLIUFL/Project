//
// Created by maples on 4/19/17.
//

#include "Point.h"

std::array<double, 2> Point2D::Get()
{
    std::array<double, 2> point;
    point[0] = this->X;
    point[1] = this->Y;
    return point;
}

std::array<double, 3> Point3D::Get()
{
    std::array<double, 3> point;
    point[0] = this->X;
    point[1] = this->Y;
    point[2] = this->Z;
    return point;
}