//
// Created by maples on 4/21/17.
//
#include <GLUT/glut.h>
#include "Brush.h"

void Brush::display()
{
    Bresenham(0, 0, 400, 300);
}

void Brush::Bresenham(GLint xStart, GLint yStart, GLint xEnd, GLint yEnd)
{
    if (xStart >= xEnd)
    {
        std::swap(xStart, xEnd);
        std::swap(yStart, yEnd);
    }

    GLint dx = xEnd - xStart;
    GLint dy = yEnd - yStart;
    GLint p = 2 * dy - dx;

    GLint x = xStart;
    GLint y = yStart;
    SetPixel(x, y);

    while (x < xEnd)
    {
        x += 1;
        if (p < 0)
        {
            p += (2 * dy);
        }
        else
        {
            p += (2 * (dy - dx));
            y += 1;
            SetPixel(x, y);
        }
    }
}

