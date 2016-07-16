#include "GraphicsLib.h"

#include <cmath>
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void GraphicsLib::drawStar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINE_LOOP);
        glVertex2i(50, 100);
        glVertex2i(150, 100);
        glVertex2i(70, 40);
        glVertex2i(100, 140);
        glVertex2i(130, 40);
    glEnd();
    glFlush();
}

void GraphicsLib::generatePoints(int n, double extend) {
    double angle = (360.0 / n);
    double x = 100, y = 100;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x, y);
    for (int i = 0; i < 2; ++i) {
        std::cout << (i * angle) << std::endl;
        x += (extend * sin(i * angle));
        y += (extend * cos(i * angle));
        std::cout << x << " " << std::ends;
        std::cout << y << std::endl;
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
