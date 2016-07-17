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

void GraphicsLib::drawCycle(int n, double extend) {
    double angle = (3.1415926 * 2 / n);
    double x = 50, y = 50;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x, y);
    for (int i = 0; i < n; ++i) {
        std::cout << (i * angle) << std::endl;
        x += (extend * sin(i * angle));
        y += (extend * cos(i * angle));
        std::cout << sin(i * angle) << " " << std::ends;
        std::cout << cos(i * angle) << std::endl;
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
